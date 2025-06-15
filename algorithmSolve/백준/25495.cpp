#include <iostream>

using namespace std;

int N;
const int MAX = 1000;
int board[MAX];

void Solve()
{
    int answer = 2, cur = 2;
    for (int i = 1; i < N; ++i)
    {
        if (board[i] == board[i - 1] && cur != 0)
            cur *= 2;
        else
            cur = 2;
        answer += cur;
        if (answer >= 100)
        {
            answer = 0;
            cur = 0;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}