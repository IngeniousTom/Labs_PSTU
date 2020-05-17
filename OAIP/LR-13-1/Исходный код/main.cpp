#include "Time.h"
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef deque<Time> TDeq;  //Псевдоним типа для двусторонней очереди с пользовательским типом Time

Time s;  //Глобальное время s для работы с алгоритмами из библиотеки STL

/**
 * Функциональный объект - предикат
 * для проверки времени на равенство с глобальным временем s
 */
struct Equal_s {
    bool operator()(Time t) {
        return t == s;
    }
};

/**
 * Функция деления времени на глобальное время s
 * @param t
 */
void divide(Time &t) {
    t = t / s;
}

/**
 * Функция для прибавления к времени глобального времени s
 * @param t
 */
void append(Time &t) {
    t = t + s;
}

/**
 * Функция формирования двусторонней очереди
 * @param n
 * @return
 */
TDeq makeNew(int n) {
    Time a;
    TDeq d;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ")" << endl;
        cin >> a;
        d.push_back(a);
    }
    return d;
}

/**
 * Функция печати двусторонней очереди
 * @param d
 */
void print(const TDeq& d) {
    for (const auto &i : d)
        cout << i << endl;
    cout << endl;
}

/**
 * Функция для нахождения среднего арифметичекского
 * значения контейнера
 * @param d
 * @return
 */
Time avg(TDeq d) {
    Time t = d[0];
    //перебор контейнера
    for (int i = 1; i < d.size(); i++)
        t = t + d[i];
    int n = d.size();//количество элементов в контейнере
    return t / n;
}

/**
 * Функция для вставки максимального элемента в конец контейнера
 * @param d 
 * @param i 
 */
void insertMaxToTheEnd(TDeq &d) {
    TDeq::iterator i = max_element(d.begin(), d.end());
    cout << "\nМаксимальный элемент контейнера = " << *(i) << endl;
    //переместили элементы совпадающие с max в конец контейнера
    TDeq newDeq(d.size() + 1);
    replace_copy(d.begin(), d.end(), newDeq.begin(), *(d.end() - 1), *(d.end() - 1)); //копируем элементы в новый контейнер без изменений
    replace_copy(d.end()-1, d.end(), newDeq.end() - 1, *(d.end() - 1), *i);  //Добавляем найденный максимальный элемент в конец нового
    d = newDeq;
}

/**
 * Функция для удаления элемента по ключу(значению).
 * Удаляет все найденные по ключу значение элементы.
 * @param d 
 * @param i 
 * @param key 
 */
void eraseByKey(TDeq &d, const Time &key) {
    int deleted = 0;
    TDeq::iterator i = find(d.begin(), d.end(), key);
    while (i != d.end()) {
        s = *i;
        i = remove_if(d.begin(), d.end(), Equal_s());
        d.erase(i, d.end());
        deleted++;
        i = find(d.begin(), d.end(), key);
    }
    if (deleted == 0) {
        cout << "\nУказанного элемента не найдено в контейнере!" << endl;
    }
}

/**
 * Функция для увеличения всех элементов контейнера 
 * на их среднее арифместическое значение
 * @param d 
 */
void increaseByAvg(TDeq &d) {
    s = avg(d);
    cout << "\nСреднее арифметическое контейнера = " << s << endl;
    for_each(d.begin(), d.end(), append);
}

/**
 * Функция для удаления минимального элемента в конейнере
 * @param d
 */
void deleteMin(TDeq &d) {
    TDeq::iterator i = min_element(d.begin(), d.end());
    s = *i;
    //переместили элементы совпадающие с min в конец контейнера
    i = remove_if(d.begin(), d.end(), Equal_s());
    //удалили элементы, начиная с i и до конца контейнера
    d.erase(i, d.end());
}

/**
 * Функция для деления всех элементов конейнера на максимальное значение
 * @param d
 */
void divideByMax(TDeq &d) {
    TDeq::iterator i = max_element(d.begin(), d.end());
    s = *i;
    //для каждого элемента контейнера вызывается функция divide
    for_each(d.begin(), d.end(), divide);
}

/**
 * Главная функция
 * @return 
 */
int main() {
    //#1 #2 СОЗДАТЬ ПОСЛЕДОВАТЕЛЬНЫЙ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ ПОЛЬЗОВАТЕЛЬСКОГО ТИПА
    int n = getInt("Введите количество элементов контейнера:", MIN_INT, MAX_INT);

    TDeq d;
    d = makeNew(n);
    cout << endl << "\nВывод элементов контейнера после создания:" << endl;
    print(d);

    //#3 НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    insertMaxToTheEnd(d);
    cout << "\nВывод элементов контейнера после добавления максимального элемента в конец:" << endl;
    print(d);

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    Time key;
    cout << "\nВведите ключ элемента который нужно удалить:" << endl;
    cin >> key;

    eraseByKey(d, key);
    cout << endl << "\nВывод элементов контейнера после удаления элемента по ключу:" << endl;
    print(d);

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    increaseByAvg(d);
    cout << endl << "\nВывод элементов контейнера после увеличения всех элементов на среднее арифметическое контейнера:" << endl;
    print(d);

    //#6 УДАЛИТЬ МИНИМАЛЬНЫЙ ЭЛЕМЕНТ
    deleteMin(d);
    cout << "\nВывод элементов контейнера после удаления минимального элемента!" << endl;
    print(d);

    //#7 ДЕЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ НА МАКСИМАЛЬНЫЙ
    divideByMax(d);
    cout << "\nВывод элементов контейнера после деления всех элементов на максимальный!" << endl;
    print(d);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}