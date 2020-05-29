#ifndef LR_14_RUNTIMEEXCEPTION_H
#define LR_14_RUNTIMEEXCEPTION_H

#include <string>
#include <stdexcept>

using namespace std;

/**
 * Исключение времени выполнения с произвольным сообщением
 */
class RuntimeException : public runtime_error {
protected :
    string msg;     //Текст сообщения
public :
    //Конструктор с параметром текста сообщения
    explicit RuntimeException(const string &arg) : runtime_error(arg) {
        msg = arg;
    }

    const char *what() const noexcept override {
        return msg.c_str();
    }
};

#endif //LR_14_RUNTIMEEXCEPTION_H
