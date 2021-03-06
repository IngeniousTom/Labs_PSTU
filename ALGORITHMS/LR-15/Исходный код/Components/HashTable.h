#ifndef LR_15_HASHTABLE_H
#define LR_15_HASHTABLE_H

#include <list>
#include <string>
#include <cmath>
#include "Data.h"

using namespace std;

/**
 * Класс "Хэш-таблица"
 */
class HashTable {
private:
    static const int baseDegree = 10;               //Степень двойки для генерации размера таблицы
    static const int size = pow(2, baseDegree);  //Размер таблицы
    list<pair<string, Data>> table[size];           //Массив списков пар "ключ-значение", представляющий контейнерную часть хэш таблицы
private:
    int getIntKey(const string &key);               //Метод получения целочисленного ключа из строкового
    int hash(const string &key);                    //Метод - хэш-функция
    int getFilledSize();                            //Метод получения общего количества добавленных в таблицу элементов
public:
    static int getSize();                           //Метод получения размера таблицы
    bool isEmpty();                                 //Метод проверки, является ли таблица пустой
    int getCollisionNum();                          //Метод посчета коллизий
    Data search(const string &key);                 //Метод поиска записи в хэш таблице по ключу
    list<Data> search(int pos);                     //Метод поиска записей в хэш таблице по номеру
    void insert(const Data &value);                 //Метод вставки новой записи в хэш-таблицу
    bool remove(const string &key);                 //Метод удаления записи из хэш-таблицы
    void print();                                   //Метод вывода записей хэш-таблицы в консоль
    void clear();                                   //Метод удаления всех записей их хэш-таблицы
};


#endif //LR_15_HASHTABLE_H
