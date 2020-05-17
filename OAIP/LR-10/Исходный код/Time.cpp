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
Time Time::operator+(Time k) {
    int t = min * 60 + sec;
    int kt = k.min * 60 + k.sec;
    t += kt;
    Time temp(t / 60, t % 60);
    return temp;
}

/**
 * Перегруженный оператор вычитания.
 * Производит вычитание временных интервалов.
 * @param k
 * @return
 */
Time Time::operator-(Time k) {
    int t = min * 60 + sec;
    int kt = k.min * 60 + k.sec;
    t -= kt;
    Time temp(t / 60, t % 60);
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

/**
 * Перегруженный оператор для считывания данных из файлового потока
 * @param fin
 * @param time
 * @return
 */
fstream &operator>>(fstream &fin, Time &time) {
    fin >> time.min;
    fin >> time.sec;
    return fin;
}

/**
 * Перегруженный оператор для записи данных в файловый поток
 * @param fout
 * @param time
 * @return
 */
fstream &operator<<(fstream &fout, const Time &time) {
    fout << time.min << endl << time.sec << endl;
    return fout;
}
