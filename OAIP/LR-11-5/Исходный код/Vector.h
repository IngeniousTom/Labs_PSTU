#ifndef LR_11_5_VECTOR_H
#define LR_11_5_VECTOR_H

#pragma once

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Класс "Вектор" параметризированный
 * @tparam T
 */
template<class T>
class Vector {
private:
    queue<T> s;  //Адаптер контейнера - очередь. Для хранения элементов.
private:
    void Add(T el, int pos);
public:
    Vector();   //конструктор без параметров
    Vector(int n);  //конструктор с параметрами
    Vector(const Vector<T> &);  //конструктор копирования
    ~Vector();      //Деструктор
    void Print();   //вывод элементов вектора на экран
    T Max();    //найти номер максимальнго элемента
    T Avg();    //вычисление среднего арифметического
    void InsertMaxToTheEnd();   //Вставка максимального элемента в конец очереди
    void EraseByKey(T key);     //удаление элемента по ключу(значению)
    void IncreaseByAvg();       //увеличение элементов на их вреднее арфиметическое
    queue<T> copyVectorToQueue(vector<T> v);
    vector<T> copyQueueToVector(queue<T> q);
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
        s.push(a);
    }
}

/**
 * Конструктор копирования
 * @tparam T
 * @param vec
 */
template<class T>
Vector<T>::Vector(const Vector<T> &vec) {
    if (s == vec.s) return;
    //копируем значения очереди vec.s в вектор v
    Vector v = copyQueueToVector(vec.s);
    //копируем вектор v в очередь s
    s = copyVectorToQueue(v);
}

/**
 * Деструктор
 * @tparam T
 */
template<class T>
Vector<T>::~Vector() = default;

/**
 * Методя для вывода элементов в консоль
 * @tparam T
 */
template<class T>
void Vector<T>::Print() {
    vector<T> v = copyQueueToVector(s);  //копируем очередь в вектор
    int i = 1;

    while (!s.empty()) {
        cout << endl << i++ << ")" << endl;
        cout << s.front() << endl;  //вывод элемента в вершине очереди
        s.pop();    //удаляем элемент из вершины
    }

    s = copyVectorToQueue(v);  //копируем вектор в очередь
}

/**
 * Метод для добавления элемента в вектор на позицию pos (private)
 * @tparam T
 * @param el
 * @param pos
 */
template<class T>
void Vector<T>::Add(T el, int pos) {
    if (pos < 1 || pos > s.size() + 1) {  //Если позиция имеет недопустимое значние, то вставка н происходит
        return;
    }

    vector<T> v;    //вспомогательный вектор
    T t;
    int i = 1;

    while (!s.empty()) {
        t = s.front();  //получить элемент из вершины очереди
        if (i == pos) v.push_back(el);   //если номер элемента равен pos добавляем в вектор новый элемент
        v.push_back(t); //добавляем t в вектор
        s.pop();    //удаляем элемент из вершины очереди
        i++;
    }

    if (i == pos) v.push_back(el);  //на случай добваления в конец
    s = copyVectorToQueue(v);    //копируем вектор в очередь
}

/**
 * Метод поиска максимального элемента
 * @tparam T
 * @return
 */
template<class T>
T Vector<T>::Max() {
    T m = s.front();    //m присвоить значение из вершины очереди

    vector<T> v = copyQueueToVector(s);  //В вектор скопировать элементы очереди
    while (!s.empty()) {
        //сравниваем m и элемент в вершине очереди
        if (s.front() > m) {
            m = s.front();
        }
        s.pop();//удаляем элемент из вершины очереди
    }
    s = copyVectorToQueue(v);//копируем вектор в очередь
    return m;
}

/**
 * Метод вычисления среднего арифметического элементов
 * @tparam T
 * @return
 */
template<class T>
T Vector<T>::Avg() {
    //копируем очередь в вектор
    vector<T> v = copyQueueToVector(s);
    int n = 1;  //количество элементов в стеке
    T sum = s.front();  //начальное значение для суммы
    s.pop();    //удаляем элемент из вершины очереди

    while (!s.empty()) {
        sum = sum + s.front();  //добавляем в сумму элемент из вершины очереди
        s.pop();    //удаляем элемент из вершины очереди
        n++;    //увеличиваем количество элементов
    }
    //копируем вектор в очередь
    s = copyVectorToQueue(v);

    return sum / n;  //делим сумму на число элементов
}

/**
 * Метод для вставки максимального элемента в конец
 * @tparam T
 */
template<class T>
void Vector<T>::InsertMaxToTheEnd() {
    T max = Max();
    cout << endl << "Максимальный элемент очереди = " << max << endl;
    Add(max, s.size() + 1);
}

/**
 * Метод для удаления элемента по ключу(значению)
 * @tparam T
 * @param key
 */
template<class T>
void Vector<T>::EraseByKey(T key) {
    vector<T> v;
    T t;
    int initSize = s.size();

    while (!s.empty()) {
        t = s.front();//получаем элемент из вершины очереди
        //Если он не равен максимальному, заносим элемент в вектор
        if (t != key) v.push_back(t);
        s.pop();
    }
    if (v.size() == initSize) {
        cout << "Элемент не был найден!" << endl;
    }
    s = copyVectorToQueue(v);   //копируем вектор в очередь
}

/**
 * Метод для увеличения всех элементов на среднее арифместическое значений всех элементов
 * @tparam T
 */
template<class T>
void Vector<T>::IncreaseByAvg() {
    T avg = Avg();
    cout << endl << "Среднее арифметическое элементов очереди = " << avg << endl;
    vector<T> v;
    T t;
    while (!s.empty()) {
        t = s.front();
        v.push_back(t + avg);
        s.pop();
    }
    s = copyVectorToQueue(v);
}

/**
 * Метод копирования очереди в вектор
 * @tparam T
 * @param q
 * @return
 */
template<class T>
vector<T> Vector<T>::copyQueueToVector(queue<T> q) {
    vector<T> v;
    while (!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

/**
 * Метод копирования вектора в очередь
 * @tparam T
 * @param v
 * @return
 */
template<class T>
queue<T> Vector<T>::copyVectorToQueue(vector<T> v) {
    queue<T> q;
    for (int i = 0; i < v.size(); i++) {
        q.push(v[i]);
    }
    return q;
}


#endif //LR_11_5_VECTOR_H