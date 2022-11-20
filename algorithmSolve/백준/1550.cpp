#include <iostream>
#include <cmath>

//풀이
//알파벳과 숫자가 섞여서 입력을 받기에 string으로 입력을 받아서 매 자리수를 16의 제곱으로 변환후 현 자리수를 곱한값을 더해간다.

using namespace std;

string str;

void MakeAnswer()
{
    int answer = 0, check, idx = str.size() - 1;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
            check = str[i] - '0';
        else
            check = str[i] - 55;
        answer += check * pow(16, idx - i);
    }

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