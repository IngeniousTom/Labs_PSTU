#ifndef LR_14_FILEOPENEXCEPTION_H
#define LR_14_FILEOPENEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Ошибка при открытии файла"
 */
class FileOpenException : public Exception {
public :
    FileOpenException() {
        msg = "Возникла ошибка при открытии указанного файла!";
    }
};

#endif //LR_14_FILEOPENEXCEPTION_H
