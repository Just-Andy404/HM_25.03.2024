/*
Дан текстовый файл. Подсчитать количество строк в нем.
*/
#include <iostream>
#include <fstream>

using namespace std;

// Функция для подсчета строк в файле
int countLines(const char* filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла\n";
        return -1; // Возвращаем -1 в случае ошибки
    }

    char line[1024]; // Массив для хранения строки
    int count = 0;
    bool isEmpty = true;

    while (file.getline(line, sizeof(line))) {
        int i = 0;
        isEmpty = true; // Предполагаем, что строка пуста

        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '.' && line[i] != '?') {
                isEmpty = false; // Строка содержит символы, не являющиеся пробелами или знаками пунктуации
                break;
            }
            i++;
        }

        if (!isEmpty) {
            count++; // Учитываем строку, если она не пуста
        }
    }

    file.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char PATH[] = "data.txt"; // Относительный путь к файлу

    int result = countLines(PATH);
    if (result != -1) {
        cout << "Количество строк: " << result << endl;
    }

    return 0;
}
