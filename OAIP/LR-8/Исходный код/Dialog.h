#ifndef LR_8_DIALOG_H
#define LR_8_DIALOG_H

#include "Vector.h"
#include "Event.h"

/**
 * Класс "Диалог"
 */
class Dialog : public Vector {
protected :
    int EndState;   //Состояние работы программы (0 - рабочее состояние / 1- завершение работы)
public :
    Dialog(void);   //контруктор
    virtual ~Dialog(void);  //деструктор
    virtual void GetEvent(TEvent &event);   //получить событие
    virtual int Execute();  //главный цикл обработки событий
    virtual void HandleEvent(TEvent &event); //обработчик
    virtual void ClearEvent(TEvent &event); //очистить событие
    int Valid();    // проверка атрибута EndState
    void EndExec(); //обработка события «конец работы»
};


#endif //LR_8_DIALOG_H
