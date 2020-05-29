#include "Dialog.h"

using namespace std;


/**
 * Конструктор
 */
Dialog::Dialog() {
    //Приведения класса в рабочее состояние
    EndState = false;
    //Формирование сообщений для пунктов меню
    menuItems.emplace_back("\n%d - Создать новую базу данных!");
    menuItems.emplace_back("\n%d - Открыть базу данных!");
    menuItems.emplace_back("\n%d - Вывести все записи в базе данных!");
    menuItems.emplace_back("\n%d - Отредактировать запись!");
    menuItems.emplace_back("\n%d - Добавить новую запись в базу данных!");
    menuItems.emplace_back("\n%d - Удалить запись из базы данных!");
    menuItems.emplace_back("\n%d - Отменить последнее удаление записи!");
    menuItems.emplace_back("\n%d - Сохранить изменения в базу данных!");
    menuItems.emplace_back("\n%d - Вывести список произведений конкретного автора!");
    menuItems.emplace_back("\n%d - Вывести список произведений, изданных за указанный период!");
    menuItems.emplace_back("\n%d - Выход!");
}

/**
 * Деструктор
 */
Dialog::~Dialog() = default;

/**
 * Метод формирует актуальное меню, пердлагая доступные варианты в зависимости от состояния системы,
 * которое получает от менеджера БД.
 * Возвращает значения типа MenuSet где хранится сформированное сообщение для пользователя
 * о доступных вариантах ввода и соотвествующие коды доступных действий.
 * @return MenuSet
 */
MenuSet Dialog::getMenuSet() {
    MenuSet result = MenuSet();  //Набор пунктов меню
    DBState dbState = manager.getDBState(); //Информация о состоянии СУБД

    string actionSetMsg = "\nВыберите действие!";

    actionSetMsg.append(string_format(menuItems[MENU_CREATE - 1], MENU_CREATE));
    result.codes.push_back(MENU_CREATE);

    actionSetMsg.append(string_format(menuItems[MENU_OPEN - 1], MENU_OPEN));
    result.codes.push_back(MENU_OPEN);

    if (dbState.connected) {
        actionSetMsg.append(string_format(menuItems[MENU_PRINT - 1], MENU_PRINT));
        result.codes.push_back(MENU_PRINT);

        if (dbState.entriesState != EMPTY) {
            actionSetMsg.append(string_format(menuItems[MENU_EDIT - 1], MENU_EDIT));
            result.codes.push_back(MENU_EDIT);
        }

        if (dbState.entriesState != FULL) {
            actionSetMsg.append(string_format(menuItems[MENU_ADD - 1], MENU_ADD));
            result.codes.push_back(MENU_ADD);
        }

        if (dbState.entriesState != EMPTY) {
            actionSetMsg.append(string_format(menuItems[MENU_DELETE - 1], MENU_DELETE));
            result.codes.push_back(MENU_DELETE);
        }

        if (dbState.entriesState != EMPTY && dbState.canUndoDelete) {
            actionSetMsg.append(string_format(menuItems[MENU_UNDO_LAST_DELETE - 1], MENU_UNDO_LAST_DELETE));
            result.codes.push_back(MENU_UNDO_LAST_DELETE);
        }

        if (dbState.hasChanges) {
            actionSetMsg.append(string_format(menuItems[MENU_SAVE - 1], MENU_SAVE));
            result.codes.push_back(MENU_SAVE);
        }

        if (dbState.entriesState != EMPTY) {
            actionSetMsg.append(string_format(menuItems[MENU_SEARCH_BY_AUTHOR - 1], MENU_SEARCH_BY_AUTHOR));
            result.codes.push_back(MENU_SEARCH_BY_AUTHOR);

            actionSetMsg.append(string_format(menuItems[MENU_SEARCH_BY_PERIOD - 1], MENU_SEARCH_BY_PERIOD));
            result.codes.push_back(MENU_SEARCH_BY_PERIOD);
        }
    }
    actionSetMsg.append(string_format(menuItems[MENU_EXIT - 1], MENU_EXIT));
    result.codes.push_back(MENU_EXIT);
    actionSetMsg.append("\n");

    result.msg = actionSetMsg;

    return result;
}

