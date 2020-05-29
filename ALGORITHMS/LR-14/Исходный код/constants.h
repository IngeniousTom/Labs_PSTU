#ifndef LR_14_CONSTANTS_H
#define LR_14_CONSTANTS_H

/**
 * Файл с глобальными константами и переменными
 */


/**
 * Перечисление с пунктами меню
 */
enum MenuAction {
    MENU_CREATE = 1,
    MENU_OPEN = 2,
    MENU_PRINT = 3,
    MENU_EDIT = 4,
    MENU_ADD = 5,
    MENU_DELETE = 6,
    MENU_UNDO_LAST_DELETE = 7,
    MENU_SAVE = 8,
    MENU_SEARCH_BY_AUTHOR = 9,
    MENU_SEARCH_BY_PERIOD = 10,
    MENU_EXIT = 11
};

/**
 * Перечисление с местом проведения операции ("С начала", "С конца/в конец", "С позиции")
 */
enum DoFrom {
    DO_FROM_BEGIN = 1,
    DO_FROM_END = 2,
    DO_FROM_POS = 3
};

/**
 * Перечисление со способом проведения операции ("По ключу", "По номеру/позици")
 */
enum DoBy {
    DO_BY_KEY = 1,
    DO_BY_POS = 2
};

/**
 * Перечисление с номерами полями печатного издания
 */
enum LiterFields {
    FIELD_AUTHOR = 1,
    FIELD_TITLE = 2,
    FIELD_PUB_YEAR = 3,
    FIELD_PUBLISHER = 4
};

/**
 * Состоянии базы данных относительно кол-ва записей
 */
enum EntriesState {
    EMPTY = 1,      //пусто
    FULL = 2,       //полность заполнено
    HAS_ENTRIES = 3 //имеются некоторые записи
};

#define MIN_ENTRIES_NUMBER 1            //Минимальное кол-во записей в БД
#define MAX_ENTRIES_NUMBER 100          //Максимальное кол-во записей в БД
#define MIN_INT numeric_limits<int>::min()  //Минимальное значение INTEGER
#define MAX_INT numeric_limits<int>::max()  //Максимальное значение INTEGER

#endif //LR_14_CONSTANTS_H
