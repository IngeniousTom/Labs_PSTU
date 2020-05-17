#include <iostream>
#include <deque>
#include <cstdlib>
#include "myUtilities.h"

using namespace std;

typedef deque<int> Deq; //определяем тип для работы с очередью

/**
 * Функция для формирования очереди
 * @param n
 * @return
 */
Deq make_deque(int n) {
    Deq d;  //пустая очередь
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        int a = (rand() % 100 + 1) - 50;    //заполняется случайными числами
        d.push_back(a); //добавляем а в конец очереди
    }
    return d; //возвращаем очередь как результа работы функции
}


/**
 * Функция для печати очереди
 * @param d
 */
void print_deque(const Deq &d) {
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;
}

/**
 * Функция вставки элемента в очередь на определенную позицию
 * @param d
 * @param el
 * @param pos
 */
void add_deque(Deq &d, int el, int pos) {
    //добавляем на место pos элемент el
    d.insert(d.begin() + pos, el);
}

/**
 * Функция поиска максимального элемента
 * @param d
 * @return
 */
int max(Deq d) {
    int max = d[0]; //максимальный элемент
    for (int i : d) {
        if (i > max) {
            max = i;  //максимальный элемент
        }
    }
    return max;
}

/**
 * Функция поиска среднего арифместического элементов очереди
 * @param d
 * @return
 */
int avg(const Deq &d) {
    int s = 0; //перебор очереди
    for (int i : d) {
        s += i;
    }
    //количество элементов в очереди
    return s / d.size();
}

/**
 * Функция вставки максимального элемента в конец очереди
 * @param deq
 */
void insertMaxToTheEnd(Deq &deq) {
    int m = max(deq);
    cout << endl << "Максимальный элемент очереди = " << m << endl;
    deq.insert(deq.begin() + deq.size(), m);
}

/**
 * Функция удаления элемента по ключу(значению).
 * Удаляет столько значений, сколько соотвествует переданному key;
 * @param d
 * @param key
 */
void eraseByKey(Deq &d, int key) {
    Deq newDeq;  //новая очередь
    int ni = 0;
    for (int &i : d) {
        if (i != key) {
            newDeq.insert(newDeq.begin() + ni, i);  //Если элементы не совпадают с искомым то добавляем их в новый контейнер
            ni++;
        }
    }
    if (ni == d.size()) { //Проверяем, был ли удален хоть один элемент
        cout << "Элемент не был найден!" << endl;
        return;
    }
    d = newDeq;
}

/**
 * Функция увеличения значений элементов на их среднее арифместическое.
 * @param deq
 */
void increaseByAvg(Deq &deq) {
    int a = avg(deq);
    cout << endl << "Среднее арифметическое элементов очереди = " << a << endl;
    for (int &i : deq) {
        i += a;
    }
}

/**
 * Главная функция
 * @return
 */
int main() {
    Deq d;

    //#1 #2 СОЗДАТЬ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ
    int n = getInt("Введите размер очереди:", 1, MAX_INT);

    d = make_deque(n); //Формирование очереди

    cout << "Вывод очереди после создания:" << endl;
    print_deque(d); //печать очереди

    //3# НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    insertMaxToTheEnd(d);
    cout << endl << "Вывод очереди после вставки максимального элемента в конец очереди:" << endl;
    print_deque(d);

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    int key = getInt("\nВведите ключ элемента который нужно удалить:", MIN_INT, MAX_INT);

    eraseByKey(d, key); //удаление элемента;
    cout << endl << "Вывод элементов словаря после удаления элемента по ключу:" << endl;
    print_deque(d); //печать очереди

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    increaseByAvg(d);
    cout << "Вывод элементов словаря после увеличения всех элементов на значение среднего арифметического:" << endl;
    print_deque(d);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();
}
