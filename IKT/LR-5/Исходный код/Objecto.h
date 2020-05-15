#ifndef LR_5_OBJECTO_H
#define LR_5_OBJECTO_H
#pragma once

//т.к. Object - это исключительное имя для объекта которое нельхя использовать
class Objecto {
public:
    Objecto();
    ~Objecto();
    virtual void show() = 0;
};


#endif //LR_5_OBJECTO_H
