#ifndef LR_14_MANAGER_H
#define LR_14_MANAGER_H

#include "DBConnectSystem.h"
#include "DBProcessor.h"
#include "IOSystem.h"

using namespace std;

/**
 * Класс "Менеджер СУБД"
 * Является центральным звеном СУБД
 * и управляет остальными его частями.
 * Также, взаимодействует с объектом диалога,
 * рреализуя команды пользователя, делегируя функции
 * подсистемам СУБД
 */
class Manager {
private:
    DBConnectSystem dbcs{};     //Файловая подсистема СУБД
    DBProcessor dbProcessor{};  //Обработчик СУБД
    IOSystem ioSystem;          //Подсистема ввода-вывода СУБД
private:
    LitList createNewList(int numberOfEntries);  //Метод создания нового списка записей
public:
    Manager();              //Конструктор
    virtual ~Manager();     //Деструктор
    bool createDB();        //Метод создания новой базы данных (БД)
    bool openDB();          //Метод открытия существующей БД из файла
    void printDB();         //Метод печати записей БД
    void editEntry();       //Метод редактирования записи в БД
    void addNewEntry();     //Метод добавления новой записи в БД
    void deleteEntry();     //Метод удаления записи из БД
    void undoLastDelete();  //Метод отмены удаления последней удаленной записи
    void saveEntriesToDB(); //Метод сохранения записей из оперативной памяти в БД
    void searchByAuthor();  //Метод поиска записей по автору
    void searchByPeriod();  //Метод поиска записей по периоду
    void saveCheck();       //Проверка на необходимость сохранения
    DBState getDBState();   //Метод получения объекта с информацией о сотоянии СУБД
};


#endif //LR_14_MANAGER_H
