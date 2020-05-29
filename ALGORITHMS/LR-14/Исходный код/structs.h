#ifndef LR_14_STRUCTS_H
#define LR_14_STRUCTS_H

#include <cstring>
#include <string>
#include <vector>
#include <list>
#include "constants.h"

#define AUTHOR_MAX_LENGTH 60
#define TITLE_PUB_MAX_LENGTH 100

using namespace std;

//Сокр. СУБД - Система управления базой данных
//Сокр. БД - база данных

/**
 * Структура "Ключ печатного издания"
 * Является составным ключом из полей "Автор" и "Название"
 */
struct Key {
    char author[AUTHOR_MAX_LENGTH]{};        //Автор
    char title[TITLE_PUB_MAX_LENGTH]{};      //Название

    //Метод проверки, является ли ключ условно пустым
    bool empty() const {
        return strncmp(author, "", AUTHOR_MAX_LENGTH) == 0
               && strncmp(title, "", TITLE_PUB_MAX_LENGTH) == 0;
    }
};

/**
 * Структура "Печатное издание"
 */
struct Literature {
    char author[AUTHOR_MAX_LENGTH]{};        //Автор
    char title[TITLE_PUB_MAX_LENGTH]{};      //Название
    int pubYear{};                           //Год издания
    char publisher[TITLE_PUB_MAX_LENGTH]{};  //Издательство
    bool deleted = false;                    //Помечено на удаление

    //Метод проверки, является ли печатное издание условно пустым
    bool empty() const {
        return strncmp(author, "", AUTHOR_MAX_LENGTH) == 0
               && strncmp(title, "", TITLE_PUB_MAX_LENGTH) == 0
               && pubYear == 0
               && strncmp(publisher, "", TITLE_PUB_MAX_LENGTH) == 0;
    }

    //Перегруженный оператор проверки печатных изданий на равенство
    bool operator==(const Literature &lit) const {
        return strncmp(author, lit.author, AUTHOR_MAX_LENGTH) == 0 &&
               strncmp(title, lit.title, TITLE_PUB_MAX_LENGTH) == 0 &&
               pubYear == lit.pubYear &&
               strncmp(publisher, lit.publisher, TITLE_PUB_MAX_LENGTH) == 0;
    }

    //Перегруженный оператор проверки печатных изданий на неравенство
    bool operator!=(const Literature &lit) const {
        return !(lit == *this);
    }

    //Перегруженный оператор проверки печатного издания и ключа на равенство по ключевым полям
    bool operator==(const Key &key) const {
        return strncmp(author, key.author, AUTHOR_MAX_LENGTH) == 0 &&
               strncmp(title, key.title, TITLE_PUB_MAX_LENGTH) == 0;
    }

    //Перегруженный оператор проверки печатного издания и ключа на неравенство по ключевым полям
    bool operator!=(const Key &key) const {
        return !(*this == key);
    }

    /*Перегруженный оператор присваивания.
    Учитывает случай самоприсваивания.*/
    Literature &operator=(const Literature &lit) {
        if (*this == lit) return *this;
        strncpy(this->author, lit.author, AUTHOR_MAX_LENGTH);
        strncpy(this->title, lit.title, TITLE_PUB_MAX_LENGTH);
        this->pubYear = lit.pubYear;
        strncpy(this->publisher, lit.publisher, TITLE_PUB_MAX_LENGTH);
        this->deleted = lit.deleted;
        return *this;
    }
};

/**
 * Структура "Набор меню"
 * Содержит текстовое представление доступных пунктов меню
 * и коды соответсвующих операций
 */
struct MenuSet {
    string msg;         //текстовое представление доступных пунктов меню
    vector<int> codes;  //коды операций доступных пунктов меню
};

/**
 * Структура "Состояние СУБД"
 * Используется для построения актуального
 * списка адаптивного меню
 */
struct DBState {
    bool connected;     //файл с базой данных открыт, соедниение установлено
    bool hasChanges{};  //С момента последнего сохранения были измненения
    bool canUndoDelete; //Есть полсденее удаление элемента, которое можно отменить
    EntriesState entriesState;  //Состоянии базы данных относительно кол-ва записей

    //Кнструктор без параметров
    DBState() {
        connected = false;
        hasChanges = false;
        canUndoDelete = false;
        entriesState = EMPTY;
    }

    //Конструктор с параметрами
    DBState(bool connected, bool hasChanges, bool canUndoDelete, EntriesState entriesState) : connected(connected), hasChanges(hasChanges), canUndoDelete(canUndoDelete), entriesState(entriesState) {}
};

/**
 * Структура ДТО для передачи в качестве аргумента в методы и функции,
 * где требуется выполнить процедуру по позиции/номеру либо по ключу
 */
struct DoByDTO {
    Key key;   //Ключ
    int pos{}; //Позиция/номер элемента
};


typedef Literature Liter;               //Псевдоним для спечатного издания
typedef list<Liter> LitList;            //Псевдоним для списка печатных изданий
typedef LitList::iterator LitList_it;   //Псевдоним для итератора списка печатных изданий

#endif //LR_14_STRUCTS_H
