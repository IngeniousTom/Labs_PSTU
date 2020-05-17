#ifndef LR_10_FILEWORK_H
#define LR_10_FILEWORK_H

#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Функция создания файла с указанным именем из элементов,
 * которые пользователь вводит с клавиатуры
 * @param f_name
 * @return
 */
int make_file(const char *f_name) {
    fstream stream(f_name, ios::out | ios::trunc); //открыть для записи
    if (!stream) return -1;//ошибка открытия файла

    int n;
    Time t;

    n = getInt("Введите количество элементов:", 1, MAX_INT);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ")" << endl;
        cin >> t;   //ввод атрибутов объекта из стандартного потока
        stream << t; //запись объекта в файловый поток
    }

    stream.close(); //закрыть поток
    return n;   //вернуть количество записанных объектов
}

/**
 * Функция печати объектов из указанного файла
 * @param f_name
 * @return
 */
int print_file(const char *f_name) {
    fstream stream(f_name, ios::in); //открыть для чтения
    if (!stream)return -1; //ошибка открытия файла

    Time t;
    int i = 0;

    while (stream >> t) {
        cout << i + 1 << ")" << endl << t << endl;
        i++;
    }

    stream.close();
    return i;
}

/**
 * Функция удаления диапазона временных интервалов из указанного файла
 * @param f_name
 * @param k1
 * @param k2
 * @return
 */
int del_from_file(const char *f_name, const Time &k1, const Time &k2) {
    fstream temp("temp", ios::out); //открыть для записи
    fstream stream(f_name, ios::in); //открыть для чтения

    if (!stream)return -1;//ошибка открытия файла

    int i = 0;
    Time t;

    while (stream >> t)//пока нет конца файла выполняем чтение объекта
    {
        //если прочитан признак конца файла,то выход из цикла
        if (stream.eof())break;
        //Если время из потока не лежит между k1 и k2, то записываем его во вспомогательый файл
        if (t < k1 || t > k2) temp << t;
    }

    //закрыть файлы
    stream.close();
    temp.close();
    remove(f_name); //удалить старый файл
    rename("temp", f_name); // переименовать temp
    return i;//количество прочитанных
}

/**
 * Функция добавления k новых элементов в файл с указанным именем
 * @param f_name
 * @param k
 * @return
 */
int add_beg(const char *f_name, int k) {
    fstream temp("temp", ios::out);  //открыть для записи
    fstream stream(f_name, ios::in);    //открыть для чтения
    if (!stream) return -1;     //ошибка открытия файла

    Time t;
    int l = 0;

    for (int i = 1; i <= k; i++) {
        Time tt;
        cout << i + 1 << ")" << endl;
        cin >> tt;
        temp << tt; //записать в temp новую запись
        l++;
    }
    while (stream >> t) {
        if (stream.eof()) break;
        temp << t;
    }

    stream.close();
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;   //количество добавленных
}

/**
 * Функция добавления 1 : 30 к временному интервалу в файле.
 * Поиск временного интервала осуществляется по значению tt.
 * Совпадающих записей может быть больше 1.
 * @param f_name
 * @param tt
 * @return
 */
int change_in_file(const char *f_name, Time tt) {
    fstream temp("temp", ios::out); //открыть для записи
    fstream stream(f_name, ios::in); //открыть для чтения
    if (!stream) return -1; //ошибка открытия файла

    Time t;
    Time t_plus(1, 30);
    int l = 0;
    char x;

    while (stream >> t) {
        if (stream.eof()) break;
        if (t == tt) {   //Если временной интервал найден по значению
            cout << t << " - будет увеличено на 1 : 30... Продолжить[y/n]?" << endl;
            cin >> x;   //Выбор пользователя
            if (x == 'n' || x == 'N') break;  //Если отказ то завершаем.
            temp << (t + t_plus);    //Прибавляем к найденному интервалу значение t_plus
            l++;
        } else temp << t;   //Запись в новый файл
    }
    stream.close();
    temp.close();
    remove(f_name); //Удаления старого файла с записями
    rename("temp", f_name);  //Сохранение нового файла под указанным именем. Происходит перезапись.
    return l;  //количество измененных элементов
}


#endif //LR_10_FILEWORK_H
