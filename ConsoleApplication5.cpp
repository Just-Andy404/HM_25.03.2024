/*
��� ��������� ����. ���������� ���������� ����� � ���.
*/
#include <iostream>
#include <fstream>

using namespace std;

// ������� ��� �������� ����� � �����
int countLines(const char* filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "������ ��� �������� �����\n";
        return -1; // ���������� -1 � ������ ������
    }

    char line[1024]; // ������ ��� �������� ������
    int count = 0;
    bool isEmpty = true;

    while (file.getline(line, sizeof(line))) {
        int i = 0;
        isEmpty = true; // ������������, ��� ������ �����

        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '.' && line[i] != '?') {
                isEmpty = false; // ������ �������� �������, �� ���������� ��������� ��� ������� ����������
                break;
            }
            i++;
        }

        if (!isEmpty) {
            count++; // ��������� ������, ���� ��� �� �����
        }
    }

    file.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const char PATH[] = "data.txt"; // ������������� ���� � �����

    int result = countLines(PATH);
    if (result != -1) {
        cout << "���������� �����: " << result << endl;
    }

    return 0;
}
