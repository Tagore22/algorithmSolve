#include <iostream>

using namespace std;

// 풀이.
// 문자열의 길이가 조건에 해당하는지 확인하는 문제.

int N;

void MakeAnswer()
{
    string str;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        if (str.size() < 6 || str.size() > 9)
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}