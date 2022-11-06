#include <iostream>

using namespace std;

//2455번 문제가 10번 반복으로 바뀐 문제

void MakeAnswer()
{
    int answer = 0, check = 0, minus, plus;
    for (int i = 0; i < 10; ++i)
    {
        cin >> minus >> plus;
        check -= minus;
        check += plus;
        answer = max(answer, check);
    }
    cout << answer << '\n';
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}