#ifndef LR_14_FILEWRITEEXCEPTION_H
#define LR_14_FILEWRITEEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Ошибка при записи в файл"
 */
class FileWriteException : public Exception {
public :
    FileWriteException() {
        msg = "Возникла ошибка при записи в указанный файл!";
    }
};

#endif //LR_14_FILEWRITEEXCEPTION_H
