#include "../constants.h"
#include "Manager.h"
#include "../Exceptions/ConnectException.h"

/**
 * Конструктор
 */
Manager::Manager() {
}

/**
 * Деструктор
 */
Manager::~Manager() {
}

/**
 * Метод создания нового списка записей
 * @param numberOfEntries
 * @return
 */
LitList Manager::createNewList(int numberOfEntries) {
    LitList newList;
    Liter newEntry;

    for (int i = 1; i <= numberOfEntries; i++) {
        printf("\nЗапись № %i:\n", i);
        newEntry = ioSystem.getEntry();
        newList.push_back(newEntry);
    }

    return newList;
}

/**
 * Проверка на необходимость сохранения
 */
void Manager::saveCheck() {
    if (!dbcs.isConnected() || !dbProcessor.hasUnsavedEntries()) return;

    string contOpt = "yY";
    string cont = getString("Несохраненные изменения могут быть утеряны!\nСохранить сведения в базу данных? (y/n)\n");

    if (contOpt.find(cont[0]) != string::npos) {
        saveEntriesToDB();
    }
}

/**
 * Метод сохранения записей из оперативной памяти в БД
 */
void Manager::saveEntriesToDB() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }
    dbProcessor.deleteIfNeeded();
    dbProcessor.saveData(dbcs);
    cout << "Данные успешно сохранены в базу данных!" << endl;
}

/**
 * Метод создания новой базы данных (БД)
 * @return
 */
bool Manager::createDB() {
    saveCheck();

    string fileName = getString("Введите имя файла в котором хотите создать базу данных!");
    int numberOfEntries = getInt(string_format("Введите кол-во записей, из которых хотите создать базу данных! (Минимум %d)", MIN_ENTRIES_NUMBER), MIN_ENTRIES_NUMBER, MAX_ENTRIES_NUMBER);
    LitList newList = createNewList(numberOfEntries);

    dbcs.initializeConnection(fileName, true);
    dbProcessor.initializeWithNewData(newList);
    dbProcessor.saveData(dbcs);

    cout << "База данных была успешно создана в файле под названием " << dbcs.getFileNameWithExt() << endl;
}

/**
 * Метод открытия существующей БД из файла
 * @return
 */
bool Manager::openDB() {
    saveCheck();

    string fileName = getString("Введите имя файла, в котором хранится база данных!");

    dbcs.initializeConnection(fileName, false);
    dbProcessor.initializeWithNewData(dbcs);

    cout << "База данных успешно открыта из файла " << dbcs.getFileNameWithExt() << endl;
}

/**
 * Метод редактирования записи в БД
 */
void Manager::editEntry() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }

    int st = getInt("Выберите, каким способом хотите получить запись для редактирования:\n1 - По ключу!\n2 - По номеру!", DO_BY_KEY, DO_BY_POS);
    Liter foundEntry;
    Liter editedEntry;

    DoByDTO doByDto = DoByDTO();
    auto doBy = DoBy(st);

    switch (doBy) {
        case DO_BY_KEY: {
            Key key =ioSystem.getKey("Введите ключ!");
            foundEntry = dbProcessor.getEntryByKey(key);
            doByDto.key = key;
            break;
        }
        case DO_BY_POS: {
            int pos = getInt(string_format("Введите номер позиции! (От %d до %d)", 1, dbProcessor.getAvailableSize()), 1, dbProcessor.getAvailableSize());
            foundEntry = dbProcessor.getEntryByPos(pos);
            doByDto.pos = pos;
            break;
        }
    }

    if (!foundEntry.empty()) {
        editedEntry = ioSystem.getEditedEntry(foundEntry);
        dbProcessor.editEntry(editedEntry, doBy, doByDto);
        cout << "Запись успешно отредактирована!" << endl;
    } else {
        cout << "Запись не была найдена!" << endl;
    }
}

/**
 * Метод удаления записи из БД
 */
void Manager::deleteEntry() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }

    int st = getInt("Выберите, каким способом хотите указать запись для удаления:\n1 - По ключу!\n2 - По номеру!", 1, 2);
    bool found = false;
    DoByDTO doByDto;
    auto doBy = DoBy(st);

    switch (doBy) {
        case DO_BY_KEY: {
            Key key = ioSystem.getKey("Введите ключ!");
            found = dbProcessor.foundByKey(key);
            doByDto.key = key;
            break;
        }
        case DO_BY_POS: {
            int pos = getInt(string_format("Введите номер позиции! (От %d до %d)", 1, dbProcessor.getAvailableSize()), 1, dbProcessor.getAvailableSize());
            found = dbProcessor.foundByPos(pos);
            doByDto.pos = pos;
            break;
        }
    }

    if (found) {
        dbProcessor.deleteEntry(doBy, doByDto);
        cout << "Запись успешно удалена!" << endl;
    } else {
        cout << "Запись не была найдена!" << endl;
    }
}

/**
 * Метод добавления новой записи в БД
 */
void Manager::addNewEntry() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }

    LitList_it it;
    int pos = 0;

    int opt = getInt("Выберите, куда нужно вставить новую запись:\n1 - В начало!\n2 - В конец!\n3 - На конкретную позицию!", DO_FROM_BEGIN, DO_FROM_POS);

    auto doFrom = DoFrom(opt);

    switch (doFrom) {
        case DO_FROM_BEGIN:
        case DO_FROM_END:
            break;
        case DO_FROM_POS:
            pos = getInt(string_format("Введите номер позиции, на которую вы хотите вставить новую запись! (От %d до %d)", 1, dbProcessor.getAvailableSize() + 1), 1, dbProcessor.getAvailableSize() + 1);
            break;
    }

    Liter newEntry = ioSystem.getEntry();
    dbProcessor.addEntry(newEntry, doFrom, pos);

    cout << "Запись успешно добавлена в базу данных!" << endl;
}

/**
 * Метод печати записей БД
 */
void Manager::printDB() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }
    dbProcessor.printEntries(ioSystem, "Содержимое базы данных:");
}

/**
 * Метод отмены удаления последней удаленной записи
 */
void Manager::undoLastDelete() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }
    dbProcessor.undoLastDelete();
    cout << "Последняя удаленная запись была успешно восстановлена!" << endl;
}

/**
 * Метод поиска записей по автору
 */
void Manager::searchByAuthor() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }

    string author = getString("Введите имя автора, чьи произведения хотите найти!");

    LitList result = dbProcessor.searchByAuthor(author);

    if (!result.empty()) {
        ioSystem.printEntries(result, "Список произведений указанного автора:");
    } else {
        cout << "По указанному автору не найдено ни одного произведения!" << endl;
    }
}

/**
 * Метод поиска записей по периоду
 */
void Manager::searchByPeriod() {
    if (!dbcs.isConnected()) {
        throw ConnectException();
    }

    cout << "Введите период, чтобы найти все произведения, чей год издания попадает в него!" << endl;
    int first = getInt("От (включительно):", MIN_INT, MAX_INT);
    int last = getInt("До (включительно):", MIN_INT, MAX_INT);

    LitList result = dbProcessor.searchByPeriod(first, last);

    if (!result.empty()) {
        ioSystem.printEntries(result, "Список произведений за указанный период:");
    } else {
        cout << "За указанный период не найдено ни одного произведения!" << endl;
    }
}

/**
 * Метод получения объекта с информацией о сотоянии СУБД
 * @return
 */
DBState Manager::getDBState() {
    DBState dbState;

    dbcs.fillEntriesState(dbState);
    dbProcessor.fillEntriesState(dbState);

    return dbState;
}
