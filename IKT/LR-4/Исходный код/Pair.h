#ifndef LR_4_PAIR_H
#define LR_4_PAIR_H

#include "string"
#include "iostream"
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

/**
 * Класс "Пара чисел"
 */
class Pair {
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

    //Перегуженные операции
    Pair &operator=(const Pair &np);
    Pair operator+(const Pair &np);

    //Глобальные фукции ввода вывода
    friend istream &operator>>(istream &in, Pair &np);
    friend ostream &operator<<(ostream &out, const Pair &np);
};


#endif //LR_4_PAIR_H
