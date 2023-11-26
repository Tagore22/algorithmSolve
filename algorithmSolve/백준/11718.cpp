#include <iostream>
#include <string>

using namespace std;

// 공백을 포함한 문자열을 매번 입력받아 그대로 출력하면 된다.

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (getline(cin, str))
    {
        cout << str << '\n';
    }

    return 0;
}