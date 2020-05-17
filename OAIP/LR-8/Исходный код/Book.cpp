#include <iostream>
#include "Book.h"

/**
 * Конструктор без параметров
 */
Book::Book() {}

/**
 * Конструктор с параметрами.
 * @param name
 * @param author
 * @param pageNumbers
 * @param publisher
 */
Book::Book(const string &name, const string &author, int pageNumbers, const string &publisher) : Print(title, author) {
    this->pageNumber = pageNumbers;
    this->publisher = publisher;
}

/**
 * Конструктор копирования
 * @param book
 */
Book::Book(const Book &book) : Print(book) {
    this->pageNumber = book.pageNumber;
    this->publisher = book.publisher;
}

/**
 * Деструктор
 */
Book::~Book() {}

/**
 * Метод получениея значения поля кол-ва страниц
 * @return
 */
int Book::getPageNumbers() const {
    return pageNumber;
}

/**
 * Метод установки значения поля кол-ва страниц
 * @param pageNumber
 */
void Book::setPageNumbers(int pageNumber) {
    Book::pageNumber = pageNumber;
}

/**
 * Метод получениея значения поля "Издательство"
 * @return
 */
const string &Book::getPublisher() const {
    return publisher;
}

/**
 * Метод установки значения поля "Издательство"
 * @param publisher
 */
void Book::setPublisher(const string &publisher) {
    Book::publisher = publisher;
}

/**
 * Метод вывода значний полей в консоль
 */
void Book::Show() {
    cout << "Название: " << title << endl;
    cout << "Автор: " << author << endl;
    cout << "Количество страниц: " << pageNumber << endl;
    cout << "Издательство: " << publisher << endl;
    cout << endl;
}

/**
 * Метод вывода названия объекта
 */
void Book::ShowTitle() {

    cout << "Название: " << title << endl;
}

/**
 * Метод вывода названия класса объекта
 */
void Book::ShowType() {
    cout << "Тип объекта: \"Книга\"" << endl;
}

/**
 * Метод ввода значний полей с консоли
 */
void Book::Input() {
    title = getString("Введите название: ");
    author = getString("Введите автора: ");
    pageNumber = getInt("Количество страниц: ", 1, MAX_INT);
    publisher = getString("Издательство: ");
    cout << endl;
}

/**
 * Перегрузка оператора присваивания.
 * Учитывает самоприсваивание.
 * @param book
 * @return
 */
Book &Book::operator=(const Book &book) {
    if (&book == this)return *this;
    this->title = book.title;
    this->author = book.author;
    this->pageNumber = book.pageNumber;
    this->publisher = book.publisher;
    return *this;
}

/**
 * Метод обработки событий.
 * Принимает объект события в качестве параметра
 * и если событие находится в активно/не обработанном состоянии (событие-сообщени)
 * и если комманда в этом событии - это "Вывести аттрибут",
 * то выводит количество страниц и название издательства
 * @param e
 */
void Book::HandleEvent(const TEvent &e) {
    if (e.what == evMessage)  //событие-сообщение
    {
        switch (e.command) {
            case cmShowTT:
                ShowType();
                ShowTitle();
                cout << endl;
                break;
        }
    }
}

