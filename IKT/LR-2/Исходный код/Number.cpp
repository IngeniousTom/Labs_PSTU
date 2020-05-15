#include <iostream>
#include "Number.h"

using namespace std;

/**
 * Конструктор без параметров
 */
Number::Number() {
    this->mantissa = 0;
    this->coefficient = 0;
    this->stringValue = "";
    cout << "\nКонструктор без параметров для объекта " << this << endl;
}

/**
 * Конструктор с параметрами
 * @param mantissa
 * @param coefficient
 * @param stringValue
 */
Number::Number(float mantissa, int coefficient, string stringValue) : mantissa(mantissa), coefficient(coefficient), stringValue(stringValue) {
    this->mantissa = mantissa;
    this->coefficient = coefficient;
    this->stringValue = stringValue;
    cout << "\nКонструктор c параметрами для объекта " << this << endl;
}

/**
 * Конструктор копирования
 * @param t
 */
Number::Number(const Number &t) {
    this->mantissa = t.mantissa;
    this->coefficient = t.coefficient;
    this->stringValue = t.stringValue;
    cout << "\nКонструктор копирования для объекта " << this << endl;
}

/**
 * Деструктор
 */
Number::~Number() {
    cout << "Деструктор для объекта " << this << endl;
}

/**
 * Метод получения мантиссы
 * @return
 */
float Number::getMantissa() {
    return mantissa;
}

/**
 * Метод установки мантиссы
 * @param mantissa
 */
void Number::setMantissa(float mantissa) {
    Number::mantissa = mantissa;
}

/**
 * Метод получения коэффициента
 * @return
 */
int Number::getCoefficient() {
    return coefficient;
}

/**
 * етод установки коэффициента
 * @param coefficient
 */
void Number::setCoefficient(int coefficient) {
    Number::coefficient = coefficient;
}

/**
 * Метод получения строкового представления
 * @return
 */
string Number::getStringValue() {
    return stringValue;
}

/**
 * Метод установки строкового представления
 * @param stringValue
 */
void Number::setStringValue(string stringValue) {
    Number::stringValue = stringValue;
}

/**
 * Метод вывода значений полей в консоль
 */
void Number::show() {
    cout << "\nОбъект:" << this << endl;
    cout << "Мантисса: " << this->mantissa << endl;
    cout << "Коэффициент: " << this->coefficient << endl;
    cout << "Строковое представление: " << this->stringValue << endl;
}
