#include <iostream>

using namespace std;

// 풀이.
// 맨 앞의 대문자와 각 하이폰 뒤의 대문자를 출력하는 문제다.
// 즉 줄임말을 출력해야 하는데 문제에서 그 줄임말들만 대문자라고 나와있으므로 간단하게
// 주어진 문자열에서 대문자들만 출력하면 된다.

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        if ('A' <= str[i] && str[i] <= 'Z')
            cout << str[i];
    cout << '\n';
    return 0;
}