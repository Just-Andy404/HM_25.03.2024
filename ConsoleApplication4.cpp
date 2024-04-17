/*
Дан текстовый файл. Подсчитать количество символов в нем.
*/
#include <iostream>
#include <fstream>

using namespace std;

// Функция для подсчета символов в файле, исключая пробелы и знаки пунктуации
int countCharacters(const char* path) {
    ifstream file(path);
    char c;
    int count = 0;

    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла\n";
        return -1; // Возвращаем -1 в случае ошибки
    }

    while (file.get(c)) { // Читаем символ из файла
        if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') {
            continue;
        }
        ++count;
    }

    file.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char PATH[] = "data.txt"; // Относительный путь к файлу

    int result = countCharacters(PATH);
    if (result != -1) {
        cout << "Количество символов: " << result << endl;
    }

    return 0;
}
