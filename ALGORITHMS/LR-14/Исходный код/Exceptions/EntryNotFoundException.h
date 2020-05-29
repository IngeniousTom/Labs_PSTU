#ifndef LR_14_ENTRYNOTFOUNDEXCEPTION_H
#define LR_14_ENTRYNOTFOUNDEXCEPTION_H

#include "Exception.h"

using namespace std;

/**
 * Исключение типа "Запись не найдена"
 */
class EntryNotFoundException : public Exception {
public :
    EntryNotFoundException() {
        msg = "Указанная запись не найдена!";
    }
};

#endif //LR_14_ENTRYNOTFOUNDEXCEPTION_H
