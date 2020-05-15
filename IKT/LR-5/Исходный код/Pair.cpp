#include "Pair.h"

/**
 * Конструктор без параметров
 */
Pair::Pair() {}

/**
 * Конструктор с параметрами
 * @param first
 * @param second
 */
Pair::Pair(int first, int second) {
    this->first = first;
    this->second = second;
}

/**
 * Конструктор копирования
 * @param np
 */
Pair::Pair(const Pair &np) {
    this->first = np.first;
    this->second = np.second;
}

/**
 * Деструктор
 */
Pair::~Pair() {}


/**
 * Метод получения первого числа
 * @return
 */
int Pair::getFirst() const {
    return first;
}

/**
 * Метод установки первого числа
 * @param first
 */
void Pair::setFirst(int first) {
    this->first = first;
}

/**
 * Метод получения второго числа
 * @return
 */
int Pair::getSecond() const {
    return second;
}

/**
 * Метод установки второго числа
 * @param second
 */
void Pair::setSecond(int second) {
    this->second = second;
}

/**
 * Перегруженный оператор присваивания
 * @param np
 * @return
 */
Pair &Pair::operator=(const Pair &np) {
    if (&np==this) return *this;
    this->first = np.first;
    this->second = np.second;
    return *this;
}

/**
 * Перегруженный оператор сложения
 * @param np
 * @return
 */
Pair Pair::operator+(const Pair &np) {
    Pair result;
    result.setFirst(this->first + this->second);
    result.setSecond(np.first + np.second);
    return result;
}

/**
 * Перегруженный оператор ввода с консоли
 * @param in
 * @param np
 * @return
 */
istream &operator>>(istream &in, Pair &np) {
    np.first = getInt("Введите первое число: ", MIN_INT, MAX_INT);
    np.second = getInt("Введите второе число: ", MIN_INT, MAX_INT);
    return in;
}

/**
 * Перегруженный оператор вывода в консоль
 * @param out
 * @param np
 * @return
 */
ostream &operator<<(ostream &out, const Pair &np) {
    return (out << np.first << ", " << np.second);
}

/**
 * Метод для вывода в консоль аттрибутов класса с помощью указателя
 */
void Pair::show() {
    cout << this->first << ", " << this->second;
}



