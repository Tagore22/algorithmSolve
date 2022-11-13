#include <iostream>

using namespace std;

//str을 왼쪽으로 4번 쉬프트(16배)하고 다시 기존 str을 더하면 총 17배가 된다.

string str;

void MakeAnswer()
{
    string plus = str;
    str += "0000";
    while (str.size() != plus.size())
        plus = '0' + plus;

    int check = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        check += (str[i] - '0') + (plus[i] - '0');
        if (check >= 2)
        {
            str[i] = check - 2 + '0';
            check = 1;
        }
        else
        {
            str[i] = check + '0';
            check = 0;
        }
    }

    if (check == 1)
        str = '1' + str;

    cout << str << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}