#ifndef LR_14_WRONGPOSITIONEXCEPTION_H
#define LR_14_WRONGPOSITIONEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Недопустимая позиция для данного действия"
 */
class WrongPositionException : public Exception {
public :
    WrongPositionException() {
        msg = "Нельзя выполнить действие с данной позиции!";
    }
};

#endif //LR_14_WRONGPOSITIONEXCEPTION_H
