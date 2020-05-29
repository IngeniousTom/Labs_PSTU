#include "DBConnectSystem.h"
#include "../Exceptions/FileNotFoundException.h"
#include "../Exceptions/FileCreateException.h"
#include "../Exceptions/FileWriteException.h"
#include "../Exceptions/FileOpenException.h"
#include "../Exceptions/FileReadException.h"
#include <unistd.h>

/**
 * Конструктор без параметров
 */
DBConnectSystem::DBConnectSystem() = default;

/**
 * Деструктор
 */
DBConnectSystem::~DBConnectSystem() = default;

/**
 * Метод проверки соединения с БД
 * @return
 */
bool DBConnectSystem::isConnected() const {
    return connected;
}

/**
 * Метод получения полного имени файла с расширением
 * @return
 */
string DBConnectSystem::getFileNameWithExt() {
    return (fileName + FILE_EXT);
}

/**
 * Метод отключения СУБД от текущего файла БД
 */
void DBConnectSystem::disconnect() {
    connected = false;
    fileName.clear();
}

/**
 * Метода записи списка записей в файл БД
 * @param list
 */
void DBConnectSystem::writeToFile(const LitList &list) {
    file = fopen(getFileNameWithExt().c_str(), "wb");

    if (file == nullptr) {
        throw FileCreateException();
    }

    //Отправка записей из списка в файл БД
    for (Liter entry : list) {
        fwrite(&entry, sizeof(struct Literature), 1, file);

        if (ferror(file)) {
            throw FileWriteException();
        }
    }

    fclose(file);
}

/**
 * Метода чтения записей из файла БД в список
 * @param list
 */
void DBConnectSystem::readFromFile(LitList &list) { //чтение записей из файла
    if (access(getFileNameWithExt().c_str(), F_OK) == -1) {
        disconnect();
        throw FileNotFoundException();
    }

    file = fopen(getFileNameWithExt().c_str(), "rb");

    if (file == nullptr) {
        throw FileOpenException();
    }

    Liter temp;
    list.clear();

    int i = 0;

    //вставка записей из файла в список
    while (i < MAX_ENTRIES_NUMBER) {
        if (fread(&temp, sizeof(struct Literature), 1, file) == 1) {
            list.push_back(temp);
            i++;
        } else if (feof(file)) {
            break;
        } else {
            throw FileReadException();
        }
    }

    fclose(file);
}

/**
 * Метод установки соедниения с файлом БД с указанным именем
 * @param newfileName
 * @param fromEmptyFile
 */
void DBConnectSystem::initializeConnection(const string &newfileName, bool fromEmptyFile) {
    if (!fromEmptyFile && access((newfileName + FILE_EXT).c_str(), F_OK) == -1) {
        throw FileNotFoundException();
    }
    this->fileName = newfileName;
    connected = true;
}

/**
 * Метод заполнения структуры "Состояние СУБД" данными о состоянии соединения с БД
 * @param dbState
 */
void DBConnectSystem::fillEntriesState(DBState &dbState) {
    dbState.connected = connected;
}