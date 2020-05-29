#ifndef LR_14_CONNECTEXCEPTION_H
#define LR_14_CONNECTEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Соединение не установлено"
 */
class ConnectException : public Exception {
public :
    ConnectException() {
        msg = "База данных не открыта, неоткуда брать данные и некуда сохранять!\n"
              "Откройте существующую базу данных или создайте новую!";
    }
};

#endif //LR_14_CONNECTEXCEPTION_H
