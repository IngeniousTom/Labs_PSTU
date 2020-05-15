#ifndef LR_5_COMPLEX_H
#define LR_5_COMPLEX_H

#include "Pair.h"
#include "string"
#include "iostream"

using namespace std;

/**
 * Класс "Комплексное число"
 */
class Complex : public Pair {
protected:
    int real;
    int imaginary;
public:
    //Конструкторы
    Complex();
    Complex(int first, int second, int real, int imaginary);
    Complex(int real, int imaginary);
    Complex(const Complex &cm);

    //Деструктор
    ~Complex() override;

    //Селекторы
    int getReal() const;
    int getImaginary() const;

    //Модификаторы
    void setReal(int real);
    void setImaginary(int imaginary);

    //Метод для вывода в консоль аттрибутов класса с помощью указателя
    void show() override;

    //Перегуженные операции
    Complex &operator=(const Complex &cm);
    Complex operator+(const Complex &cm);
    Complex operator-(const Complex &cm);
    Complex operator*(const Complex &cm);

    //Глобальные фукции ввода вывода
    friend istream &operator>>(istream &in, Complex &cm);
    friend ostream &operator<<(ostream &out, const Complex &cm);
};


#endif //LR_5_COMPLEX_H
