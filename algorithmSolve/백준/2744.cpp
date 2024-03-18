#include <iostream>

using namespace std;

// 풀이.
// 문자열을 입력받아 각 문자를 대문자 혹은 소문자로 스위칭하는 문제.

int main()
{
    string str, answer = "";
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('a' <= str[i] && str[i] <= 'z')
            answer += str[i] - 32;
        else
            answer += str[i] + 32;
    }
    cout << answer << '\n';
    return 0;
}