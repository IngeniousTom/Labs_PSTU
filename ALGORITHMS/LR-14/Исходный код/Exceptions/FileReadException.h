#ifndef LR_14_FILEREADEXCEPTION_H
#define LR_14_FILEREADEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Ошибка при чтении файла"
 */
class FileReadException : public Exception {
public :
    FileReadException() {
        msg = "Возникла ошибка при чтении указанного файла!";
    }
};

#endif //LR_14_FILEREADEXCEPTION_H
