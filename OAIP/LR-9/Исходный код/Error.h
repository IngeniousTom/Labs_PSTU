#ifndef LR_9_ERROR_H
#define LR_9_ERROR_H
#pragma once

#include <string>
#include <iostream>

using namespace std;

/**
 * Базовый класс ошибок
 */
class Error
{
public :
    virtual void what() {};  //Виртуальный метод вывода сообщения ошибки
};

#endif //LR_9_ERROR_H