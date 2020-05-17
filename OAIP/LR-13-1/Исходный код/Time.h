#ifndef LR_13_1_TIME_H
#define LR_13_1_TIME_H

#include <iostream>
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

/**
 * Класс "Временной интервал"
 */
class Time {
    int min, sec;             //Минуты и секунды
public:
    Time() {                  //Конструктор без параметров
        min = 0;
        sec = 0;
    }
    Time(int min, int sec) {  //Конструктор с параметрами
        this->min = min;
        this->sec = sec;
    }
    Time(const Time &time) {  //Конструктор коприрования
        min = time.min;
        sec = time.sec;
    }
    ~Time() {}                //Деструктор

    //Селекторы
    int getMin() {            //Метод получения минут
        return min;
    }

    int getSec() {            //Метод получения секунд
        return sec;
    }

    //Модификаторы
    void setMin(int min) {    //Метод установки минут
        this->min = min;
    }

    void setSec(int sec) {    //Метод установки секунд
        this->sec = sec;
    }

    //Перегуженные операции
    Time &operator=(const Time &t);   //Присваивание
    Time &operator+=(const Time &t);  //Прибавление через присваивание
    Time operator+(const Time &t);    //Перегруженный оператор для сложения времени
    Time operator*(const Time &t);    //Перегруженный оператор для умножения времени
    Time operator/(const Time &t);    //Перегруженный оператор для деления на время
    Time operator/(const int &n);     //Перегруженный оператор деления на секунды
    bool operator>(const Time&);      //Перегруженный оператор сравнения "строго больше"
    bool operator<(const Time&);      //Перегруженный оператор сравнения "строго меньше"
    Time &operator++();               //Инкремент
    Time operator++(int);             //Пост-инкремент
    bool operator==(const Time &);    //Проверка на равенство
    bool operator!=(const Time &);    //Проверка на неравенство

    //Глобальные фукции ввода вывода
    friend istream &operator>>(istream &in, Time &time);        //Ввод с консоли
    friend ostream &operator<<(ostream &out, const Time &time); //Вывод в консоль
};


#endif //LR_13_1_TIME_H
