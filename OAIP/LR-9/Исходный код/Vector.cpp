#include "Vector.h"
#include "MaxSizeError.h"
#include "IndexError1.h"
#include "IndexError2.h"
#include "EmptySizeError.h"
#include <iostream>

using namespace std;

/**
 * Конструктор с параметром размера
 * @param s
 */
Vector::Vector(int s) {
    if (s > MAX_SIZE) throw MaxSizeError();
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = 0;
}

/**
 * Конструктор копирования с параметром размера
 * @param s
 * @param mas
 */
Vector::Vector(int s, int *mas) {
    if (s > MAX_SIZE) throw MaxSizeError();
    size = s;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = mas[i];
}

/**
 * Конструктор копирования
 * @param v
 */
Vector::Vector(const Vector &v) {
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
}

/**
 * Деструктор
 */
Vector::~Vector() {
    if (beg != nullptr) delete[]beg;
}

/**
 * Перегруженный оператор присваивания для копирования вектора.
 * Учитывает самоприсваивание.
 * @param v
 * @return
 */
const Vector &Vector::operator=(const Vector &v) {
    if (this == &v) return *this;
    if (beg != 0) delete[]beg;
    size = v.size;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = v.beg[i];
    return *this;
}

/**
 * Перегруженный оператор вывода в консоль
 * @param out
 * @param v
 * @return
 */
ostream &operator<<(ostream &out, const Vector &v) {
    if (v.size == 0) out << "Empty\n";
    else {
        for (int i = 0; i < v.size; i++)
            out << v.beg[i] << " ";
        out << endl;
    }
    return out;
}

/**
 * Перегруженный оператор ввода с консоли
 * @param in
 * @param v
 * @return
 */
istream &operator>>(istream &in, Vector &v) {
    for (int i = 0; i < v.size; i++) {
        cout << ">";
        in >> v.beg[i];
    }
    return in;
}

/**
 * Перегруженный оператор для доступа к элементу по индексу
 * @param i
 * @return
 */
int Vector::operator[](int i) {
    if (i < 0)throw IndexError1();
    if (i >= size) throw IndexError2();
    return beg[i];
}

/**
 * Перегруженный оператор для добавления нового элемента
 * @param a
 * @return
 */
Vector Vector::operator+(int a) {
    if (size + 1 == MAX_SIZE) throw MaxSizeError();
    Vector temp(size + 1, beg);
    temp.beg[size] = a;
    return temp;
}

/**
 * Перегруженный оператор для удаления последнего элемента
 * @return
 */
Vector Vector::operator--() {
    if (size == 0) throw EmptySizeError();
    if (size == 1) {
        size = 0;
        delete[]beg;
        beg = nullptr;
        return *this;
    };
    Vector temp(size, beg);
    delete[]beg;
    size--;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = temp.beg[i];
    return *this;
}

/**
 * Перегруженный оператор для удаления последнего элемента пост-декремент
 * @param a
 * @return
 */
Vector Vector::operator--(int a) {
    if (size == 0) throw EmptySizeError();
    if (size == 1) {
        size = 0;
        delete[]beg;
        beg = nullptr;
        return *this;
    };
    Vector temp(size, beg);
    delete[]beg;
    size--;
    beg = new int[size];
    for (int i = 0; i < size; i++)
        beg[i] = temp.beg[i + 1];
    return *this;
}

int Vector::operator()() {
    return size;
}
