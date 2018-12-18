#include <cstring>
#include <iostream>
 
using namespace std;
 
string str;
 
// проверка строки на палиндром. Если равноудаленне от концов строки символы не совпадают, значит это не палиндром
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
    // переберем все пары несовпадающих индексов i, j, проверим строку с i по j индекс на палиндром и выберем из таких палиндромов максимальный по длине
    for (int i = 0; i < str.size(); ++i)
        for (int j = i; j < str.size(); ++j)
            if (isPalindrome(str.substr(i, j - i + 1))) {
                if (maxPalindromeSize < j - i + 1) {
                    maxPalindromeSize = j - i + 1;
                    left = i;
                    right = j;
                }
            }
   // нашли макс палиндром, который находится в [left, right], в качестве ответа возьмем строку без этого отрезка
    string result = str.substr(0, left);
    result.append(str.substr(right + 1, str.size() - (right + 1)));
    return result;
}
 
int main() {
 
    cin >> str;
    cout << deleteMaxPalindrome(str) << endl;
 
    return 0;
}
