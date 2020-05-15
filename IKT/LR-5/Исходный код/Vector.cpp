#include "Vector.h"


/**
 * Конструктор без параметров
 */
Vector::Vector() {
    beg = nullptr;
    size = 0;
    current = 0;
}

/**
 * Конструктор с параметром размера
 */
Vector::Vector(int size) {
    beg = new Objecto *[size];
    this->size = size;
    current = 0;
}

/**
 * Деструктор
 */
Vector::~Vector() {
    if (beg != nullptr) delete [] beg;
    beg = nullptr;
}

/**
 * Метод добавления объекта в вектор
 * @param obj
 */
void Vector::add(Objecto *obj) {
    if (current < size) {
        beg[current] = obj;
        current++;
    }
}

/**
 * Перегруженный оператор вывода в консоль.
 * Выводит поочередно каждый хранимый объект.
 * @param out
 * @param vector
 * @return
 */
ostream &operator<<(ostream &out, const Vector &vector) {
    out << endl << "Вывод элементов вектора:\n" << endl;

    if (vector.size == 0) out << "\tПусто!" << endl;

    Objecto **p = vector.beg; //указатель на объект типа Objecto
    for (int i = 0; i < vector.current; i++) {
        out << "Элемент " << (i + 1) << ":" << endl;
        (*p)->show();
        out << endl << endl;
        p++;
    }
    return out;
}



