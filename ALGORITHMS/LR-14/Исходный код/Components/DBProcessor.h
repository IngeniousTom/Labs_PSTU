#ifndef LR_14_DBPROCESSOR_H
#define LR_14_DBPROCESSOR_H

#include "../structs.h"
#include "DBConnectSystem.h"
#include "IOSystem.h"

using namespace std;

/**
 * Класс "Обработчик СУБД"
 * Выполняет операции с записями в оперативной памяти.
 */
class DBProcessor {
private:
    LitList listEntries;   //список записей
    Liter *lastDeleted = nullptr;  //указатель на последнюю запись, помеченную на удаление
    unsigned int numberOfDeleted = 0;  //Кол-во удаленных файл за текущую сессию с момента последнего сохранения
    bool hasChanges = false; //Изменились ли данные после загрузки
private:
    void clearList();       //Метод очистки списка записей
    void deleteEntries();   //Метод удаления записей безвозвратно
public:
    DBProcessor();    //Конструктор

    virtual ~DBProcessor();  //Деструктор

    void deleteIfNeeded();  //Метод проверки необходимости безвозвратно удалить записи, что помечены на удаление

    void saveData(DBConnectSystem &dbcs);   //Метод сохранение данных в файл БД с помощью файловой подсистемы

    void initializeWithNewData(const LitList &newList);     //Метод инициализации списка записей другим списком

    void initializeWithNewData(DBConnectSystem &dbcs);      //Метод инициализации списка записей из файловой подсистемы

    LitList_it findEntryByPos(int pos);         //Метод поиска записи по позиции

    Liter getEntryByPos(int pos);               //Метод получения записи по позиции

    LitList_it findEntryByKey(const Key &key);  //Метод нахождения записи по ключу

    Liter getEntryByKey(const Key &key);        //Метод получения записи по ключу

    void assignNewEntry(LitList_it it, Liter &newEntry);    //Метод присваивания нового значения записи, на которую указывает передаваемый итератор

    unsigned int getAvailableSize();        //Метод получения доступного размера под новые записи в БД

    bool foundByKey(const Key &key);        //Метод проверки, можно ли найти запись по ключу

    bool foundByPos(int pos);               //Метод проверки, можно ли найти запись по позиции

    LitList searchByAuthor(const string &author);  //Метод поиска записи по автору

    LitList searchByPeriod(int first, int last);   //Метод поиска записи по периоду издания

    void printEntries(IOSystem &ioSystem, const string &title);     //Метод выодода списка записей в консоль с помощью подсистемы ввода/вывода СУБД

    bool canUndoDelete();       //Метод проверки, можно ли отменить последнее "удаление" записи

    void undoLastDelete();      //Метод отмены последнего "удаления записи"

    void addEntry(Liter &newEntry, DoFrom doFrom, int pos);  //Метод добавления в список записей новой записи

    void editEntry(Liter &newEntry, DoBy doBy, const DoByDTO &doByDto);  //Метод редактирования записи

    void deleteEntry(DoBy doBy, DoByDTO &doByDto);      //Метод удаления записи

    void fillEntriesState(DBState &dbState);        //Метод заполнения структуры "Состояние СУБД" соотвествующимим данными о записях в оперативной памяти

    bool hasUnsavedEntries();       //Метод проверки, имеются ли несохраненные записи
};


#endif //LR_14_DBPROCESSOR_H
