#include <iostream>

using namespace std;

//총합을 구해 60으로 나누었을때 분과 초를 구하는 문제

void MakeAnswer()
{
    int answer = 0, plus;
    for (int i = 0; i < 4; ++i)
    {
        cin >> plus;
        answer += plus;
    }
    cout << answer / 60 << '\n';
    cout << answer % 60 << '\n';
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