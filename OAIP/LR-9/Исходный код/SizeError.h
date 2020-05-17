#ifndef LR_9_SIZEERROR_H
#define LR_9_SIZEERROR_H
#pragma once

#include <string>
#include <iostream>
#include "Error.h"

using namespace std;

/**
 * Базовый класс ошибки размера
 */
class SizeError : public Error
{
protected :
    string msg;
public :
    SizeError() { msg = "Size error\n"; }

    virtual void what() { cout << msg; }
};

#endif //LR_9_SIZEERROR_H
