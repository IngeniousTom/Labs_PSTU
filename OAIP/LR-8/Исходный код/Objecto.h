#ifndef LR_8_OBJECTO_H
#define LR_8_OBJECTO_H


#include "Event.h"

/**
 * Базовый класс "Объект" иерархии классов,
 * обрабатывающих события
 */
class Objecto { //потому что Object - зарезервированное имя
public:
    Objecto();     //Конструктор без параметров

    virtual void Show() = 0;  //Абстрактный метод вывода всех атрибтов класса

    virtual void ShowTitle() = 0;  //Абстрактный метод вывода названия

    virtual void ShowType() = 0;  //Абстрактный метод вывода названия класса

    virtual void Input() = 0;    //Абстрактный метод ввода объекта с консоли

    virtual ~Objecto();     //Абстрактный деструктор

    virtual void HandleEvent(const TEvent &e) = 0;  //Абстрактный метод обработки событий
};


#endif //LR_8_OBJECTO_H
