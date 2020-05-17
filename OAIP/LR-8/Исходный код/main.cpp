#include <iostream>
#include "Print.h"
#include "Vector.h"
#include "Dialog.h"

using namespace std;

/**
 * Главная функция
 * @return
 */
int main() {
    //ДЕМОНСТРАЦИЯ РАБОТЫ МЕНЮ НА ОСНОВЕ СОБЫТИЙ
    Dialog d;
    d.Execute();

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();
    return 0;
}
