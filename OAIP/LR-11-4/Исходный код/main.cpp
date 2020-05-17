#include <iostream>
#include <queue>
#include <vector>
#include "Time.h"

using namespace std;

typedef queue<Time> Que; //Псевдоним для очереди
typedef vector<Time> Vec; //Псевдоним для вспомогательного вектора

/**
 * Функция создания очереди из n элементов
 * @param n
 * @return
 */
Que makeQue(int n) {
    Que q;
    Time t;
    cout << "Введите элементы очереди:" << endl;
    for (int i = 0; i < n; i++) {
        cout << endl << i + 1 << ")" << endl;
        cin >> t;   //ввод переменной
        q.push(t);  //добавление ее в очередь
    }
    return q;   //вернуть очередь как результат функции
}


/**
 * Функция копирования очереди в вектор
 * @param q
 * @return
 */
Vec copyQueToVector(Que q) {
    Vec v;
    while (!q.empty()) {
        //Добавить в вектор элемент из вершиы очереди
        v.push_back(q.front());
        q.pop();
    }
    return v; //Вернуть вектор как результат функции
}

/**
 * Функция создания очереди из вектора
 * @param v
 * @return
 */
Que copyVectorToQue(const Vec& v) {
    Que q;
    for (auto & i : v) {
        q.push(i); //добавить в очередь элемент вектора
    }
    return q; //Вернуть очередь как результат функции
}

/**
 * Функция вывода элементов очереди в консоль
 * @param queue
 */
void printQue(Que queue) {
    Vec v = copyQueToVector(queue);
    for (int i = 0; i < v.size(); i++) {
        cout << endl << endl << i + 1 << ")" << endl;
        cout << v[i];
    }
    cout << endl;
}

/**
 * Функция вычисления среднего арифместического элементов очереди
 * @param q
 * @return
 */
Time Avg(Que q) {
    Vec v = copyQueToVector(q);//копируем очередь в вектор
    int n = 1;
    Time sum = q.front();//начальное значениедля суммы
    q.pop();//удалить первый элемент из вектора
    while (!q.empty()) {
        sum = sum + q.front();//добавить в сумму элемент из вершины очереди
        q.pop();//удалить элемент
        n++;
    }
    q = copyVectorToQue(v);//скопировать вектор в очередь
    return sum / n; //вернуть среднее арифметическое
}

/**
 * Функция добавления элемента в очередь на позицию pos
 * @param q
 * @param el
 * @param pos
 */
void AddToQue(Que &q, const Time& el, int pos) {
    if (pos < 1 || pos > q.size() + 1) {  //Если позиция за пределамидопустимого
        return;
    }
    if (pos == q.size() + 1) {    //Если вствка производится в конец
        q.push(el);
        return;
    }

    Vec v;
    Time t;
    int i = 1; //номер элемента в стеке
    while (!q.empty()) {
        t = q.front();
        //если номер равен номеру позиции, на котоую добвляем элемент
        if (i == pos) {
            v.push_back(el);   //добавить новый элемент в вектор
        }
        v.push_back(t);   //добавить элемент из очереди в вектор
        q.pop();    //удалить элемент из очереди
        i++;
    }
    q = copyVectorToQue(v); //копируем вектор в очередь
}

/**
 * Функция нахождения максимального элемента в очереди.
 * @param q
 * @return
 */
Time Max(Que q) {
    Time m = q.front(); //переменной m присваиваем значение из вершины очереди
    Vec v = copyQueToVector(q); //копируем очередь в вектор
    while (!q.empty()) {
        if (q.front() > m)m = q.front();    //срвниваем m и элемнт в вершине очереди
        q.pop(); //удаляем элемент из очереди
    }
    q = copyVectorToQue(v); //копиуем вектор в очередь
    return m; //возвращаем m
}

/**
 * Функция поиска элемента в очереди по ключу(значению)
 * @param q
 * @param key
 * @return
 */
Time FindByKey(Que q, Time &key) {
    while (!q.empty()) {
        if (q.front() == key) {
            return q.front(); //срвниваем tt и элемнт в вершине очереди
        }
        q.pop(); //удаляем элемент из очереди
    }
    return Time(-1, -1); //означает, что элемент не был найден
}

/**
 * Функция нахождения и вставки максимального элемента в конец
 * @param q
 */
void InsertMaxToTheEnd(Que &q) {
    Time m = Max(q);
    cout << endl  << endl << "Максимальный элемент очереди = " << m << endl;
    AddToQue(q, m, q.size() + 1);
}


/**
 * Функция удаления элемента из очереди по ключу
 * @param q
 * @param key
 */
void EraseByKey(Que &q, Time &key) {
    Time m = FindByKey(q, key);//находим элемент по ключу (значению)

    if (m == Time(-1, -1)) {
        cout << endl << "Элемент не был найден!" << endl;
    }

    Vec v;
    Time t;

    while (!q.empty()) {
        t = q.front();//получаем элемент из вершины очереди
        //Если он не равен найденному, заносим элемент в вектор
        if (t != m) v.push_back(t);
        q.pop();
    }

    q = copyVectorToQue(v); //копируем вектор в очередь
}

/**
 * Функция увеличения всех элементов очереди на их среднее арифместического значение
 * @param q
 */
void IncreaseByAvg(Que &q) {
    Time avg = Avg(q);
    cout << endl  << endl << "Среднее арифметическое элементов очереди = " << avg << endl;
    Vec v = copyQueToVector(q);
    Time t;
    for (auto & i : v) {
        i += avg;
    }
    q = copyVectorToQue(v);     //копируем вектор в очередь
}

/**
 * Главная функция
 * @return
 */
int main() {
    //#1 #2 СОЗДАТЬ ПАРАМЕТРИЗИРОВАННЫЙ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ ПОЛЬЗОВАТЕЛЬСКОГО ТИПА
    int n = getInt("Введите размер очереди:", 1, MAX_INT);

    Que que = makeQue(n);
    cout << "Вывод элементов очереди после создания:" << endl;
    printQue(que);

    //3# НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    InsertMaxToTheEnd(que);
    cout << "Вывод очереди после вставки максимального элемента в конец вектора:" << endl;
    printQue(que);

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    Time key;
    cout << endl << "Введите ключ элемента который нужно удалить:" << endl;
    cin >> key;

    EraseByKey(que, key); //удаление элемента;
    cout << endl << "Вывод элементов очереди после удаления элемента по ключу:" << endl;
    printQue(que);

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    IncreaseByAvg(que);
    cout << "Вывод элементов очереди после увеличения всех элементов на значение среднего арифметического:" << endl;
    printQue(que);

    cout << endl << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}
