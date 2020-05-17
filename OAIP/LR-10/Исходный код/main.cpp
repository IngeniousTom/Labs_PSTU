#include <iostream>
#include "FileWork.h"

using namespace std;

/**
 * Главная функция
 * @return
 */
int main() {
    int returnValue; //Код результата работы программы
    int choice;  //Перемнная для хранения выбора пользователя
    char file_name[30];
    do {
        //МЕНЮ
        cout << endl;
        cout << endl << "1. Создать новый файл";
        cout << endl << "2. Вывести содержимое файла";
        cout << endl << "3. Удалить записи из файла";
        cout << endl << "4. Добавить записи в в начало файла";
        cout << endl << "5. Изменить записи в файле (увеличить на 1 : 30)";
        cout << endl << "0. Выход" << endl << endl;

        choice = getInt("> ", 0, 5);

        switch (choice) {
            case 1: {
                cout << "Введите имя файла:" << endl;
                cin >> file_name;
                returnValue = make_file(file_name);
                if (returnValue < 0) cout << "Не получилось создать файл!";
                break;
            }
            case 2: {
                cout << "Введите имя файла:" << endl;
                cin >> file_name;
                returnValue = print_file(file_name);
                if (returnValue == 0) cout << "Файл пуст!" << endl;
                if (returnValue < 0) cout << "Не получилось прочитать файл!" << endl;
                break;
            }
            case 3: {
                cout << "Введите имя файла:" << endl;
                cin >> file_name;
                cout << "Введите интервал времени в котором нужно удалить записи!" << endl;
                cout << "Левая граница интервала:" << endl;
                Time t1;
                cin >> t1;
                cout << "Правая граница интервала:" << endl;
                Time t2;
                cin >> t2;
                returnValue = del_from_file(file_name, t1, t2);
                if (returnValue < 0) cout << "Не получилось прочитать файл!";
                break;
            }
            case 4: {
                int amount;  //кол-во добавляемых записей
                cout << "Введите имя файла:" << endl;
                cin >> file_name;
                amount = getInt("Введите количество элементов:", 1, MAX_INT);
                returnValue = add_beg(file_name, amount);
                if (returnValue < 0) cout << "Не получилось прочитать файл!";
                break;
            }
            case 5:
                cout << "Введите имя файла:" << endl;
                cin >> file_name;
                cout << "Введите время которое нужно изменить:" << endl;
                Time tt;
                cin >> tt;
                returnValue = change_in_file(file_name, tt);
                if (returnValue < 0) cout << endl << "Не получилось прочитать файл!";
                if (returnValue == 0) cout << endl << "Не найдено такой записи";
                break;
        }
    } while (choice != 0);

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();
    return 0;
}
