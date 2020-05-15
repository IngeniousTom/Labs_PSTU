#include <iostream>
#include "Time.h"

/**
 * Функция сравнения времени.
 * Сравнивает временные интервалы и выводит знак
 * равенства или неравенства в консоль.
 * @param t1
 * @param t2
 */
void comapre_time(Time &t1, Time &t2) {
    cout << t1 << (t1 == t2 ? " == " : " != ") << t2 << endl;
}

/**
 * Главная функция
 * @return
 */
int main() {
    Time a;
    Time b(20, 40);
    Time c = b;
    Time d;

    cout << "Введите время а" << endl;
    cin >> a;

    cout << "\nВремя a: " << a << endl;

    cout << "\nВремя b: " << b << endl;

    cout << "\nВремя c(c = b): " << c << endl;

    cout << "\nВремя ++a: " << ++a << endl;

    cout << "\nВремя b++: " << b++ << endl;

    cout << "\nВремя c: " << c << endl;

    cout << "\nСравнение времени b и c:" << endl;
    comapre_time(b, c);

    d.setMin(50);
    d.setSec(10);
    cout << "\nВремя d: " << d << endl;

    cout << "Время d != a: " << ((d != a) ? "да" : "Нет") << endl;
	
	cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}
