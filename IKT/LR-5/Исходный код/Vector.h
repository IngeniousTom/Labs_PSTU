#ifndef LR_5_VECTOR_H
#define LR_5_VECTOR_H

#include <ostream>
#include "Objecto.h"

using namespace std;

/**
 * Класс "Вектор"
 */
class Vector {
private:
    Objecto **beg;
    int size;
    int current;
public:
    //Конструкторы
    Vector();
    Vector(int size);

    //Деструктор
    virtual ~Vector();

    void add(Objecto *obj);  //Метод добавления объекта в вектор
    friend ostream &operator<<(ostream &out, const Vector &vector);  //Перегруженный оператор вывода в консоль
};


#endif //LR_5_VECTOR_H
