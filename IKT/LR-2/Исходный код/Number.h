#ifndef LR_2_NUMBER_H
#define LR_2_NUMBER_H

#include <string>

using namespace std;

/**
 * Класс "Число"
 */
class Number {
    float mantissa;     //Мантисса
    int coefficient;    //Порядок
    string stringValue; //Строковое представление
public:
    Number();                                //Конструктор без параметров
    Number(float mantissa, int coefficient, const string& stringValue); //Конструктор с пармаетрами
    Number(const Number &);                  //Конструктор копирования
    ~Number();                               //Деструктор
    float getMantissa();                     //Метод получения мантиссы
    void setMantissa(float mantissa);        //Метод установки мантиссы
    int getCoefficient();                    //Метод получения коэффициента
    void setCoefficient(int coefficient);    //Метод установки коэффициента
    string getStringValue();                 //Метод получения строкового представления
    void setStringValue(string stringValue); //Метод установки строкового представления
    void show();                             //Метод вывода значений полей в консоль
};


#endif //LR_2_NUMBER_H
