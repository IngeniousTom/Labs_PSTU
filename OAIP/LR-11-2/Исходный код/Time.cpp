#include "Time.h"

/**
 * Перегруженный оператор присваивания.
 * Учитывает самоприсваивание.
 * @param t
 * @return
 */
Time &Time::operator=(const Time &t) {
    if (&t == this) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}

/**
 * Перегруженный оператор сложения.
 * Складывает временные интервалы.
 * @param k
 * @return
 */
Time Time::operator+(const Time &t) {
    int tt = min * 60 + sec;
    int kt = t.min * 60 + t.sec;
    tt += kt;
    Time temp(tt / 60, tt % 60);
    return temp;
}

/**
 * Перегруженный оператор вычитания.
 * Производит вычитание временных интервалов.
 * @param k
 * @return
 */
Time Time::operator-(const Time &t) {
    int tt = min * 60 + sec;
    int kt = t.min * 60 + t.sec;
    tt -= kt;
    Time temp(tt / 60, tt % 60);
    return temp;
}

/**
 * Перегруженный оператор для инкремента времени
 * @return
 */
Time &Time::operator++() {
    int temp = min * 60 + sec;
    temp++;
    min = temp / 60;
    sec = temp % 60;
    return *this;
}

/**
 * Перегруженный оператор для пост-инкремента времени
 * @return
 */
Time Time::operator++(int) {
    int temp = min * 60 + sec;
    temp++;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
}

/**
 * Перегруженный оператор для декремента времени
 * @return
 */
Time &Time::operator--() {
    int temp = min * 60 + sec;
    temp--;
    min = temp / 60;
    sec = temp % 60;
    return *this;
}

/**
 * Перегруженный оператор для пост-декремента времени
 * @return
 */
Time Time::operator--(int) {
    int temp = min * 60 + sec;
    temp--;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
}

/**
 * Перегруженный оператор присваивания со сложением.
 * Добавляет временной интервал к текущему.
 * @param t
 * @return
 */
Time &Time::operator+=(const Time &t) {
    int tt = min * 60 + sec;
    int kt = t.min * 60 + t.sec;
    tt += kt;
    this->min = tt / 60;
    this->sec = tt % 60;
    return *this;
}

/**
 * Перегруженный оператор умножения.
 * Умножает врмеменные интервалы.
 * @param t
 * @return
 */
Time Time::operator*(const Time &t) {
    int tt = min * 60 + sec;
    int kt = t.min * 60 + t.sec;
    tt *= kt;
    Time temp(tt / 60, tt % 60);
    return temp;
}

/**
 * Перегруженный оператор деления.
 * Делит врмеменные интервалы друг на друга.
 * @param t
 * @return
 */
Time Time::operator/(const Time &t) {
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 / temp2) / 60;
    p.sec = (temp1 / temp2) % 60;
    return p;
}

/**
 * Перегруженный оператор деления.
 * Делит временной интервал на целое число.
 * @param t
 * @return
 */
Time Time::operator/(const int &t) {
    int temp = min * 60 + sec;
    Time p;
    p.min = (temp / t) / 60;
    p.sec = (temp / t) % 60;
    return p;
}

//ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ РАВЕНСТВА И СРАВНЕНИЯ ВРЕМЕННЫХ ИНТЕРВАЛОВ
bool Time::operator==(const Time &t) {
    return min == t.min && sec == t.sec;
}

bool Time::operator!=(const Time &t) {
    return min != t.min || sec != t.sec;
}

bool Time::operator>(const Time &t) {
    return min > t.min || (min == t.min && sec > t.sec);
}

bool Time::operator<(const Time &t) {
    return min < t.min || (min == t.min && sec < t.sec);
}

bool Time::operator>=(const Time &t) {
    return min > t.min || (min == t.min && sec >= t.sec);
}

bool Time::operator<=(const Time &t) {
    return min < t.min || (min == t.min && sec <= t.sec);
}

/**
 * Перегруженный оператор для ввода с консоли
 * @param in
 * @param t
 * @return
 */
istream &operator>>(istream &in, Time &t) {
    t.min = getInt("Введите минуты:", 1, MAX_INT);
    t.sec = getInt("Введите секунды:", 1, MAX_INT);
    return in;
}

/**
 * Перегруженный оператор для вывода в консоль
 * @param out
 * @param t
 * @return
 */
ostream &operator<<(ostream &out, const Time &t) {
    return (cout << t.min << " : " << t.sec);
}