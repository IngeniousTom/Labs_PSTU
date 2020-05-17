#include "Time.h"

/**
 * Перегруженный оператор присваивания.
 * Присваивает данному временному интервалу
 * значения полей передаваемого справа от знака =.
 * Учитывает случай самоприсваивания.
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
 * Перегруженный оператор сложения времени.
 * Учитывает, что в минуте не может быть более 60 секунд.
 * @param k
 * @return
 */
Time Time::operator+(const Time &k) {
    int t = min * 60 + sec;
    int kt = k.min * 60 + k.sec;
    t += kt;
    Time temp(t / 60, t % 60);
    return temp;
}

/**
 * Перегруженный оператор сложения с присваиванием.
 * Производит сложение временных интервалов и присваивает 
 * результат левому интервалу.
 * Учитывает, что в минуте не может быть более 60 секунд.
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
 * Перегруженный оператор умножения времени.
 * Учитывает, что в минуте не может быть более 60 секунд.
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
 * Перегруженный оператор инкремента.
 * Учитывает, что в минуте не может быть более 60 секунд.
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
 * Перегруженный оператор пост-инкремента.
 * Учитывает, что в минуте не может быть более 60 секунд.
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
 * Перегруженный оператор делеания на время.
 * Учитывает, что в минуте не может быть более 60 секунд.
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
 * Перегруженный оператор делеания на секунды.
 * Учитывает, что в минуте не может быть более 60 секунд.
 * @return
 */
Time Time::operator/(const int &t) {
    int temp1 = min * 60 + sec;
    Time p;
    p.min = (temp1 / t) / 60;
    p.sec = (temp1 / t) % 60;
    return p;
}

/*
 * Перегруженный оператор сравнения "строго меньше"
 */
bool Time::operator<(const Time &t) {
    if (min < t.min) return true;
    if (min == t.min && sec < t.sec) return true;
    return false;
}

/*
 * Перегруженный оператор сравнения "строго больше"
 */
bool Time::operator>(const Time &t) {
    if (min > t.min) return true;
    if (min == t.min && sec > t.sec) return true;
    return false;
}

/*
 * Перегруженный оператор проверки на равенство
 */
bool Time::operator==(const Time &t) {
    return min == t.min && sec == t.sec;
}

/**
 * Перегруженный оператор проверки на неравенство
 * @param t
 * @return
 */
bool Time::operator!=(const Time &t) {
    return min != t.min || sec != t.sec;
}

/**
 * Перегруженный оператор ввода с консоли
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
 * Перегруженный оператор вывода в консоль
 * @param out
 * @param t
 * @return
 */
ostream &operator<<(ostream &out, const Time &t) {
    return (cout << "(" << t.min << " : " << t.sec << ")");
}