#include "DBProcessor.h"
#include "../Exceptions/EntryNotFoundException.h"
#include "../Exceptions/WrongPositionException.h"
#include "../Exceptions/RuntimeException.h"
#include <algorithm>

/**
 * Предикат для определения, что запись не была помечена на удаление
 * @param entry
 * @return
 */
bool notDeleted(const Liter &entry) {
    return !entry.deleted;
}

/**
 * Предикат для определения что год публикации первого печатного издания меньше, чем второго
 * @param entry1
 * @param entry2
 * @return
 */
bool lessPubYear(const Liter & entry1, const Liter & entry2) {
    return entry1.pubYear < entry2.pubYear;
}

/**
 * Констркуктор без параметров
 */
DBProcessor::DBProcessor() = default;

/**
 * Деструктор
 */
DBProcessor::~DBProcessor() = default;

/**
 * етод проверки, можно ли отменить последнее "удаление" записи
 * @return
 */
bool DBProcessor::canUndoDelete() {
    return !(listEntries.empty() || lastDeleted == nullptr || !lastDeleted->deleted);
}

/**
 * Метод проверки, имеются ли несохраненные записи
 * @return
 */
bool DBProcessor::hasUnsavedEntries() {
    return hasChanges;
}

/**
 * Метод получения доступного размера(кол-ва) под новые записи в БД
 * @return
 */
unsigned int DBProcessor::getAvailableSize() {
    return listEntries.size() - numberOfDeleted;
}

/**
 * Метод очистки списка записей
 */
void DBProcessor::clearList() {
    listEntries.clear();
    delete lastDeleted;
    numberOfDeleted = 0;
}

/**
 * Метод удаления записей безвозвратно
 */
void DBProcessor::deleteEntries() {
    LitList deleteList;

    copy_if(listEntries.begin(), listEntries.end(), back_inserter(deleteList), notDeleted);
    listEntries.clear();
    copy(deleteList.begin(), deleteList.end(), back_inserter(listEntries));

    numberOfDeleted = 0;
    delete lastDeleted;
}

/**
 * Метод проверки необходимости безвозвратно удалить записи, что помечены на удаление
 */
void DBProcessor::deleteIfNeeded() {
    if (numberOfDeleted > listEntries.size() / 2) {
        deleteEntries();
    }
}

/**
 * Метод сохранение данных в файл БД с помощью файловой подсистемы
 * @param dbcs
 */
void DBProcessor::saveData(DBConnectSystem &dbcs) {
    dbcs.writeToFile(listEntries);
    dbcs.readFromFile(listEntries);
    hasChanges = false;
}

/**
 * Метод инициализации списка записей другим списком
 * @param newList
 */
void DBProcessor::initializeWithNewData(const LitList &newList) {
    clearList();
    listEntries = newList;
    hasChanges = false;
}

/**
 * Метод инициализации списка записей из файловой подсистемы
 * @param dbcs
 */
void DBProcessor::initializeWithNewData(DBConnectSystem & dbcs) {
    clearList();
    dbcs.readFromFile(listEntries);
    hasChanges = false;
}

/**
 * Метод поиска записи по позиции
 * @param pos
 * @return
 */
LitList_it DBProcessor::findEntryByPos(const int pos) {
    if (pos < 1 || pos > listEntries.size()) {
        return listEntries.end();
    }

    int i = 1;

    LitList_it it = listEntries.begin();

    while (it != listEntries.end()) {
        if (!(*it).deleted) {
            if (i == pos) {
                break;
            }
            i++;
        }
        it++;
    }

    return it;
}

/**
 * Метод получения записи по позиции
 * @param pos
 * @return
 */
Liter DBProcessor::getEntryByPos(const int pos) {
    Liter result;

    LitList_it it = findEntryByPos(pos);
    if (it != listEntries.end()) {
        result = *it;
    }

    return result;
}

/**
 * етод нахождения записи по ключу
 * @param key
 * @return
 */
LitList_it DBProcessor::findEntryByKey(const Key &key) {
    if (key.empty()) {
        return listEntries.end();
    }

    LitList_it it = listEntries.begin();

    while (it != listEntries.end()) {
        if (*it == key && !(*it).deleted) {
            break;
        }
        it++;
    }

    return it;
}

/**
 * Метод получения записи по ключу
 * @param key
 * @return
 */
Liter DBProcessor::getEntryByKey(const Key &key) {
    Liter result;

    LitList_it it = findEntryByKey(key);
    if (it != listEntries.end()) {
        result = *it;
    }

    return result;
}

/**
 * Метод проверки, можно ли найти запись по ключу
 * @param key
 * @return
 */
bool DBProcessor::foundByKey(const Key &key) {
    return !(findEntryByKey(key) == listEntries.end());
}

/**
 * Метод проверки, можно ли найти запись по позиции
 * @param pos
 * @return
 */
bool DBProcessor::foundByPos(const int pos) {
    return !(findEntryByPos(pos) == listEntries.end());
}

