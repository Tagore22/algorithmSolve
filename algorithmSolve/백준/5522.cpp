#include <iostream>

using namespace std;

int answer;

void MakeAnswer()
{
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    answer = 0;

    for (int i = 0; i < 5; ++i)
    {
        int a;
        cin >> a;
        answer += a;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}