#include <iostream>

using namespace std;

// 풀이.
// 현재 문자열을 출력할 길이 iter를 조건문을 이용해 구한다.
// 그 이후 iter만큼 출력을 하고 다시 iter만큼 잘라낸다.

// 이 모든 것을 str이 빌때까지 반복한다.

string str;

void MakeAnswer()
{
    while (!str.empty())
    {
        int ssize = str.size();
        int iter = ssize > 10 ? 10 : ssize;
        for (int i = 0; i < iter; ++i)
            cout << str[i];

        cout << '\n';
        str = str.substr(iter);
    }
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