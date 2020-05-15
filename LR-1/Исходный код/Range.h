#ifndef LR_1_RANGE_H
#define LR_1_RANGE_H

#include "myUtilities.h"

//Структура "Диапазаон значений"
struct Range {
    double left;        //Левая граница
    double right;       //Правая граница
    void init(double left_, double right_);  //Метод для инициализации
    void read();        //Метод для ввода границ диапазона с клавиатуры
    void show();        //Метод для вывода границ диапазона на экран (в консоль)
    void rangeCheck(double x); //Метод для проверки принадлежности числа данному диапазону
};


#endif //LR_1_RANGE_H
