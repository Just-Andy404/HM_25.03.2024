/*
��� ��������� ����. ���������� � ������ ���� ��� ��� ������ � ������� � ��� ������� 0 �� ������ 1 � ��������..
*/
#include <iostream>
#include <fstream>

using namespace std;

// ������� ��� ������ �� ������ ����� � ������ � ������ � ������� �������� '0' �� '1' � ��������
void replaceDigitsAndCopy(const char* inputPath, const char* outputPath) {
    ifstream inputFile(inputPath, ios::in); // ��������� ���� ��� ������
    ofstream outputFile(outputPath, ios::out); // ��������� ���� ��� ������

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "������ ��� �������� �����\n";
        return;
    }

    char c;
    while (inputFile.get(c)) { // ������ ������� �� �����
        if (c == '0') {
            c = '1';
        }
        else if (c == '1') {
            c = '0';
        }
        outputFile.put(c); // ���������� ���������� ������ � ����
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char firstPATH[] = "firstData.txt";
    const char secondPATH[] = "secondData.txt";

    replaceDigitsAndCopy(firstPATH, secondPATH); // ����� ������� ��� ��������� ������

    return 0;
}
