#include <iostream>

using namespace std;

// 풀이.
// X를 A 혹은 B로 대체하는 문제이다. 사전순으로 앞서는 답을 출력해야하기 때문에 A를 먼저 대입해보아야 한다.
// 다만, A는 4개고 B는 2개이기 때문에 이부분을 생각해서 구현하면 된다.

string str, answer = "";

void MakeAnswer()
{
    int num = 0;
    for (int iter = 0; iter < str.size(); ++iter)
    {
        if (str[iter] == 'X')
        {
            ++num;
        }
        else
        {
            if (num % 2 != 0)
            {
                cout << -1 << '\n';
                exit(0);
            }
            for (int i = 0; i < num / 4; ++i)
                answer += "AAAA";
            num %= 4;
            for (int i = 0; i < num / 2; ++i)
                answer += "BB";
            num %= 2;
            answer += ".";
        }
    }
    if (num % 2 != 0)
    {
        cout << -1 << '\n';
        exit(0);
    }
    for (int i = 0; i < num / 4; ++i)
        answer += "AAAA";
    num %= 4;
    for (int i = 0; i < num / 2; ++i)
        answer += "BB";
    cout << answer << '\n';
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