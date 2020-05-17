#ifndef LR_8_BOOK_H
#define LR_8_BOOK_H

#include "Print.h"

/**
 * Класс "Книга"
 */
class Book : public Print {
protected:
    int pageNumber;   //Кол-во страниц
    string publisher; //Издательство
public:
    //Конструкторы
    Book();
    Book(const string &title, const string &author, int pageNumbers, const string &publisher);
    Book(const Book & book);

    //Деструтор
    virtual ~Book();

    //Методы для чения и установки значения полей
    int getPageNumbers() const;
    void setPageNumbers(int pageNumber);
    const string &getPublisher() const;
    void setPublisher(const string &publisher);

    void Show() override;      //Метод вывода значний полей в консоль
    void Input() override;     //Метод ввода значний полей с консоли
    void ShowTitle() override;  //Метод вывода названия объекта
    void ShowType();        //Метод вывода названия класса объекта

    Book& operator=(const Book& book);  //перегрузка оператора присваивания
    void HandleEvent(const TEvent &e);  //Метод обработки событий
};


#endif //LR_8_BOOK_H
