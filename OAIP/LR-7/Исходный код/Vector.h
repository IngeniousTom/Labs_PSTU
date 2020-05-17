#ifndef LR_7_VECTOR_H
#define LR_7_VECTOR_H

#include <iostream>

using namespace std;

/**
 * Класс "Вектор"
 * @tparam T
 */
template <class T> //T - параметр шаблона
class Vector {
private:
    int size{};
    T *data;
public:
    //Конструкторы
    Vector(int size, T k);
    Vector(const Vector<T> &vector);

    //Деструктор
    virtual ~Vector();

    //Перегруженные операторы
    Vector &operator=(const Vector<T> &vector);
    T &operator[](int index);
    Vector operator+(T);
    Vector operator*(T);
    int operator()();

    //Перегруженные операторы ввода-вывода
    template <class U>
    friend ostream &operator<<(ostream&out,const Vector<U>&a);

    template <class U>
    friend istream &operator>>(istream &in, Vector<U> &a);
};

//операции для ввода-вывода
template<class T>
ostream &operator<<(ostream &out, const Vector<T> &a) {
    for (int i = 0; i < a.size; ++i) out << (i+1) << ") " << a.data[i] << endl;
    return out;
}

template<class T>
istream &operator>>(istream &in, Vector<T> &a) {
    for (int i = 0; i < a.size; ++i) {
        cout << (i+1) << ") \n";
        in >> a.data[i];
    }
    return in;
}

/**
 * Конструктор с параметрами размера
 * и значением k для заполнения
 * вектора.
 * @tparam T
 * @param size
 * @param k
 */
template<class T>
Vector<T>::Vector(int size, T k) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i < size; i++) data[i] = k;
}

/*
 * Конструктор копирования
 */
template<class T>
Vector<T>::Vector(const Vector<T> &vector) {
    size = vector.size;
    data = new T[size];
    for (int i = 0; i < size; i++) data[i] = vector.data[i];
}

/**
 * Деструктор
 * @tparam T
 */
template<class T>
Vector<T>::~Vector() {
    delete[]data;
    data = nullptr;
}

/**
 * Копирует передаваемый вектор в текущий,
 * переписывая имеющиеся элементы,
 * т.е. создает полную копию.
 * @tparam T
 * @param vector
 * @return
 */
template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vector) {
    if (this == &vector) return *this;
    size = vector.size;
    if (data != nullptr) delete[]data;
    data = new T[size];
    for (int i = 0; i < size; i++) data[i] = vector.data[i];
    return *this;
}

/**
 * Перегруженный оператор [].
 * Позволяет обратиться к элементу вектора по индексу.
 * Учитывает границы вектора.
 * @param index
 * @return
 */
template<class T>
T &Vector<T>::operator[](int index) {
    if (index >= 0 && index < size) return data[index];
    cout << "Ошибка! Значение индекса не должно быть больше индекса последнего элемента (нумерация с 0)!";
}

/**
 * Перегруженный оператор сложения.
 * Перегружен по параметру шаблонного типа.
 * Придавляет к значению каждого элемента
 * данного вектора переданное значение k.
 * @param k
 * @return
 */
template<class T>
Vector<T> Vector<T>::operator+(T k) {
    Vector<T> temp(size, k);//инициализируем временный вектор любым значением
    for (int i = 0; i < size; ++i) temp.data[i] = data[i] + k;
    return temp;
}

/**
 * Перегруженный оператор умножения.
 * Перегружен по параметру шаблонного типа.
 * Умножает значение каждого элемента
 * данного вектора на переданное значение k.
 * @param k
 * @return
 */
template<class T>
Vector<T> Vector<T>::operator*(T k) {
    Vector<T> temp(size, k);//инициализируем временный вектор любым значением
    for (int i = 0; i < size; ++i) temp.data[i] = data[i] * k;
    return temp;
}

/**
 * Перегруженный оператор ().
 * Возвращает размер данного вектора.
 * @return
 */
template<class T>
int Vector<T>::operator()() {
    return size;
}


#endif //LR_7_VECTOR_H
