/*
Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задает пользователь.
*/
#include <iostream>
#include <fstream>
using namespace std;

// Функция для подсчета слов, начинающихся с заданного символа
int countWordsStartingWith(const char* path, char targetChar) {
    ifstream file(path);
    char c;
    int count = 0;
    bool isSpace = true; // предполагаем, что перед первым символом был пробел

    if (!file) {
        cout << "Ошибка при открытии файла\n";
        return -1; // Возвращаем -1 в случае ошибки
    }

    while (file.get(c)) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') { // Проверка на разделители
            isSpace = true;
        }
        else if (c == targetChar && isSpace) {
            ++count;
            isSpace = false;
        }
        else {
            isSpace = false;
        }
    }

    file.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char PATH[] = "data.txt"; // относительный путь к файлу
    char targetChar;

    cout << "Введите символ: ";
    cin >> targetChar;

    int result = countWordsStartingWith(PATH, targetChar);
    if (result != -1) {
        cout << "Количество слов, начинающихся с '" << targetChar << "': " << result << endl;
    }

    return 0;
}
