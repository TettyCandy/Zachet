#include <cstring>
#include <iostream>
 
using namespace std;
 
string str;
 
// �������� ������ �� ���������. ���� ������������� �� ������ ������ ������� �� ���������, ������ ��� �� ���������
bool isPalindrome(string str) {
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}
 
string deleteMaxPalindrome(string str) {
    int maxPalindromeSize = 0;
    int left = -1;
    int right = -1;
    // ��������� ��� ���� ������������� �������� i, j, �������� ������ � i �� j ������ �� ��������� � ������� �� ����� ����������� ������������ �� �����
    for (int i = 0; i < str.size(); ++i)
        for (int j = i; j < str.size(); ++j)
            if (isPalindrome(str.substr(i, j - i + 1))) {
                if (maxPalindromeSize < j - i + 1) {
                    maxPalindromeSize = j - i + 1;
                    left = i;
                    right = j;
                }
            }
   // ����� ���� ���������, ������� ��������� � [left, right], � �������� ������ ������� ������ ��� ����� �������
    string result = str.substr(0, left);
    result.append(str.substr(right + 1, str.size() - (right + 1)));
    return result;
}
 
int main() {
 
    cin >> str;
    cout << deleteMaxPalindrome(str) << endl;
 
    return 0;
}
