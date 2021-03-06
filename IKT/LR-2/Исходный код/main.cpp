#include <iostream>
#include "Number.h"
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()
#define MIN_FLOAT numeric_limits<float>::min()
#define MAX_FLOAT numeric_limits<float>::max()

using namespace std;

/**
 * Функция создания объекта класса "Число".
 * Организаует ввод значений пользователем с клавиатуры
 * и с помощью введенных значений инциализирует объект
 * новый класса "Число" через конструктор с параметрами.
 * @return
 */
Number make_number() {
    float mantissa;
    int coefficient;
    string stringValue;

    cout << "\nВвод нового числа!\n\n";
    mantissa = getFloat("Введите мантиссу:", MIN_FLOAT, MAX_FLOAT);
    coefficient = getInt("Введите коэффициент: ", MIN_INT, MAX_INT);
    stringValue = getString("Введите строковое представление:");

    Number t(mantissa, coefficient, stringValue);

    return t;
}

/**
 * Функция вывода числа в консоль
 * @param t
 */
void print_number(Number t) {
    t.show();
}

int main() {
    //Конструктор без параметров
    Number n1;
    cout << endl << "Вывод полей числа n1, созданного конструктором без параметров:" << endl;
    n1.show();

    //Конструктор с параметрами
    Number n2(20.5, 5, "Двадцать с половиной!");
    cout << endl << "Вывод полей числа n2, созданного конструктором c параметрами (20.5, 5, \"Двадцать с половиной!\"):" << endl;
    n2.show();

    //Конструктор копирования
    Number n3 = n2;
    cout << endl << "Вывод полей числа n3, созданного конструктором копирования n3 = n2: " << endl;
    n3.show();
    n3.setMantissa(15.7);
    n3.setCoefficient(3);
    n3.setStringValue("Пятнадцать целых и семь десятых!");

    //Вывод числа
    cout << endl << "Вывод полей n3 через вызов функции print_number(n3) после установки новых значений: " << endl;
    print_number(n3);

    //Конструктор копирования через возвращаемое значение (конверсия)
    n1 = make_number();
    cout << endl << "Вывод полей n1 через вызов функции print_number(n1) после операции n1 = make_number();: " << endl;
    print_number(n1);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}