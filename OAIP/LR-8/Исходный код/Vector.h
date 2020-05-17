#ifndef LR_8_VECTOR_H
#define LR_8_VECTOR_H

#include "Objecto.h"

using namespace std;

/**
 * Класс "Вектор"
 */
class Vector {
protected:
    Objecto **beg;  //указатель на первый элемент вектора
    int size;  //размер
    int cur;   //текущая позиция
public:
    Vector();  //Конструктор без параметров
    explicit Vector(int m); //конструктор с параметрами
    ~Vector();  //деструктор
    void Add(); //добавление элемента в вектор
    void Add(Objecto *p);   //добавление элемента в вектор
    void Del();   //Метод удаления элемента
    void Show();  //Метод вывода в консоль элементов вектора
    void ShowK(int k);  //Метод вывода в консоль элемента с номером k
    void ShowT(TEvent &event);   //Метод вывода типов и названия всех объеков группы
    int operator()();   //Размер вектора
    void HandleEvent(const TEvent &e);  //Метод обработки событий
    void MakeGroup(TEvent &event);

};


#endif //LR_8_VECTOR_H
