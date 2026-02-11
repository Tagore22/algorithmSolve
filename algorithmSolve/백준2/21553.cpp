#include <iostream>

using namespace std;

// 풀이.
// str1과 중복되는 부분 문자열 str2를 가지는 아무 문자열을 출력하는 문제.
// str2 자체가 자기 자신을 가지므로 그대로 출력하면 된다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;
    cout << str2 << '\n';
    return 0;
}