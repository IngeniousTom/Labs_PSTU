#ifndef LR_5_PAIR_H
#define LR_5_PAIR_H

#include "string"
#include "iostream"
#include "Objecto.h"
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

/**
 * Класс "Пара чисел"
 */
class Pair : public Objecto {
protected:
    int first, second;
public:
    //Конструкторы
    Pair();
    Pair(int first, int second);
    Pair(const Pair& np);

    //Деструктор
    virtual ~Pair();

    //Селекторы
    int getFirst() const;
    int getSecond() const;

    //Модификаторы
    void setFirst(int first);
    void setSecond(int second);

    //Метод для вывода в консоль аттрибутов класса с помощью указателя
    void show() override;

    //Перегуженные операции
    Pair &operator=(const Pair &np);
    Pair operator+(const Pair &np);

    //Глобальные фукции ввода вывода
    friend istream &operator>>(istream &in, Pair &np);
    friend ostream &operator<<(ostream &out, const Pair &np);
};


#endif //LR_5_PAIR_H
