#include <iostream>
#include "Pair.h"
#include "Complex.h"


/**
 * Функция, принимающая ссылку
 * на объект типа "Пара чисел".
 * Принимает в качестве парметра ссылку на такой объект
 * присваивает ему значения 1 и 5 и выводит в консоль.
 * @param p
 */
void takePair(Pair &p) {
    p.setFirst(1);
    p.setSecond(5);
    cout << p << endl;
}

/**
 * Функция, принимающая указатель
 * на объект типа "Пара чисел".
 * Принимает в качестве парметра ссылку на такой объект
 * и выводит его в консоль.
 * @param p
 */
void takePairP(Pair *p) {
    cout << *p << endl;
}

/**
 * Функция, создающая объект типа "Комплексное число"
 * и возвращающая его как объект базового класса "Пара чисел"
 * @return
 */
Pair makePairFromComplex() {
    Complex complex(3, 7, 1, 6);
    return complex;
}

/**
 * Функция, создающая объект типа "Комплексное число"
 * и возвращающая его как объект базового класса "Пара чисел"
 * по уазателю
 * @return
 */
Pair * makePairFromComplexP() {
    Complex *complex = new Complex(3, 7, 1, 6);
    return complex;
}

/**
 * Главная функция
 * @return
 */
int main() {
    //Работа с базовым классом Pair
    Pair a;
    cin >> a;
    cout << "a: " << a << endl;

    Pair b(1, 5);
    cout << "\nb: " << b << endl;

    a = b;
    cout << "\na (после a = b): " << a << endl;

    Pair c;
    c.setFirst(2);
    c.setSecond(7);
    cout << "\nc: " << c << endl;
    c = a + b;
    cout << "\nc (после c = a + b): " << c << endl;

    //Работа с производным классом Complex
    Complex d;
    cin >> d;
    cout << "\nComplex d: " << d << endl;

    Complex d2;
    cin >> d2;
    cout << "\nComplex d2: " << d2 << endl;

    cout << "\nd - d2 = " << (d - d2) << endl;
    cout << "\nd * d2 = " << (d * d2) << endl;


    //Принцип подстановки
    cout << "\nПодстановка Complex d в метод, принимающий Pair:" << endl;
    takePair(d);  //Выведет как Pair, потому что типа параметра фцнкйии = Pair&
    a = makePairFromComplex();
    //Выведет как Pair, потому что a имеет тип Pair
    cout << "\nPair a, хранящая новую переменную типа Pair созданную конструктором Complex: " << endl << a << endl;

    Complex *e = new Complex(0, 0, 7, 8);
    cout << "\nПодстановка Complex *e в метод, принимающий Pair*:" << endl;
    takePairP(e);  //Выведет как Pair потому что тип указателя параметра Pair*
    cout << "\nПросто вывод Complex *e:" << endl << *e << endl;
    Pair *f;
    f = makePairFromComplexP(); //вернется и выведется как Pair, потому что тип указателя f  =  Pair*
    cout << "\nPair* f, указатель новый объект типа Complex созданный конструктором Complex и возвращенный как *Pair: " << endl << *f << endl;

    Complex* g;
    g = (Complex*) makePairFromComplexP(); //вернется и выведется как Pair, потому что восходящее преобразование не работет
    cout << "\nComplex* g, указатель новый объект типа Complex созданный конструктором Complex и возвращенный как *Pair: " << endl << *f << endl;

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}
