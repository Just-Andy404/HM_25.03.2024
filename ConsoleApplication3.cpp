/*
Дан массив строк. Записать их в файл, расположив каждый элемент массива 
на отдельной строке с сохранением порядка.
*/
#include <iostream>
#include <fstream>
using namespace std;

// Функция для записи массива строк в файл
void writeArrayToFile(const char* filePath, char arr[][255], int size) {
    ofstream file(filePath); // Открываем файл для записи

    if (!file.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << arr[i] << endl; // Записываем каждую строку в файл
    }

    file.close(); // Закрываем файл
}

int main() {
    const int SIZE = 3;
    const int MAX_LENGTH = 255;
    char arrOfSymbol[SIZE][MAX_LENGTH] = { "First line", "Second line", "Third line" };
    const char PATH[] = "data.txt";

    writeArrayToFile(PATH, arrOfSymbol, SIZE); // Вызов функции для записи массива в файл

    return 0;
}

