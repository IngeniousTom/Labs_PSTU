#ifndef LR_9_INDEXERROR2_H
#define LR_9_INDEXERROR2_H

#pragma once

#include <string>
#include <iostream>
#include "IndexError.h"

using namespace std;

/**
 * Класс ошибки "Индекс больше текущего размера вектора"
 */
class IndexError2 : public IndexError
{
protected :
    string msg_;
public :
    IndexError2() {
        IndexError();
        msg_ = "index > size\n";
    }

    virtual void what() { cout << msg << msg_; }
};

#endif //LR_9_INDEXERROR2_H
