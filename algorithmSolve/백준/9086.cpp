#include <iostream>

using namespace std;

// 풀이.
// T개의 문자열을 입력받고 그때마다 첫번째 문자와 마지막 문자를 출력한다.

int main()
{
    int T;
    cin >> T;

    string str;
    for (int i = 0; i < T; ++i)
    {
        cin >> str;
        cout << str[0] << str[str.size() - 1] << '\n';
    }
    return 0;
}