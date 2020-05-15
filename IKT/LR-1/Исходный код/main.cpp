#include <iostream>
#include "Range.h"

#define MIN_VALUE 0    //Минимальное значение для ввода
#define MAX_VALUE 100  //Максимальное значение для ввода

using namespace std;

/**
 * Метод для создания диапазона значений.
 * Принимает параметры в качестве значений
 * границ данного диапазона. Если границы перепутаны местами,
 * то выводит соотвествующее сообщение и завершает работу.
 * @param left_
 * @param right_
 * @return
 */
Range make_range(double left_, double right_) {
    if (left_ < right_) {
        Range t;
        t.init(left_, right_);
        return t;
    } else {
        cout << "\nЛевая граница должна быть меньше правой!";
    }
}

/**
 * Главный метод.
 * @return
 */
int main() {
    //ВВОД ЧИСЛА ДЛЯ ПРОВЕРКИ НА ВХОЖДЕНИЕ В ДИАПАЗОНЫ
    double checkValue = getDouble(string_format("Введите вещественное число для проверки! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);

    //ОПРЕДЕЛЕНИЕ ДИАПАЗОНОВ ЧЕРЕЗ ПРОСТЫЕ ПЕРЕМЕННЫЕ
    Range a;
    Range b;

    //Создание диапазон через конструктор
    cout << endl << "\nВВОД ДИАПАЗОНА A:" << endl;
    double a_left, a_right;
    a_left = getDouble(string_format("Введите левую границу диапазона! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);
    a_right = getDouble(string_format("Введите правую границу диапазона! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);
    a.init(a_left, a_right);

    cout << endl << "\nВЫВОД ДИАПАЗОНА A:" << endl;
    a.show();
    a.rangeCheck(checkValue);

    //Создание диапазона через ввод с клаиватуры
    cout << endl << "\nВВОД ДИАПАЗОНА B:" << endl;
    b.read();
    cout << "\n\nВЫВОД ДИАПАЗОНА B:" << endl;
    b.show();
    b.rangeCheck(checkValue);

    //ОПРЕДЕЛЕНИЕ ДИАПАЗОНОВ ЧЕРЕЗ УКАЗАТЕЛИ
    cout << endl << endl << "\nДИАПАЗОН С:" << endl;
    Range * x = new Range();
    double x_left, x_right;

    x_left = getDouble(string_format("Введите левую границу диапазона! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);
    x_right = getDouble(string_format("Введите правую границу диапазона! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);

    x->init(x_left, x_right);
    x->show();
    x->rangeCheck(checkValue);

    //РАБОТА С МАССИВОМ ДИАПАЗОНОВ
    cout << endl << endl << "\nМАССИВ ДИАПАЗОНОВ D:";
    Range mas[3];
    cout << endl << "\nВвод";
    for (int i = 0; i < 3; i++) {
        cout << endl << i + 1 << " диапазон:" << endl;
        mas[i].read();
    }
    cout << endl << "\nВывод";
    for (int i = 0; i < 3; i++) {
        cout << endl << i + 1 << " диапазон:" << endl;
        mas[i].show();
    }
    cout << endl << "\nПроверка диапазонов";
    for (int i = 0; i < 3; i++) {
        cout << "\n\n" << i + 1 << " диапазон:" << endl;
        mas[i].rangeCheck(checkValue);
    }

    //РАБОТА С ДИАПАЗОНАМИ ЧЕРЕЗ ДИНАМИЧЕСКИЕ МАССИВЫ
    cout << endl << endl << "\nМАССИВ ДИАПАЗОНОВ E:";
    Range * p_mas = new Range[3];
    cout << endl << "\nВвод";
    for (int i = 0; i < 3; i++) {
        cout << endl << i + 1 << " диапазон:" << endl;
        p_mas[i].read();
    }
    cout << endl << "\nВывод";
    for (int i = 0; i < 3; i++) {
        cout << endl << i + 1 << " диапазон:" << endl;
        p_mas[i].show();
    }
    cout << endl << "\n\nПроверка диапазонов";
    for (int i = 0; i < 3; i++) {
        cout << endl << i + 1 << " диапазон:" << endl;
        p_mas[i].rangeCheck(checkValue);
    }

    //СОЗДАНИЕ ДИАПАЗОНА ЧЕРЕЗ ФУНКЦИЮ MAKE_RANGE()
    double r_left, r_right;
    cout << endl << endl << "\nДИАПАЗОН F:\n" << endl;
    r_left = getDouble(string_format("Введите левую границу диапазона! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);
    r_right = getDouble(string_format("Введите правую границу диапазона! (от %d до %d)", MIN_VALUE, MAX_VALUE), MIN_VALUE, MAX_VALUE);
    Range r = make_range(r_left, r_right);
    r.show();
    r.rangeCheck(checkValue);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}
