#ifndef LR_8_PRINT_H
#define LR_8_PRINT_H

#include <string>
#include "Objecto.h"
#include "myUtilities.h"

#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

using namespace std;

/**
 * Класс "Печатное издание"
 */
class Print : public Objecto {
protected:
    string title;     //Название
    string author;    //Автор
public:
    Print(void);      //конструктор без параметров
    Print(string title, string author);  //конструктор с параметрами
    Print(const Print & print);     //конструктор копирования
    ~Print(void) override;       //деструктор

    //Методы для чения и установки значения полей
    const string &getTitle() const;
    void setTitle(const string &title);
    const string &getAuthor() const;
    void setAuthor(const string &author);

    void Show() override;   //Метод вывода значений полей в консоль
    void Input() override;  //Метод ввода значений полей с консоли
    void ShowTitle() override;  //Вывод названия объекта
    void ShowType();    //Метод вывода названия класса объекта

    Print& operator=(const Print& print);  //перегрузка оператора присваивания
    void HandleEvent( const TEvent &e);   //Метод обработки событий
};


#endif //LR_8_PRINT_H