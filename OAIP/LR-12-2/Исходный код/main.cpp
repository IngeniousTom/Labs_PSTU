#include <iostream>
#include <map>
#include "Time.h"

using namespace std;

typedef map<int, Time> TMap;//определяем тип для работы со словаре
typedef TMap::iterator It;

/**
 * Функция для формирования словаря
 * @param n
 * @return
 */
TMap makeMap(int n) {
    int key;
    Time value;
    TMap m;

    cout << "Введите элементы словаря:" << endl;

    for (int i = 0; i < n; i++) {
        cout << endl << i + 1 << ")" << endl;
        key = getInt("\"Ключ:", MIN_INT, MAX_INT);
        cout << "Значение:" << endl;
        cin >> value;
        m.insert(make_pair(key, value));
    }

    return m;
}

/**
 * Функция для печати словаря
 * @param m
 */
void printMap(TMap m) {
    It it = m.begin();
    int i = 1;
    while (it != m.end()) {
        cout << endl << "Ключ: " << it->first;
        cout << endl << "Значение: " << endl;
        cout << it->second;
        cout << endl;
        it++;
    }
}

/**
 * Вычисление среднего арифметического значения элементов контейнера
 * @param m
 * @return
 */
Time Avg(TMap m) {
    Time s = Time(0, 0);
    //перебор словаря
    It it = m.begin();
    while (it != m.end()) {
        s += it->second;
        it++;
    }
    int n = m.size(); //количество элементов в словаре
    return s / n;
}

/**
 * Функция нахождения максимального элемента в очереди.
 * @param m
 * @return
 */
Time Max(TMap m) {
    It i = m.begin();
    Time max = (*i).second; //значение первого элемента
    while (i != m.end()) {
        if (max < (*i).second) {
            max = (*i).second;
        }
        i++; //итератор
    }
    return max; //max
}

/**
 * Функция увеличения всех элементов словаря на их среднее арифместического значение
 * @param m
 */
void IncreaseByAvg(TMap &m) {
    Time avg = Avg(m); //значение минимального элемента
    cout << endl << "Среднее арифметическое элементов словаря = " << avg << endl;
    It it = m.begin();
    while (it != m.end()) {
        m[it->first] += avg;
        it++;
    }
}
/**
 * Функция нахождения и вставки максимального элемента в конец
 * @param n
 * @param m
 */
void InsertMaxToTheEnd(TMap &m) {
    Time max = Max(m);
    cout << endl << "Максимальное значение элементов словаря = " << max << endl;

    pair<int , Time> newMax;
    for (auto & el : m) {
        if (el.second == max) {
            newMax = pair<int, Time>(el);
            break;
        }
    }

    //Чтобы элемент оказался в конце словаря нужно,
    //чтобы ключ нового элемента был больше, чем ключ последнего на данный момент
    newMax.first = (*(--m.end())).first + 1;
    m.insert(m.end(), newMax);
}

/**
 * Функция удаления элемента из словаря по ключу
 * @param map
 * @param key
 */
void eraseByKey(TMap &map, int key) {
    unsigned long erased = map.erase(key); //удаление элемента;
    if (erased < 1) {
        cout << "Элемент не был найден!" << endl;
    }
}

/**
 * Главная функция
 * @return
 */
int main() {
    //#1 #2 СОЗДАТЬ ПАРАМЕТРИЗИРОВАННЫЙ КОНТЕЙНЕР И ЗАПОЛНИТЬ ЕГО ЭЛЕМЕНТАМИ ПОЛЬЗОВАТЕЛЬСКОГО ТИПА
    int n = getInt("Введите размер очереди:", 1, MAX_INT);

    TMap map = makeMap(n);
    cout << endl << "Вывод элементов словаря после создания:" << endl;
    printMap(map);

    //3# НАЙТИ МАКСИМАЛЬНЫЙ ЭЛЕМЕНТ И ДОБАВИТЬ ЕГО В КОНЕЦ КОНТЕЙНЕРА
    InsertMaxToTheEnd(map);
    cout << endl << "Вывод элементов словаря после добавления максимального элемента в конец:" << endl;
    printMap(map);

    //#4 НАЙТИ ЭЛЕМЕНТ С ЗАДАННЫМ КЛЮЧОМ И УДАЛИТЬ ЕГО ИЗ КОНТЕЙНЕРА
    int key = getInt("\nВведите ключ элемента который нужно удалить:", MIN_INT, MAX_INT);

    eraseByKey(map, key);
    cout << endl << "Вывод элементов словаря после удаления элемента по ключу:" << endl;
    printMap(map);

    //#5 К КАЖДОМУ ЭЛЕМЕНТУ ДОБАВИТЬ СРЕДНЕЕ АРИФМЕТИЧЕСКОЕ ЭЛЕМЕНТОВ КОНТЕЙНЕРА
    IncreaseByAvg(map);
    cout << endl << "Вывод элементов словаря после увеличения всех элементов на значение среднего арифметического:" << endl;
    printMap(map);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}