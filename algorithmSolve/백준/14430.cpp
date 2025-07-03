#include <iostream>

using namespace std;

int board[300][300], dp[300][300] = { 0, };
int N, M;

void Solve()
{
    dp[0][0] = board[0][0];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + board[i][j]);
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + board[i][j]);
        }
    }
    cout << dp[N - 1][M - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}