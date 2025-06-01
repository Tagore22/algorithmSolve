#include <iostream>

using namespace std;

const int MAX = 1000;
int N;
int board[MAX];

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        int ans = 0;
        for (int j = 0; j < i; ++j)
            if (board[j] < board[i])
                ++ans;
        cout << ans << '\n';
    }
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