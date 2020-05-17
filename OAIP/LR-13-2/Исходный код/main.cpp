#include "Time.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef queue<Time> TQue;  //Псевдоним типа для очереди с пользовательским типом Time
typedef vector<Time> TVec; //Псевдоним типа для контейнера с пользовательским типом Time

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
 * Функция для создания вектора из очереди.
 * Необъодима, т.к. алгоритмы библиотеки STL
 * не работают с многими адаптерами контейнеров
 * @param q
 * @return
 */
TVec getVectorFromQueue(const TQue& q) {
    TQue newQue(q);
    TVec vector;
    while (!newQue.empty()) {
        vector.emplace_back(newQue.front());
        newQue.pop();
    }
    return vector;
}

/**
 * Функция копирования элементов вектора в очередь.
 * @param v 
 * @param q 
 */
void copyVectorToQue(const TVec& v, TQue &q) {
    TQue newQue;
    for (auto & el : v) {
        newQue.push(el);
    }
    q = newQue;
}

/**
 * Функция формирования контейнера
 * @param n
 * @return
 */
TQue makeNew(int n) {
    Time a;
    TQue q;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ")" << endl;
        cin >> a;
        q.push(a);
    }
    return q;
}

/**
 * Функция печати контейнера
 * @param q
 */
void print(const TQue& q) {
    TQue temp(q);
    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }
    cout << endl;
}

/**
 * Функция для нахождения среднего арифметичекского
 * значения контейнера
 * @param q
 * @return
 */
Time avg(const TQue& q) {
    Time t = q.front();
    TQue temp(q);
    //перебор контейнера
    while (!temp.empty()) {
        t = t + temp.front();
        temp.pop();
    }
    int n = q.size();     //количество элементов в контейнере
    return t / n;
}

/**
 * Функция для вставки максимального элемента в конец контейнера
 * @param q 
 * @param i 
 */
void insertMaxToTheEnd(TQue &q) {
    TVec temp = getVectorFromQueue(q);
    TVec::iterator i = max_element(temp.begin(), temp.end());

    cout << "\nМаксимальный элемент контейнера = " << *(i) << endl;

    TVec newVec(temp.size() + 1);
    replace_copy(temp.begin(), temp.end(), newVec.begin(), *(temp.end() - 1), *(temp.end() - 1)); //копируем элементы в новый контейнер без изменений
    replace_copy(temp.end()-1, temp.end(), newVec.end() - 1, *(temp.end() - 1), *i);  //Добавляем найденный максимальный элемент в конец нового
    copyVectorToQue(newVec, q);
}

/**
 * Функция для удаления элемента по ключу(значению).
 * Удаляет все найденные по ключу значение элементы.
 * @param q 
 * @param i 
 * @param key 
 */
void eraseByKey(TQue &q, const Time &key) {
    int deleted = 0;
    TVec temp = getVectorFromQueue(q);
    TVec::iterator i = find(temp.begin(), temp.end(), key);
    while (i != temp.end()) {
        s = *i;
        i = remove_if(temp.begin(), temp.end(), Equal_s());
        temp.erase(i, temp.end());
        deleted++;
        i = find(temp.begin(), temp.end(), key);
    }
    copyVectorToQue(temp, q);
    if (deleted == 0) {
        cout << "\nУказанного элемента не найдено в контейнере!" << endl;
    }
}

/**
 * Функция для увеличения всех элементов контейнера 
 * на их среднее арифместическое значение
 * @param q 
 */
void increaseByAvg(TQue &q) {
    s = avg(q);
    TVec temp = getVectorFromQueue(q);
    cout << "\nСреднее арифметическое контейнера = " << s << endl;
    for_each(temp.begin(), temp.end(), append);
    copyVectorToQue(temp, q);
}

/**
 * Функция для удаления минимального элемента в конейнере
 * @param q
 */
void deleteMin(TQue &q) {
    TVec temp = getVectorFromQueue(q);
    TVec::iterator i = min_element(temp.begin(), temp.end());
    s = *i;
    //переместили элементы совпадающие с min в конец контейнера
    i = remove_if(temp.begin(), temp.end(), Equal_s());
    //удалили элементы, начиная с i и до конца контейнера
    temp.erase(i, temp.end());
    copyVectorToQue(temp, q);
}

/**
 * Функция для деления всех элементов конейнера на максимальное значение
 * @param q
 */
void divideByMax(TQue &q) {
    TVec temp = getVectorFromQueue(q);
    TVec::iterator i = max_element(temp.begin(), temp.end());
    s = *i;
    //для каждого элемента контейнера вызывается функция divide
    for_each(temp.begin(), temp.end(), divide);
    copyVectorToQue(temp, q);
}

/**
 * Главная функция
 * @return 
 */
int main() {
    //#1 #2 СОЗДАТЬ ПОСЛЕДОВАТЕЛЬНЫЙ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ ПОЛЬЗОВАТЕЛЬСКОГО ТИПА
    int n = getInt("Введите количество элементов контейнера:", MIN_INT, MAX_INT);

    TQue q;
    q = makeNew(n);
    cout << endl << "\nВывод элементов контейнера после создания:" << endl;
    print(q);

    //#3 НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    insertMaxToTheEnd(q);
    cout << "\nВывод элементов контейнера после добавления максимального элемента в конец:" << endl;
    print(q);

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    Time key;
    cout << "\nВведите ключ элемента который нужно удалить:" << endl;
    cin >> key;

    eraseByKey(q, key);
    cout << endl << "\nВывод элементов контейнера после удаления элемента по ключу:" << endl;
    print(q);

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    increaseByAvg(q);
    cout << endl << "\nВывод элементов контейнера после увеличения всех элементов на среднее арифметическое контейнера:" << endl;
    print(q);

    //#6 УДАЛИТЬ МИНИМАЛЬНЫЙ ЭЛЕМЕНТ
    deleteMin(q);
    cout << "\nВывод элементов контейнера после удаления минимального элемента!" << endl;
    print(q);

    //#7 ДЕЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ НА МАКСИМАЛЬНЫЙ
    divideByMax(q);
    cout << "\nВывод элементов контейнера после деления всех элементов на максимальный!" << endl;
    print(q);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}