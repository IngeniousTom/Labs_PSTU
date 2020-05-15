#include "Complex.h"

/**
 * Конструктор без параметров
 */
Complex::Complex() : Pair() {
    this->real = 0;
    this->imaginary = 0;

}

/**
 * Конструктор с параметрами
 * @param first
 * @param second
 * @param real
 * @param imaginary
 */
Complex::Complex(int first, int second, int real, int imaginary) : Pair(first, second) {
    this->real = real;
    this->imaginary = imaginary;
}

/**
 * Конструктор с параметрами (только свои)
 * @param real
 * @param imaginary
 */
Complex::Complex(int real, int imaginary) {
    this->real = real;
    this->imaginary = imaginary;
    /*this->first = 0;
    this->second = 0;*/
}

/**
 * Конструктор копирования
 * @param cm
 */
Complex::Complex(const Complex &cm) {
    this->real = cm.real;
    this->imaginary = cm.imaginary;
}

/**
 * Деструктор
 */
Complex::~Complex() {}

/*
 * Метод получения реальной части
 */
int Complex::getReal() const {
    return real;
}

/**
 * Метод получения мнимой части
 * @return
 */
int Complex::getImaginary() const {
    return imaginary;
}

/**
 * Метод установки реальной части
 * @param real
 */
void Complex::setReal(int real) {
    Complex::real = real;
}

/**
 * Метод установки мнимой части
 * @param imaginary
 */
void Complex::setImaginary(int imaginary) {
    Complex::imaginary = imaginary;
}

/**
 * Перегруженный оператор присваивания
 * @param cm
 * @return
 */
Complex &Complex::operator=(const Complex &cm) {
    if (&cm == this) return *this;
    this->real = cm.real;
    this->imaginary = cm.imaginary;
    return *this;
}

/*
 * Перегруженный оператор сложения
 */
Complex Complex::operator+(const Complex &cm) {
    Complex result;
    result.setReal(this->real + this->imaginary);
    result.setImaginary(cm.real + cm.imaginary);
    return result;
}


/**
 * Перегруженный оператор вычитания
 * @param cm
 * @return
 */
Complex Complex::operator-(const Complex &cm) {
    Complex result;
    result.setReal(this->real - this->imaginary);
    result.setImaginary(cm.real - cm.imaginary);
    return result;
}

/**
 * Перегруженный оператор умножения
 * @param cm
 * @return
 */
Complex Complex::operator*(const Complex &cm) {
    Complex result;
    result.setReal(this->real * cm.real - this->imaginary * cm.imaginary);
    result.setImaginary(this->real * cm.imaginary + this->imaginary * cm.real);
    return result;
}

/**
 * Перегруженный оператор ввода с консоли
 * @param in
 * @param cm
 * @return
 */
istream &operator>>(istream &in, Complex &cm) {
    cm.real = getInt("Введите реальную часть: ", MIN_INT, MAX_INT);
    cm.imaginary = getInt("Введите мнимую часть: ", MIN_INT, MAX_INT);
    return in;
}

/**
 * Перегруженный оператор вывода в консоль
 * @param out
 * @param cm
 * @return
 */
ostream &operator<<(ostream &out, const Complex &cm) {
    out << "Реальная часть: " << cm.real << endl;
    out << "Мнимая часть: " << cm.imaginary << endl;
    return out;
}

/**
 * Метод для вывода в консоль аттрибутов класса с помощью указателя
 */
void Complex::show() {
    cout << "Реальная часть: " << this->real << endl;
    cout << "Мнимая часть: " << this->imaginary << endl;
}
