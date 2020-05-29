#ifndef LR_14_IOSYSTEM_H
#define LR_14_IOSYSTEM_H

#include "../myUtilities.h"
#include "../structs.h"

using namespace std;

/**
 * Класс "Подсистема ввода-вывода СУБД"
 */
class IOSystem {
public:
    IOSystem();           //Конструктор
    virtual ~IOSystem();  //Деструктор
    Liter getEntry();                       //Метод получения записи с консоли пользователя (диалог ввода)
    Key getKey(const string &title);        //Метод получения ключа записи с консоли пользователя (диалог ввода)
    Liter getEditedEntry(Liter &entry);     //Метод получения отредактированной записи с консоли пользователя (диалог ввода)
    void printEntries(const LitList &list, const string &title);  //Вывод записей из списка в консоль
    void printEntry(const Liter &entry) const;  //Вывод одной записи в консоль
};


#endif //LR_14_IOSYSTEM_H
