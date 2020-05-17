#ifndef LR_9_INDEXERROR_H
#define LR_9_INDEXERROR_H
#pragma once

#include <string>
#include <iostream>
#include "Error.h"

using namespace std;

/**
 * Безовый класс ошибки в индексе вектора
 */
class IndexError : public Error {
protected :
    string msg;
public :
    IndexError() { msg = "Index Error\n"; }

    virtual void what() { cout << msg; }
};

#endif //LR_9_INDEXERROR_H
