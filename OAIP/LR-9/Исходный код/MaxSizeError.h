#ifndef LR_9_MAXSIZEERROR_H
#define LR_9_MAXSIZEERROR_H

#pragma once

#include <string>
#include <iostream>
#include "Error.h"
#include "SizeError.h"

using namespace std;

/**
 * Класс ошибки превышения максимального размера
 */
class MaxSizeError : public SizeError {
protected :
    string msg_;
public :
    MaxSizeError() {
        SizeError();
        msg_ = "size > MAXSIZE\n";
    }

    virtual void what() { cout << msg << msg_; }
};

#endif //LR_9_MAXSIZEERROR_H
