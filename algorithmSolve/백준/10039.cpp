#include <iostream>

using namespace std;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < 5; ++i)
    {
        int a;
        cin >> a;
        answer = a >= 40 ? answer + a : answer + 40;
    }
    cout << answer / 5 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}