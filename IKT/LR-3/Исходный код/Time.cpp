#include "Time.h"
#include "myUtilities.h"


/**
 * Перегруженный оператор присваивания.
 * Присваивает данному временному интервалу 
 * значения полей передаваемого справа от знака =.
 * Учитывает случай самоприсваивания.
 * @param t 
 * @return 
 */
Time &Time::operator=(const Time &t) {
    if (&t==this) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}

/*
 * Перегруженный оператор инкремента.
 * Учитывает, что в минуте не может быть более 60 секунд.
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
 * Перегруженный оператор для добавления секунд.
 * Учитывает, что в минуте не может быть более 60 секунд.
 * @param s 
 * @return 
 */
Time Time::operator+(int s) {
    int temp = min * 60 + sec;
    temp+=s;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
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
    return (cout << t.min << " : " << t.sec);
}
