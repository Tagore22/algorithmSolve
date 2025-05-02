#include <iostream>

using namespace std;

// 풀이.
// 2차원 누적합 문제다. 예전에 많이 버벅였는데 혼자 힘으로 잘 풀어내서 다행이다.

const int MAXNUM = 1025;
int N, M, K;
int board[MAXNUM][MAXNUM], dp[MAXNUM][MAXNUM];

void CalculSum()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
}

void Solve()
{
    CalculSum();
    for (int iter = 0; iter < K; ++iter)
    {
        pair<int, int> leftup, rightdown;
        cin >> leftup.first >> leftup.second >> rightdown.first >> rightdown.second;

        int answer = 0;
        answer = dp[rightdown.first][rightdown.second] - dp[rightdown.first][leftup.second - 1]
            - dp[leftup.first - 1][rightdown.second] + dp[leftup.first - 1][leftup.second - 1];

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    cin >> K;
}

int main()
{
    Input();
    Solve();
    return 0;
}