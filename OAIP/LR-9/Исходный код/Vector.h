#ifndef LR_9_VECTOR_H
#define LR_9_VECTOR_H


#pragma once

#include <iostream>
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

const int MAX_SIZE = 20;

class Vector {
    int size;
    int *beg;
public :
    //Конструкторы
    Vector() {
        size = 0;
        beg = nullptr;
    }
    Vector(int s);
    Vector(int s, int *mas);
    Vector(const Vector &v);

    //Деструктор
    ~Vector();

    //Перегруженные операторы
    const Vector &operator=(const Vector &v);
    int operator[](int i);
    int operator()();
    Vector operator+(int a);
    Vector operator--();
    Vector operator--(int a);

    //Перегруженные операторы ввода-вывода с консолью
    friend ostream &operator<<(ostream &out, const Vector &v);
    friend istream &operator>>(istream &in, Vector &v);
};


#endif //LR_9_VECTOR_H
