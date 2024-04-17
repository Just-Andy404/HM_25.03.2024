/*
��� ��������� ����. ���������� ���������� �������� � ���.
*/
#include <iostream>
#include <fstream>

using namespace std;

// ������� ��� �������� �������� � �����, �������� ������� � ����� ����������
int countCharacters(const char* path) {
    ifstream file(path);
    char c;
    int count = 0;

    if (!file.is_open()) {
        cerr << "������ ��� �������� �����\n";
        return -1; // ���������� -1 � ������ ������
    }

    while (file.get(c)) { // ������ ������ �� �����
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
    const char PATH[] = "data.txt"; // ������������� ���� � �����

    int result = countCharacters(PATH);
    if (result != -1) {
        cout << "���������� ��������: " << result << endl;
    }

    return 0;
}
