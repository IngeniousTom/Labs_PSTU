#include "Vector.h"

/**
 * Конструктор с параметрами размера
 * и значением k, которым данный
 * вектор заполняется.
 * @param size
 * @param k
 */
Vector::Vector(int size, int k) {
    this->size = size;
    this->data = new int[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = k;
    }
    beg.element=&data[0];
    end.element=&data[size];
}

/**
 * Конструктор с параметром размера.
 * Заполняет все элементы значением 0.
 * @param size
 */
Vector::Vector(int size):Vector(size, 0) {}

/**
 * Конструктор копирования
 * @param vector
 */
Vector::Vector(const Vector &vector) {
    size = vector.size;
    data=new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = vector.data[i];
    }
    beg=vector.beg;
    end=vector.end;
}

/**
 * Деструктор
 */
Vector::~Vector() {
    delete[] data;
    data = nullptr;
}


/**
 * Перегруженный оператор [].
 * Позволяет обратиться к элементу вектора по индексу.
 * Учитывает границы вектора.
 * @param index
 * @return
 */
int &Vector::operator[](int index) {
    if (index >= 0 && index < size) return data[index];
    cout << "Ошибка! Значение индекса не должно быть больше индекса последнего элемента (нумерация с 0)!";
}

/**
 * Перегруженный оператор присваивания.
 * Копирует передаваемый вектор в текущий,
 * переписывая имеющиеся элементы,
 * т.е. создает полную копию.
 * @param vector
 * @return
 */
Vector &Vector::operator=(const Vector &vector) {
    if (this == &vector) return *this;
    size = vector.size;
    if (data != nullptr) delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = vector.data[i];
    }
    beg=vector.beg;
    end=vector.end;
    return *this;
}

/**
 * Перегруженный оператор сложения.
 * Перегружен по параметру типа int.
 * Придавляет к значению каждого элемента
 * данного вектора переданное значение k.
 * @param k
 * @return
 */
Vector Vector::operator+(const int k) { //+k
    Vector temp(size);
    for (int i = 0; i < size; i++) {
        temp.data[i] += data[i] + k;
    }
    return temp;
}

/**
 * Перегруженный оператор умножения.
 * Перегружен по параметру типа int.
 * Умножает значение каждого элемента
 * данного вектора на переданное значение k.
 * @param k
 * @return
 */
Vector Vector::operator*(int k) { //*k
    Vector temp(size);
    for (int i = 0; i < size; i++) {
        temp.data[i] += data[i] * k;
    }
    return temp;
}

/**
 * Перегруженный оператор ().
 * Возвращает размер данного вектора.
 * @return
 */
int Vector::operator()() {
    return size;
}

/**
 * Перегруженный оператор вывода в консоль.
 * Поочередно выводит в консоль все элементы
 * данного вектора.
 * @param out
 * @param vector
 * @return
 */
ostream &operator<<(ostream &out, const Vector &vector) {
    for (int i = 0; i < vector.size; i++) {
        out << vector.data[i] << " ";
    }
    return out;
}

/**
 * Перегруженный оператор ввода с консоли.
 * Позволяет поочередно ввести значение каждого элемента
 * вектора.
 * @param in
 * @param vector
 * @return
 */
istream &operator>>(istream &in, Vector &vector) {
    for (int i = 0; i < vector.size; i++) {
        vector.data[i] = getInt("", MIN_INT, MAX_INT);
    }
    return in;
}