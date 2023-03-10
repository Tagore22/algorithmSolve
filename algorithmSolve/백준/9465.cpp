#include <iostream>

using namespace std;

// 풀이
// 평범한 DP문제인데 너무 오래걸렸다.
// 위 아래 N개의 배열에서 각각 DP[0][K] 혹은 DP[1][K]의 최대값을 출력하면 된다.
// 각 경우는 k - 1의 대각선 값을 가지는 경우 혹은 k - 2의 대각선을 가지는 경우 2가지이므로 이 때의 최대값을
// 매번 갱신하면 된다.

int board[2][100000], dp[2][100000];
int T, N, answer;

void CalDP()
{
    dp[0][0] = board[0][0];
    dp[1][0] = board[1][0];
    dp[0][1] = board[1][0] + board[0][1];
    dp[1][1] = board[0][0] + board[1][1];

    for (int i = 1; i < N; ++i)
    {
        dp[0][i] = max(dp[1][i - 1] + board[0][i], dp[1][i - 2] + board[0][i]);
        dp[1][i] = max(dp[0][i - 1] + board[1][i], dp[0][i - 2] + board[1][i]);
    }

    cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
}

void MakeAnswer()
{
    for (int test = 0; test < T; ++test)
    {
        answer = 0;
        cin >> N;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];
        CalDP();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}