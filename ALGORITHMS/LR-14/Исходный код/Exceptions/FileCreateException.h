#ifndef LR_14_FILECREATEEXCEPTION_H
#define LR_14_FILECREATEEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Не удалось создать файл"
 */
class FileCreateException : public Exception {
public :
    FileCreateException() {
        msg = "Возникла ошибка при создании указанного файла!";
    }
};

#endif //LR_14_FILECREATEEXCEPTION_H
