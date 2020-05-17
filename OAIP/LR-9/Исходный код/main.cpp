#include <iostream>
#include "Vector.h"
#include "Error.h"

/**
 * Главная функция
 */
int main() {
    try {
        Vector x(0);

        cout << "Вывод вектора x (Vector x(2)): " << endl;
        cout << x;

        int i = getInt("\nВведите индекс искомого элемента: ", MIN_INT, MAX_INT);

        cout << endl << "Вывод элемента вектора x с указанным индексом: " << endl;
        cout << x[i] << endl;

        Vector y;
        y = x + 3;
        cout << endl << "Вывод вектора y после операции y = x + 3: " << endl;
        cout << y << endl;

        //Проверяем работу операторов префиксного и постфиксного операторов --
        cout << "\nВывод значения выражения --y: " << --y << endl;

        cout << "\nВывод значения выражения y--: " << y-- << endl;

        cout << "\nВывод значения выражения --y: " << --y << endl;

        cout << "\nРазмер вектора y = " << y() << endl << endl;

        //Провоцируем исключение типа EmptySizeError
        cout << "\nПопытка произвести операцию --y:" << endl;
        --y;
    } catch (Error &e) {
        e.what();
    }

    try {
        cout << endl << "Попытка создать вектор a(21):" << endl;
        Vector a(21);
    } catch (Error &e) {
        e.what();
    }

    try {
        cout << endl << "Cоздаем вектор a(20):" << endl;
        Vector a(20);

        cout << "Попытка провести операцию a = a + 1:" << endl;
        a = a + 1;
    } catch (Error &e) {
        e.what();
    }

    try {
        cout << endl << "Cоздаем вектор a(5):" << endl;
        Vector a(5);

        cout << "Попытка получить элемент a[-1]:" << endl;
        a[-1];
    } catch (Error &e) {
        e.what();
    }

    try {
        cout << endl << "Cоздаем вектор a(5):" << endl;
        Vector a(5);

        cout << "Попытка получить элемент a[6]:" << endl;
        a[6];
    } catch (Error &e) {
        e.what();
    }
	
	cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();
    return 0;
}
