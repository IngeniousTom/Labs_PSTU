#ifndef LR_14_DBCONNECTSYSTEM_H
#define LR_14_DBCONNECTSYSTEM_H


#include <cstdio>
#include <string>
#include "../structs.h"

#define FILE_EXT ".dat"

using namespace std;

/**
 * Класс "Файловая подсистема СУДБД"
 */
class DBConnectSystem {
private:
    FILE *file{};       //указатель связанный с файлом
    string fileName;    //Имя файла
    bool connected = false; //Признак успешно установленного соединения с файлом
public:
    DBConnectSystem();  //Конструктор без параметров
    virtual ~DBConnectSystem(); //Деструктор
    bool isConnected() const;  //Метод проверки соединения с БД
    string getFileNameWithExt(); //Метод получения полного имени файла с расширением
    void writeToFile(const LitList &list);  //Метода записи списка записей в файл БД
    void readFromFile(LitList &list);   //Метода чтения записей из файла БД в список
    void initializeConnection(const string &newfileName, bool fromEmptyFile);   //Метод установки соедниения с файлом БД с указанным именем
    void fillEntriesState(DBState &dbState);    //Метод заполнения структура данными о состоянии соединения с БД
    void disconnect();      //Метод отключения от текущего файла БД
};


#endif //LR_14_DBCONNECTSYSTEM_H
