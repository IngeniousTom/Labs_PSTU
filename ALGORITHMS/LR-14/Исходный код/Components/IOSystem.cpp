#include "IOSystem.h"
#include "../Exceptions/RuntimeException.h"
#include <iostream>

/**
 * Конструктор
 */
IOSystem::IOSystem() = default;

/**
 * Деструктор
 */
IOSystem::~IOSystem() = default;

/**
 * Метод получения записи с консоли пользователя (диалог ввода)
 * @return
 */
Liter IOSystem::getEntry() {
    Liter newEntry{};
    string strValue;

    //ФОРМИРУЕМ ЗАПИСЬ
    strValue = getString("Автор:");
    strncpy(newEntry.author, strValue.c_str(), AUTHOR_MAX_LENGTH);

    strValue = getString("Название:");
    strncpy(newEntry.title, strValue.c_str(), TITLE_PUB_MAX_LENGTH);

    newEntry.pubYear = getInt("Год издания:", MIN_INT, MAX_INT);

    strValue = getString("Издательство:");
    strncpy(newEntry.publisher, strValue.c_str(), TITLE_PUB_MAX_LENGTH);

    return newEntry;
}

/**
 * Метод получения ключа записи с консоли пользователя (диалог ввода)
 * @param title
 * @return
 */
Key IOSystem::getKey(const string &title) {
    Key newKey{};
    string strValue;

    if (!title.empty()) {
        cout << title << endl;
    }
    //ВВОД КЛЮЧА
    strValue = getString("Автор:");
    strncpy(newKey.author, strValue.c_str(), AUTHOR_MAX_LENGTH);

    strValue = getString("Название:");
    strncpy(newKey.title, strValue.c_str(), TITLE_PUB_MAX_LENGTH);

    return newKey;
}

/**
 * Метод получения отредактированной записи с консоли пользователя (диалог ввода)
 * @param entry
 * @return
 */
Liter IOSystem::getEditedEntry(Liter &entry) {
    Liter result;
    int field;
    string strValue;
    int intValue;

    string title =
            "Какое поле нужно поменять?"
            "\n1 - Автор"
            "\n2 - Название"
            "\n3 - Год издания"
            "\n4 - Издательство\n";
    string contOpt = "yY";
    string cont;

    bool done = false;

    cout << "Текущее состояние записи:" << endl;
    printEntry(entry);

    //Далее цикл выбор какое поле отредактировать и продолжить ли редактирование записи
    do {
        field = getInt(title, 1, 4);
        switch (field) {
            case FIELD_AUTHOR: {
                strValue = getString("\nНовое значение для поля \"Автор\":");
                strncpy(entry.author, strValue.c_str(), AUTHOR_MAX_LENGTH);
                break;
            }
            case FIELD_TITLE: {
                strValue = getString("\nНовое значение для поля \"Название\":");
                strncpy(entry.title, strValue.c_str(), TITLE_PUB_MAX_LENGTH);
                break;
            }
            case FIELD_PUB_YEAR: {
                intValue = getInt("\nНовое значение для поля \"Год издания\":", MIN_INT, MAX_INT);
                entry.pubYear = intValue;
                break;
            }
            case FIELD_PUBLISHER: {
                strValue = getString("\nНовое значение для поля \"Издательство\":");
                strncpy(entry.publisher, strValue.c_str(), TITLE_PUB_MAX_LENGTH);
                break;
            }
            default:
                printf("\nТакого поля нет в записи!\n");
                break;
        }
        cout << "\nТекущее состояние записи:" << endl;
        printEntry(entry);
        cont = getString("Продолжить редактировать запись? (y/n)");
        if (contOpt.find(cont[0]) == string::npos) {
            done = true;
        }
    } while (!done);

    result = entry;
    return result;
}

/**
 * Вывод записей из списка в консоль
 * @param list
 * @param title
 */
void IOSystem::printEntries(const LitList &list, const string &title) {
    if (list.empty()) {
        throw RuntimeException("Список пуст, выводить нечего!");
    }

    if (!title.empty()) {
        cout << endl << title << endl;
    }

    int pos = 1;
    for (const Liter &entry : list) {
        if (!entry.deleted) {
            cout << pos << ")" << endl;
            printEntry(entry);
            pos++;
        }
    }
}

/**
 * Вывод одной записи в консоль
 * @param entry
 */
void IOSystem::printEntry(const Liter &entry) const {
    cout << "Автор: " << entry.author << endl;
    cout << "Название: " << entry.title << endl;
    cout << "Год издания: " << entry.pubYear << endl;
    cout << "Издательство: " << entry.publisher << endl;
    cout << endl;
}
