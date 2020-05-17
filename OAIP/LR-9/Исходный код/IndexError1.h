#ifndef LR_9_INDEXERROR1_H
#define LR_9_INDEXERROR1_H

#pragma once

#include <string>
#include <iostream>
#include "IndexError.h"

using namespace std;

/**
 * Класс ошибки "Индекс меньше нуля"
 */
class IndexError1 : public IndexError
{
protected :
    string msg_;
public :
    IndexError1() {
        IndexError();
        msg_ = "index < 0\n";
    }

    virtual void what() { cout << msg << msg_; }
};

#endif //LR_9_INDEXERROR1_H