/**
 * Метод редактирования записи
 * @param newEntry
 * @param doBy
 * @param doByDto
 */
void DBProcessor::editEntry(Liter &newEntry, DoBy doBy, const DoByDTO &doByDto) {
    LitList_it it;

    switch (doBy) {
        case DO_BY_KEY: {
            it = findEntryByKey(doByDto.key);
            break;
        }
        case DO_BY_POS: {
            it = findEntryByPos(doByDto.pos);
            break;
        }
    }

    if (it != listEntries.end()) {
        assignNewEntry(it, newEntry);
        hasChanges = true;
    } else {
        throw EntryNotFoundException();
    }
}

/**
 * Метод удаления записи
 * @param doBy
 * @param doByDto
 */
void DBProcessor::deleteEntry(DoBy doBy, DoByDTO &doByDto) {
    LitList_it it;

    switch (doBy) {
        case DO_BY_KEY: {
            it = findEntryByKey(doByDto.key);
            break;
        }
        case DO_BY_POS: {
            it = findEntryByPos(doByDto.pos);
            break;
        }
    }

    if (it != listEntries.end()) {
        lastDeleted = &*it;
        it->deleted = true;
        numberOfDeleted++;
        hasChanges = true;
    } else {
        throw EntryNotFoundException();
    }
}

/**
 * Метод добавления в список записей новой записи
 * @param newEntry
 * @param doFrom
 * @param pos
 */
void DBProcessor::addEntry(Liter &newEntry, DoFrom doFrom, int pos) {
    LitList_it it;

    switch (doFrom) {
        case DO_FROM_BEGIN: {
            it = listEntries.begin();
            listEntries.insert(it, newEntry);
            break;
        }
        case DO_FROM_END: {
            it = listEntries.end();
            listEntries.insert(it, newEntry);
            break;
        }
        case DO_FROM_POS:
        default:
            if (pos >= 1 && pos <= listEntries.size() + 1) {
                it = findEntryByPos(pos);
                listEntries.insert(it, newEntry);
            } else {
                throw WrongPositionException();
            }
            break;
    }
    hasChanges = true;
}

/**
 * Метод присваивания нового значения записи, на которую указывает передаваемый итератор
 * @param it
 * @param newEntry
 */
void DBProcessor::assignNewEntry(LitList_it it, Liter &newEntry) {
    if (it == listEntries.end()) {
        throw EntryNotFoundException();
    }

    *it = newEntry;
    hasChanges = true;
}

/**
 * Метод отмены последнего "удаления записи"
 */
void DBProcessor::undoLastDelete() {
    if (listEntries.empty()) {
        throw RuntimeException("Список записей пуст! Восстанавливать нечего!");
    }
    if (numberOfDeleted == 0) {
        throw RuntimeException("Удаленных записей нет! Восстанавливать нечего!");
    }
    if (lastDeleted == nullptr || !lastDeleted->deleted) {
        throw RuntimeException("Последняя удаленная запись уже была восстановлена!");
    }
    lastDeleted->deleted = false;
    numberOfDeleted--;
    hasChanges = true;
}

/**
 * Метод выодода списка записей в консоль с помощью подсистемы ввода/вывода СУБД
 * @param ioSystem
 * @param title
 */
void DBProcessor::printEntries(IOSystem &ioSystem, const string &title) {
    ioSystem.printEntries(listEntries, title);
}

/**
 * Метод поиска записи по автору
 * @param author
 * @return
 */
LitList DBProcessor::searchByAuthor(const string &author) {
    LitList result;
    //Поиск записей по автору
    for (Liter entry : listEntries) {
        if (strncmp(entry.author, author.c_str(), AUTHOR_MAX_LENGTH) == 0 && !entry.deleted) {
            result.push_back(entry);
        }
    }
    result.sort(lessPubYear);  //Сортировка записей
    return result;
}

/**
 * Метод поиска записи по периоду издания
 * @param first
 * @param last
 * @return
 */
LitList DBProcessor::searchByPeriod(int first, int last) {
    LitList result;
    //Поиск записей по периоду
    for (Liter entry  : listEntries) {
        if (entry.pubYear >= first && entry.pubYear <= last && !entry.deleted) {
            result.push_back(entry);
        }
    }
    result.sort(lessPubYear); //Сортировка записей
    return result;
}

/**
 * Метод заполнения структуры "Состояние СУБД" соотвествующимим данными о записях в оперативной памяти
 * @param dbState
 */
void DBProcessor::fillEntriesState(DBState &dbState) {
    if (listEntries.empty()) {
        dbState.entriesState = EMPTY;
    } else if (listEntries.size() == MAX_ENTRIES_NUMBER) {
        dbState.entriesState = FULL;
    } else {
        dbState.entriesState = HAS_ENTRIES;
    }
    dbState.canUndoDelete = canUndoDelete();
    dbState.hasChanges = hasChanges;
}
