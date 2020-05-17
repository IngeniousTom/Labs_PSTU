#include <iostream>
#include "Dialog.h"
#include "Print.h"

//Конструктор
Dialog::Dialog() {
    EndState = 0;  //Перевод объекта в рабочее состояние
}

//Деструктор
Dialog::~Dialog(void) {
}

/**
 * Метод получения события на основе выбора пользователем
 * комманд из меню.
 * @param event
 */
void Dialog::GetEvent(TEvent &event) {
    string OpInt = "m+-sztq"; //строка содержит коды операций
    string s;
    string param;

    char code;
    string title = "\n\nВведите код события: \n"
                   "m - Создать группу (формат: m 5, где 5 - размер группы)\n"
                   "+ - Добавит новый объект в группу\n"
                   "- - Удалить объект из группы\n"
                   "s - Вывести информацию об элементах группы\n"
                   "z - Вывести название элемента группы под номером k (формат: z 5, где 5 - номер элемента)\n"
                   "t - Вывести тип и название всех элементов группы\n"
                   "q - Выход!";
    s = getString(title);
    code = s[0]; //первый символ команды - это код
    if (OpInt.find(code) >= 0)  //является ли символ кодом операции
    {
        event.what = evMessage;
        switch (code) {
            case 'm':
                event.command = cmMake;
                break;  //Создать группу
            case '+':
                event.command = cmAdd;
                break;  //добавить объект в группу
            case '-':
                event.command = cmDel;
                break;  //удалить объект из группы
            case 's':
                event.command = cmShow;
                break;  //просмотр объектов в группе
            case 'z':
                event.command = cmShowK;
                break;  //просмотр названия элемента группы по номером к
            case 't':
                event.command = cmShowTT;
                break;  //просмотр названий всех элементов группы
            case 'q':
                event.command = cmQuit;
                break; //конец работы
            default:
                cout << "Такого варианта нет в меню!";
                event.what = evNothing;
        }
        //выделяем параметры команды, если они есть
        if (s.length() > 1) {
            param = s.substr(1, s.length() - 1);
            int A = atoi(param.c_str());//преобразуем парметр в число
            event.a = A;//записываем в сообщение
        } else {
            event.a = - 100;
        }
    } else {
        event.what = evNothing;// пустое событие
    }
}

/**
 * Метод - Основной цикл обработки.
 * @return
 */
int Dialog::Execute() {
    TEvent event;
    do {
        EndState = 0;   //Перевод объекта в рабочее состояние (нужно при первом запуске диалога)
        GetEvent(event); //получить событие
        HandleEvent(event); //обработать событие
    } while (!Valid());
    return EndState;
}

/**
 * Метод проверки необходимости продолжения
 * работы объекта. Т.е. в рабочем ли состоянии он находится.
 * @return
 */
int Dialog::Valid() {
    if (EndState == 0) return 0;
    else return 1;
}

/**
 * Метод перевода события в состоянии "обработано" / Пустое событие
 * @param event
 */
void Dialog::ClearEvent(TEvent &event) {
    event.what = evNothing; //пустое событие
}

/**
 * Метод завершения работы объекта "Диалог"
 */
void Dialog::EndExec() {
    EndState = 1;  //Перевод объекта в нерабочее состояние.
}

/**
 * Метод обрабатывает события.
 * Если событие находится в состоянии для чтения ("не обработано"),
 * то считывается код его команды и выполняется соотвествующее
 * действие менеджером БД, после чего событие приводится
 * в состояние "Не для чтения/Пропустить"
 * @param event
 */
void Dialog::HandleEvent(TEvent &event) {
    if (event.what == evMessage) {
        switch (event.command) {
            case cmMake: //создание группы
                MakeGroup(event);
                ClearEvent(event);//очищаем событие
                break;
            case cmAdd://добавление
                Add();
                ClearEvent(event);
                break;
            case cmDel:
                Del(); //удаление
                ClearEvent(event);
                break;
            case cmShow:
                Show(); //просмотр
                ClearEvent(event);
                break;
            case cmShowK:
                ShowK(event.a); //просмотр
                ClearEvent(event);
                break;
            case cmShowTT:
                ShowT(event); //просмотр
                ClearEvent(event);
                break;
            case cmQuit:
                EndExec(); //выход
                ClearEvent(event);
                break;
        }
    }
}

