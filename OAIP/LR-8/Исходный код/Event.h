#ifndef LR_8_EVENT_H
#define LR_8_EVENT_H

#pragma once

const int evNothing=0; //пустое событие
const int evMessage=100; //непустое событие
const int cmAdd=1; //добавить объект в группу
const int cmDel=2; //удалить объект из группы
const int cmShow=3; //вывести всю группу
const int cmShowK=4; //вывести элемент с номером k
const int cmMake=5; //создать группу
const int cmShowTT=6; //создать группу
const int cmQuit=101; //выход


/**
 * Структура "Событие"
 */
struct TEvent
{
    int what;  //тип события
    union
    {
        int command; //код команды

        struct
        {
            int message; //сообщение
            int a;   //параметр команды, -100 означает, что параметр не задан
        };
    };
};

#endif //LR_8_EVENT_H
