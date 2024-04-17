/*
��� ��������� ����. ���������� ���������� ����, ������������ � �������, ������� ������ ������������.
*/
#include <iostream>
#include <fstream>
using namespace std;

// ������� ��� �������� ����, ������������ � ��������� �������
int countWordsStartingWith(const char* path, char targetChar) {
    ifstream file(path);
    char c;
    int count = 0;
    bool isSpace = true; // ������������, ��� ����� ������ �������� ��� ������

    if (!file) {
        cout << "������ ��� �������� �����\n";
        return -1; // ���������� -1 � ������ ������
    }

    while (file.get(c)) {
        if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') { // �������� �� �����������
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
    const char PATH[] = "data.txt"; // ������������� ���� � �����
    char targetChar;

    cout << "������� ������: ";
    cin >> targetChar;

    int result = countWordsStartingWith(PATH, targetChar);
    if (result != -1) {
        cout << "���������� ����, ������������ � '" << targetChar << "': " << result << endl;
    }

    return 0;
}
