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
    vector<T> v;    //последовательный контейнер для хранения элементов вектора
private:
    void Add(T el, int pos);//добавление элемента el на позицию
    void Del(int pos);  //удалить элемент из позиции
public:
    Vector();   //конструктор без параметра
    Vector(int n);  //конструктор с параметром
    ~Vector();  //деструктор
    void Print();   //вывод элементов вектора на экран
    T Max();    //найти номер максимальнго элемента
    T Avg();    //вычисление среднего арифметического
    void InsertMaxToTheEnd();   //Вставка максимального элемента в конец очереди
    void EraseByKey(T key);     //удаление элемента по ключу(значению)
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
    if (n < 1) {
        cout << endl << "Размер вектора не может быть меньше 1" << endl;
    }
    T a;
    for (int i = 0; i < n; i++) {
        cout << endl << i + 1 << ")" << endl;
        cin >> a;
        v.push_back(a);
    }
} //печать

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
    for (int i = 0; i < v.size(); i++) {
        cout << endl << i + 1 << ")" << endl << v[i] << endl;
    }
    cout << endl;
}

/**
 * Метод для добавления элемента в вектор на позицию pos (private)
 * @tparam T
 * @param el
 * @param pos
 */
template<class T>
void Vector<T>::Add(T el, int pos) {
    v.insert(v.begin() + pos, el);
}

/**
 * Метод для удаление элемента с позиции pos (private)
 * @tparam T
 * @param pos
 */
template<class T>
void Vector<T>::Del(int pos) {
    v.erase(v.begin() + pos);
}

/**
 * Метод поиска максимального элемента
 * @tparam T
 * @return
 */
template<class T>
T Vector<T>::Max() {
    T m = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i] > m) {
            m = v[i];
        }
    return m;
}

/**
 * Метод вычисления среднего арифметического элементов
 * @tparam T
 * @return
 */
template<class T>
T Vector<T>::Avg() {
    T s = v[0];
    for (int i = 1; i < v.size(); i++) s = s + v[i];
    int n = v.size();
    return s / n;
}

/**
 * Метод для вставки максимального элемента в конец
 * @tparam T
 */
template<class T>
void Vector<T>::InsertMaxToTheEnd() {
    T m = Max();
    cout << endl << "Максимальный элемент вектора = " << m << endl;
    Add(m, v.size());
}

/**
 * Метод для удаления элемента по ключу(значению)
 * @tparam T
 * @param key
 */
template<class T>
void Vector<T>::EraseByKey(T key) {
    vector<int> idx;   //Вектор индексов, запомниающий индексы всех совпавших по значению элементов
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            idx.push_back(i);
        }
    }
    if (idx.empty()) {
        cout << endl << "Элемент не был найден!" << endl;
        return;
    }
    for (int i : idx) {
        Del(i);
    }
}

/**
 * Метод для увеличения всех элементов на среднее арифместическое значений всех элементов
 * @tparam T
 */
template<class T>
void Vector<T>::IncreaseByAvg() {
    T a = Avg();
    cout << endl << "Среднее арифметическое элементов вектора = " << a << endl;
    for (int i = 0; i < v.size(); i++) {
        v[i] += a;
    }
}


#endif //LR_11_3_VECTOR_H
