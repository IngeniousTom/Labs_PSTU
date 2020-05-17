#include <iostream>
#include "Vector.h"
#include "Time.h"

using namespace std;

/**
 * Главная функция
 * @return
 */
int main() {
    //#1 #2 СОЗДАТЬ ПАРАМЕТРИЗИРОВАННЫЙ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ ПОЛЬЗОВАТЕЛЬСКОГО ТИПА
    int n = getInt("Введите размер вектора:", 1, MAX_INT);
    
    cout << endl << string_format("Введите элементы вектора (%d штук)!", n) << endl << endl;
    Vector<Time> vec(n);    //создать вектор из n элементов
    cout << endl << "Вывод вектора после создания:" << endl;
    vec.Print();    //печать вектора

    //3# НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    vec.InsertMaxToTheEnd();
    cout << "Вывод вектора после вставки максимального элемента в конец вектора:" << endl;
    vec.Print();

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    Time key;
    cout << endl << "Введите ключ(значение) элемента который нужно удалить:" << endl;
    cin >> key;

    vec.EraseByKey(key); //удаление элемента;
    cout << endl << "Вывод элементов вектора после удаления элемента по ключу:" << endl;
    vec.Print();

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    vec.IncreaseByAvg();
    cout << "Вывод элементов вектора после увеличения всех элементов на значение среднего арифметического:" << endl;
    vec.Print();

    std::cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();
    return 0;
}