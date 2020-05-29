#ifndef LR_14_EXCEPTION_H
#define LR_14_EXCEPTION_H

#include <string>

using namespace std;

/**
 * Базовый класс исключения
 */
class Exception : public exception {
protected :
    string msg;  //Сообщение исключения
public :
    Exception() {
        msg = "Возникла ошибка в ходе работы программы!";
    }

    //Метод получения сообщения исключения
    const char *what() const noexcept override {
        return msg.c_str();
    }
};

#endif //LR_14_EXCEPTION_H
