#ifndef LR_11_3_VECTOR_H
#define LR_11_3_VECTOR_H

#pragma once

#include <vector>
#include <iostream>
#include "myUtilities.h"

using namespace std; //шаблон класса

/**
 * Класс "Вектор" параметризированный
 * @tparam T
 */
template<class T>
class Vector {
private:
    map<int, T> m;    //последовательный контейнер для хранения элементов вектора
public:
    Vector();   //конструктор без параметра
    Vector(int n);  //конструктор с параметром
    ~Vector();  //деструктор
    void Print();   //вывод элементов вектора на экран
    T Max();    //найти номер максимальнго элемента
    T Avg();    //вычисление среднего арифметического
    void InsertMaxToTheEnd();   //Вставка максимального элемента в конец очереди
    void EraseByKey(int key);     //удаление элемента по ключу(значению)
    void IncreaseByAvg();       //увеличение элементов на их вреднее арфиметическое
};

/**
 * Конструктор без параметра
 * @tparam T
 */
template<class T>
Vector<T>::Vector() {
}

/**
 * Конструктор с параметром
 * @tparam T
 * @param n
 */
template<class T>
Vector<T>::Vector(int n) {
    int key;
    T value;

    cout << "Введите элементы словаря:" << endl;

    for (int i = 0; i < n; i++) {
        cout << endl << i + 1 << ")" << endl;
        key = getInt("\"Ключ:", MIN_INT, MAX_INT);
        cout << "Значение:" << endl;
        cin >> value;
        m.insert(make_pair(key, value));
    }
}

/**
 * Деструктор
 * @tparam T
 */
template<class T>
Vector<T>::~Vector() {}

/**
 * Методя для вывода элементов в консоль
 * @tparam T
 */
template<class T>
void Vector<T>::Print() {
    for (auto & el : m) {
        cout << endl << "Ключ: " << el.first;
        cout << endl << "Значение: " << endl;
        cout << el.second;
        cout << endl;
    }
    cout << endl;
}

/**
 * Метод поиска максимального элемента
 * @tparam T
 * @return
 */
template<class T>
T Vector<T>::Max() {
    T max = (*m.begin()).second;

    for (auto & el : m) {
        if (max < el.second) {
            max = el.second;
        }
    }

    return max; //max
}

/**
 * Метод вычисления среднего арифметического элементов
 * @tparam T
 * @return
 */
template<class T>
T Vector<T>::Avg() {
    T s = Time(0, 0);

    for (auto & el : m) {
        s += el.second;
    }

    int n = m.size(); //количество элементов в словаре

    return s / n;
}

/**
 * Метод для вставки максимального элемента в конец
 * @tparam T
 */
template<class T>
void Vector<T>::InsertMaxToTheEnd() {
    T max = Max();
    cout << endl << "Максимальное значение элементов словаря = " << max << endl;

    pair<int , T> newMax;
    for (auto & el : m) {
        if (el.second == max) {
            newMax = pair<int, T>(el);
            break;
        }
    }

    //Чтобы элемент оказался в конце словаря нужно,
    //чтобы ключ нового элемента был больше, чем ключ последнего на данный момент
    newMax.first = (*(--m.end())).first + 1;
    m.insert(m.end(), newMax);
}

/**
 * Метод для удаления элемента по ключу(значению)
 * @tparam T
 * @param key
 */
template<class T>
void Vector<T>::EraseByKey(int key) {
    unsigned long erased = m.erase(key); //удаление элемента;
    if (erased < 1) {
        cout << "Элемент не был найден!" << endl;
    }
}

/**
 * Метод для увеличения всех элементов на среднее арифместическое значений всех элементов
 * @tparam T
 */
template<class T>
void Vector<T>::IncreaseByAvg() {
    const T a = Avg();
    cout << endl << "Среднее арифметическое элементов вектора = " << a << endl;
    for (auto& el : m) {
        el.second += a;
    }
}


#endif //LR_11_3_VECTOR_H