/**
 * Метод выводит на экран пользователю доступные пункты меню
 * и принимает от него выбранный вариант, на основе которого формирует
 * событие, которое далее уже будет обработано данной системой в основном цикле обработке.
 * @param event
 */
void Dialog::getEvent(TEvent &event) {
    try {
        const char *noOrUnavailable = "Такого действия нет в системе или оно не доступно в данный момент!";
        MenuSet menuSet = getMenuSet(); //Набор доступных кодов пунктов меню и соотвествующий текст
        int action;

        //МЕНЮ
        activateEvent(event);  //Активация события
        action = getInt(menuSet.msg, menuSet.codes, noOrUnavailable);  //Получение выбора пользователя
        auto menuAction = MenuAction(action);
        event.command = menuAction;
    } catch (exception& e) {
        cout << "Возникла ошибка!" << endl;
        cout << e.what() << endl;
        clearEvent(event);  //Деактивация события
    }
}

/**
 * Метод запускает и поддержитвает основной цикл обработки
 * и функционированния данной системы.
 * Обработка прекращается когда система будет переведена
 * в нерабочее состояние, например, по выбору полтзователя,
 * когда он выбрал пункт выхода из меню.
 * @return
 */
int Dialog::execute() {
    TEvent event;
    do {
        startExec();
        getEvent(event);    //получить событие
        handleEvent(event); //обработать событие
    } while (valid());
    return EndState;
}

/**
 * Метод проверяет, находится ли система в рабочем состоянии
 * @return
 */
bool Dialog::valid() const { return !EndState; }

/**
 * Метод переводит событие в рабочеее состояние, т.е. в состояние,
 * в котором оно может быть обработано другими объектами
 * @param event
 */
void Dialog::activateEvent(TEvent &event) const {
    event.what = EV_MESSAGE;
}

/**
 * Метод "очищает" событие, т.е. переводит его в состояние,
 * когда его никто не может прочитать, т.н. состояние "Не для чтения/Пропустить"
 * @param event
 */
void Dialog::clearEvent(TEvent &event) {
    event.what = EV_NOTHING; //пустое событие
}

/**
 * Метод переводит систему в рабочее состояние
 */
void Dialog::startExec() { EndState = false; }

/**
 * Метод переводит систему в нерабочее состояние
 */
void Dialog::endExec() {
    EndState = true;
}

/**
 * Метод обрабатывает события.
 * Если событие находится в состоянии для чтения,
 * то считывается код его команды и выполняется соотвествующее
 * действие менеджером БД, после чего событие приводится
 * в состояние "Не для чтения/Пропустить"
 * @param event
 */
void Dialog::handleEvent(TEvent &event) {
    try {
        if (event.what == EV_MESSAGE) {
            switch (event.command) {
                case MENU_CREATE: {
                    manager.createDB();
                    break;
                }
                case MENU_OPEN: {
                    manager.openDB();
                    break;
                }
                case MENU_PRINT: {
                    manager.printDB();
                    break;
                }
                case MENU_EDIT: {
                    manager.editEntry();
                    break;
                }
                case MENU_ADD: {
                    manager.addNewEntry();
                    break;
                }
                case MENU_DELETE: {
                    manager.deleteEntry();
                    break;
                }
                case MENU_UNDO_LAST_DELETE: {
                    manager.undoLastDelete();
                    break;
                }
                case MENU_SAVE: {
                    manager.saveEntriesToDB();
                    break;
                }
                case MENU_SEARCH_BY_AUTHOR: {
                    manager.searchByAuthor();
                    break;
                }
                case MENU_SEARCH_BY_PERIOD: {
                    manager.searchByPeriod();
                    break;
                }
                case MENU_EXIT: {
                    manager.saveCheck();
                    endExec(); //выход
                    break;
                }
            }
            clearEvent(event);
        }
    } catch (exception& e) {
        cout << e.what() << endl;
        clearEvent(event);
    }
}

