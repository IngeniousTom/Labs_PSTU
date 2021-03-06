#include "Range.h"
#include <iostream>

using namespace std;

/**
 * Метод для иниациализации диапазона значений.
 * Принимает параметры в качестве значений
 * границ данного диапазона. Если границы перепутаны местами,
 * то меняет их на правильный порядок и сообщает об этом.
 * Если границы равны то оставляет как есть.
 * @param left_
 * @param right_
 */
void Range::init(double left_, double right_) {
    if (left_ < right_) {
        this->left = left_;
        this->right = right_;
    } else {
        this->left = right_;
        this->right = left_;
        cout << "\nГраницы были перепутаны местами, они теперь упорядочены!\n";
    }
}

/**
 * Метод для ввода границ диапазона с клавиатуры.
 * Если границы перепутаны местами,
 * то меняет их на правильный порядок и сообщает об этом.
 * Если границы равны то оставляет как есть.
 */
void Range::read() {
    double left_ = getDouble(string_format("\nВведите левую границу диапазона! (от %d до %d)", 0, 100), 0, 100);
    double right_ = getDouble(string_format("\nВведите правую границу диапазона! (от %d до %d)", 0, 100), 0, 100);
    if (left_ > right_) {
        this->left = right_;
        this->right = left_;
        cout << "\nГраницы были перепутаны местами, они теперь упорядочены!\n";
    }
    this->left = left_;
    this->right = right_;
}

/**
 * Метод для вывода границ диапазона на экран (в консоль)
 */
void Range::show() {
    cout << "\nЛевая граница диапазона = " << this->left << endl;
    cout << "Правая граница диапазона = " << this->right << endl;
}

/**
 * Метод для проверки принадлежности числа данному диапазону.
 * Принимает x и возвращает выводит в консоль информацию о том,
 * принадлежит ли данный аргумент текущему диапазону
 * @param x
 */
void Range::rangeCheck(double x) {
    if (x >= this->left && x <= this->right) {
        cout << "\nЧисло " << x << " принадлежит данному диапазону [" << this->left << ";" << this->right << "]!";
    } else {
        cout << "\nЧисло " << x << " не принадлежит данному диапазону [" << this->left << ";" << this->right << "]!";
    }
}