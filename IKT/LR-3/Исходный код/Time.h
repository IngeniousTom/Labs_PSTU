#ifndef LR_3_TIME_H
#define LR_3_TIME_H

#include <iostream>

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

/**
 * Класс "Временной интервал"
 */
class Time {
    int min, sec;       //Минуты и секунды
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

    //Перегуженные операторы
    Time &operator=(const Time &);  //Присваивание
    Time &operator++();             //Инкремент
    Time operator++(int);           //Пост-инкремент
    Time operator+(int);            //Перегруженный оператор для добавления секунд
    bool operator==(const Time &);  //Проверка на равенство
    bool operator!=(const Time &);  //Проверка на неравенство

    //Глобальные фукции ввода вывода
    friend istream &operator>>(istream &in, Time &time);        //Ввод с консоли
    friend ostream &operator<<(ostream &out, const Time &time); //Вывод в консоль
};


#endif //LR_3_TIME_H
