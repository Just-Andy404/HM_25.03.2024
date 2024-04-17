/*
��� ������ �����. �������� �� � ����, ���������� ������ ������� ������� 
�� ��������� ������ � ����������� �������.
*/
#include <iostream>
#include <fstream>
using namespace std;

// ������� ��� ������ ������� ����� � ����
void writeArrayToFile(const char* filePath, char arr[][255], int size) {
    ofstream file(filePath); // ��������� ���� ��� ������

    if (!file.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        file << arr[i] << endl; // ���������� ������ ������ � ����
    }

    file.close(); // ��������� ����
}

int main() {
    const int SIZE = 3;
    const int MAX_LENGTH = 255;
    char arrOfSymbol[SIZE][MAX_LENGTH] = { "First line", "Second line", "Third line" };
    const char PATH[] = "data.txt";

    writeArrayToFile(PATH, arrOfSymbol, SIZE); // ����� ������� ��� ������ ������� � ����

    return 0;
}

