#ifndef LR_6_VECTOR_H
#define LR_6_VECTOR_H

#include "iostream"
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

/**
 * Класс итератор.
 * Является вспомогательным классом
 * для класса "Вектор"
 */
class Iterator {
    friend class Vector;

private:
    int *element;
public:
    Iterator() { element = nullptr; }

    Iterator(const Iterator &it) {
        element = it.element;
    }

    //перегруженные операции сравнения
    bool operator==(const Iterator &it) { return element == it.element; }

    bool operator!=(const Iterator &it) { return element != it.element; }

    //перегруженная операция инкремент
    void operator++() { ++element; }

    void operator++(int) { ++element; }

    //перегруженная операция декремент
    void operator--() { --element; }

    void operator--(int) { --element; }

    //перегруженная операция разыменования
    int &operator*() const { return *element; }
};

/**
 * Класс "Вектор"
 */
class Vector {
private:
    int size;
    int *data;
    Iterator beg;
    Iterator end;
public:
    //Конструкторы
    Vector(int size, int k);
    explicit Vector(int size);
    Vector(const Vector &vector);

    //Деструктор
    virtual ~Vector();

    //Перегруженные операторы
    int &operator[](int index);

    Vector &operator=(const Vector &vector);

    Vector operator+(int k);

    Vector operator*(int k);

    int operator()();

    //Перегруженные операторы ввода-вывода
    friend ostream &operator<<(ostream &out, const Vector &vector);

    friend istream &operator>>(istream &in, Vector &vector);

    //Возвращает указатель на первый элемент
    Iterator first() { return beg; }

    //Возвращает указатель на элемент следующий за последним
    Iterator last() { return end; }

    /*Перегруженный оператор - (int) итератора.
    Переводит итератор влево на элемент с номером n*/
    Iterator operator-(int n) {
        n--;   //т.к. снаружи это номер, а здесь индекс
        Iterator iter = end;
        if (n < 0) {
            for (int i = size; i > 0; --i) {
                iter--;
            }
        } else if (n <= (size - 1)) {
            for (int i = size; i > n; --i) {
                iter--;
            }
        }

        return iter;
    }
};


#endif //LR_6_VECTOR_H
