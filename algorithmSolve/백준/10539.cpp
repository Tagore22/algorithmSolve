#include <iostream>

using namespace std;

const int MAX = 100;
int N;
int board[MAX];

void Solve()
{
    cout << board[0] << ' ';
    for (int i = 1; i < N; ++i)
        cout << board[i] - board[i - 1] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        board[i] *= i + 1;
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}