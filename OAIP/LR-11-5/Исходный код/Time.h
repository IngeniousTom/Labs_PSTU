#ifndef LR_11_2_TIME_H
#define LR_11_2_TIME_H

#include <iostream>
#include "myUtilities.h"

using namespace std;


/**
 * Класс "Временной интервал"
 */
class Time {
    int min, sec;  //Минуты и секунды
public:
    //Конструкторы
    Time() {
        min = 0;
        sec = 0;
    }
    Time(int min, int sec) {
        this->min = min;
        this->sec = sec;
    }
    Time(const Time &time) {
        min = time.min;
        sec = time.sec;
    }

    //Деструктор
    ~Time() {}

    //Селекторы
    int getMin() {
        return min;
    }
    int getSec() {
        return sec;
    }

    //Модификаторы
    void setMin(int min) {
        this->min = min;
    }
    void setSec(int sec) {
        this->sec = sec;
    }

    //Перегуженные операции
    Time &operator=(const Time &);
    Time &operator+=(const Time &t);
    Time operator+(const Time &);
    Time operator-(const Time &);
    Time operator*(const Time &t);
    Time operator/(const Time &t);
    Time operator/(const int &n);
    Time &operator++();
    Time operator++(int);
    Time &operator--();
    Time operator--(int);
    bool operator==(const Time &);
    bool operator!=(const Time &);
    bool operator>(const Time&);
    bool operator<(const Time&);
    bool operator>=(const Time &);
    bool operator<=(const Time &);

    //Глобальные фукции ввода вывода
    friend istream &operator>>(istream &in, Time &time);
    friend ostream &operator<<(ostream &out, const Time &time);
};


#endif //LR_11_2_TIME_H
