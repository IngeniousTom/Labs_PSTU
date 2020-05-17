#ifndef LR_9_EMPTYSIZEERROR_H
#define LR_9_EMPTYSIZEERROR_H

#pragma once

#include <string>
#include <iostream>
#include "Error.h"
#include "SizeError.h"

using namespace std;

/**
 * Класс ошибки удаления из пустого контейнера
 */
class EmptySizeError : public SizeError {
protected :
    string msg_;
public :
    EmptySizeError() {
        SizeError();
        msg_ = "Vector is empty\n";
    }

    virtual void what() { cout << msg << msg_; }
};

#endif //LR_9_EMPTYSIZEERROR_H
