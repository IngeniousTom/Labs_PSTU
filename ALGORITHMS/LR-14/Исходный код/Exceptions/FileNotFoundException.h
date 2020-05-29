#ifndef LR_14_FILENOTFOUNDEXCEPTION_H
#define LR_14_FILENOTFOUNDEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Файла с данным именем не сущесвтует"
 */
class FileNotFoundException : public Exception {
public :
    FileNotFoundException() {
        msg = "Файла с данным именем не сущесвтует!";
    }
};

#endif //LR_14_FILENOTFOUNDEXCEPTION_H
