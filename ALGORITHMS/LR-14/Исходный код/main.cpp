#include "Components/Dialog.h"
#include <iostream>

using namespace std;

/**
 * Главная функция
 * @return
 */
int main() {
    Dialog dialog;
    dialog.execute();  //Запуск диалога (меню СУБД)

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}