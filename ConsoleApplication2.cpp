/*
Дан текстовый файл. Переписать в другой файл все его строки с заменой в них символа 0 на символ 1 и наоборот..
*/
#include <iostream>
#include <fstream>

using namespace std;

// Функция для чтения из одного файла и записи в другой с заменой символов '0' на '1' и наоборот
void replaceDigitsAndCopy(const char* inputPath, const char* outputPath) {
    ifstream inputFile(inputPath, ios::in); // Открываем файл для чтения
    ofstream outputFile(outputPath, ios::out); // Открываем файл для записи

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Ошибка при открытии файла\n";
        return;
    }

    char c;
    while (inputFile.get(c)) { // Читаем символы из файла
        if (c == '0') {
            c = '1';
        }
        else if (c == '1') {
            c = '0';
        }
        outputFile.put(c); // Записываем измененный символ в файл
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char firstPATH[] = "firstData.txt";
    const char secondPATH[] = "secondData.txt";

    replaceDigitsAndCopy(firstPATH, secondPATH); // Вызов функции для обработки файлов

    return 0;
}
