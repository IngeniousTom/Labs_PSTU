#include "Print.h"
#include "iostream"

/**
 * Метод получения значния поля "название"
 * @return
 */
const string &Print::getTitle() const {
    return title;
}

/**
 * Метод установки значения поля "название"
 * @param name
 */
void Print::setTitle(const string &name) {
    Print::title = name;
}

/**
 * Метод получения значения поля "Автор"
 * @return
 */
const string &Print::getAuthor() const {
    return author;
}

/**
 * Метод установки значения поля "Автор"
 * @param author
 */
void Print::setAuthor(const string &author) {
    Print::author = author;
}

/**
 * Конструктор без параметров
 */
Print::Print() {
    title = "";
    author = "";
}

/**
 * Конструктор с параметрами
 * @param name
 * @param author
 */
Print::Print(string name, string author) {
    this->title = name;
    this->author = author;
}

/**
 * Конструктор копирования
 * @param print
 */
Print::Print(const Print &print) {
    this->title = print.title;
    this->author = print.author;
}

/**
 * деструктор
 */
Print::~Print(void) {}

/**
 * Перегрузка оператора присваивания.
 * Учитывает самоприсваивание.
 * @param print
 * @return
 */
Print &Print::operator=(const Print &print) {
    if(&print==this)return *this;
    this->title = print.title;
    this->author = print.author;
    return *this;
}

/**
 * Метод вывода значений полей в консоль
 */
void Print::Show() {
    cout << "Название: " << title << endl;
    cout << "Автор: " << author << endl;
}

/**
 * Метод ввода значений полей с консол
 */
void Print::Input() {
    title = getString("Введите название: ");
    author = getString("Введите автора: ");
}

/**
 * Вывод названия объекта
 */
void Print::ShowTitle() {
    cout << "Название: " << title << endl;
}

/**
 * Метод вывода названия класса объекта
 */
void Print::ShowType() {
    cout << "Тип объекта: \"Печатное издание\"" << endl;
}

/**
 * Метод обработки событий.
 * Принимает объект события в качестве параметра
 * и если событие находится в активно/не обработанном состоянии (событие-сообщени)
 * и если комманда в этом событии - это "Вывести аттрибут",
 * то выводит название и автора данного печатного издания
 * @param e
 */
void Print::HandleEvent(const TEvent &e) {
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

