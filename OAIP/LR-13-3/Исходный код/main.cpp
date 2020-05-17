#include "Time.h"
#include <iostream>
#include <algorithm>
#include "bits/stl_multimap.h"

using namespace std;

typedef multimap<string, Time> TMap;  //Псевдоним типа для контейнера с пользовательским типом Time
typedef vector<Time> TVec;

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
void divide(Time& t) {
    t = t / s;
}

/**
 * Функция для прибавления к времени глобального времени s
 * @param t
 */
void append(Time& t) {
    t += s;
}

/**
 * Функция формирования контейнера
 * @param n
 * @return
 */
TMap makeNew(int n) {
    string key;
    Time value;
    TMap m;
    for (int i = 0; i < n; i++) {
        cout << endl << i + 1 << ")" << endl;
        cout << "Ключ: ";
        key = getString("");
        cout << "Значение: \n";
        cin >> value;
        m.insert(make_pair(key, value));
    }
    return m;
}

/**
 * Функция печати контейнера
 * @param m
 */
void print(const TMap& m) {
    for (const auto & el : m) {
        cout << "Ключ: " << el.first << endl;
        cout << "Значение: " << el.second << endl;
        cout << endl;
    }
}

/**
 * Функция для нахождения среднего арифметичекского
 * значения элементов контейнера
 * @param m
 * @return
 */
Time avg(TMap m) {
    auto it = m.begin();
    Time t = (*it).second;
    ++it;
    //перебор контейнера
    while (it != m.end()) {
        t = t + (*it).second;;
        ++it;
    }
    int n = m.size(); //количество элементов в контейнере
    return t / n;
}


/**
 * Функция получения вектора из словаря
 * путем последовательного копирования
 * значений элементов словаря
 */
TVec getVectorFromMap(TMap &m) {
    TVec vec;
    for (const auto & el : m) {
        vec.emplace_back(el.second);
    }
    return vec;
}


/**
 * Функция для удаления из словаря тех элементов,
 * которые есть в векторе, но нет в словаре.
 * @param v
 * @param m
 */
void retainMapFromVector(TVec& v, TMap &m) {
    TMap newMap;
    auto it = m.begin();
    while (it != m.end()) {
        if (find(v.begin(), v.end(), (*it).second) != v.end()) {
            newMap.insert((*it));
        }
        ++it;
    }
    m = newMap;
}

/**
 * Функция для последовательного копирования
 * значений элементов вектора в элементы словаря.
 * Учитывает, что контейнеры могут быть разного размера.
 * @param v
 * @param m
 */
void copyVectorToMap(TVec& v, TMap &m) {
    int i = 0;
    auto it = m.begin();
    while (it != m.end() || i < v.size()) {
        (*it).second = v[i];
        it++;
        i++;
    }
}

/**
 * Функция для вставки максимального элемента в конец контейнера.
 * Находит максимальное значение среди элементов контейнера
 * и самый первый элемент с таким значением копирует в конец контейнера.
 * @param m 
 * @param i 
 */
void insertMaxToTheEnd(TMap &m) {
    auto temp = getVectorFromMap(m);
    auto i = max_element(temp.begin(), temp.end());

    cout << "\nМаксимальный элемент контейнера = " << *(i) << endl;

    pair<string , Time> newMax;
    for (auto & el : m) {
        if (el.second == (*i)) {
            newMax = pair<string, Time>(el);
            break;
        }
    }
    TMap newMap;
    //Чтобы элемент оказался в конце словаря нужно,
    //чтобы ключ нового элемента был больше, чем ключ последнего на данный момент
    newMax.first = (*(--m.end())).first + "2";
    newMap.insert(newMax);
    copy(--newMap.end(), newMap.end(), inserter(m, m.end()));
}

/**
 * Функция для удаления элемента по ключу.
 * @param m 
 * @param i 
 * @param key 
 */
void eraseByKey(TMap &m, const string &key) {
    auto i = m.find(key);
    if (i != m.end()) {
        m.erase(i);
    } else {
        cout << "\nУказанного элемента не найдено в контейнере!" << endl;
    }
}

/**
 * Функция для увеличения всех элементов контейнера 
 * на их среднее арифместическое значение
 * @param m 
 */
void increaseByAvg(TMap &m) {
    s = avg(m);
    cout << "\nСреднее арифметическое контейнера = " << s << endl;
    TVec temp = getVectorFromMap(m);
    for_each(temp.begin(), temp.end(), append);
    copyVectorToMap(temp, m);
}

/**
 * Функция для удаления минимального элемента в конейнере
 * @param m
 */
void deleteMin(TMap &m) {
    TVec temp = getVectorFromMap(m);
    auto i = min_element(temp.begin(), temp.end());
    s = (*i);
    //переместили элементы совпадающие с min в конец контейнера
    i = remove_if(temp.begin(), temp.end(), Equal_s());
    //удалили элементы, начиная с i и до конца контейнера
    temp.erase(i, temp.end());
    retainMapFromVector(temp, m);
}

/**
 * Функция для деления всех элементов конейнера на максимальное значение
 * @param m
 */
void divideByMax(TMap &m) {
    TVec temp = getVectorFromMap(m);
    auto i = max_element(temp.begin(), temp.end());
    s = (*i);
    for_each(temp.begin(), temp.end(), divide);
    copyVectorToMap(temp, m);
}

/**
 * Главная функция
 * @return 
 */
int main() {
    //#1 #2 СОЗДАТЬ ПОСЛЕДОВАТЕЛЬНЫЙ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ ПОЛЬЗОВАТЕЛЬСКОГО ТИПА
    int n = getInt("Введите количество элементов контейнера:", MIN_INT, MAX_INT);

    TMap m;
    m = makeNew(n);
    cout << endl << "\nВывод элементов контейнера после создания:" << endl;
    print(m);

    //#3 НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    insertMaxToTheEnd(m);
    cout << "\nВывод элементов контейнера после добавления максимального элемента в конец:" << endl;
    print(m);

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    string key = getString("\nВведите ключ элемента который нужно удалить:");

    eraseByKey(m, key);
    cout << endl << "\nВывод элементов контейнера после удаления элемента по ключу:" << endl;
    print(m);

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    increaseByAvg(m);
    cout << endl << "\nВывод элементов контейнера после увеличения всех элементов на среднее арифметическое контейнера:" << endl;
    print(m);

    //#6 УДАЛИТЬ МИНИМАЛЬНЫЙ ЭЛЕМЕНТ
    deleteMin(m);
    cout << "\nВывод элементов контейнера после удаления минимального элемента!" << endl;
    print(m);

    //#7 ДЕЛЕНИЕ ВСЕХ ЭЛЕМЕНТОВ НА МАКСИМАЛЬНЫЙ
    divideByMax(m);
    cout << "\nВывод элементов контейнера после деления всех элементов на максимальный!" << endl;
    print(m);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}