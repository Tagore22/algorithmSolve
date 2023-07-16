#include <iostream>

using namespace std;

// 17069번의 재귀가 아닌 일반 for문을 이용한 dp 풀이.
// 큰 틀은 기존 풀이와 같으나, 말그대로 재귀를 없애고 단순 for문을 이용하였다.

// 자세한 설명은 주석으로 남긴다.

bool board[33][33];
long long dp[34][34][3];
int N;

void MakeAnswer()
{
    dp[1][2][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 2; j <= N; ++j)
        {
            if (board[i][j])
                continue;

            // 우측으로 이동. 현재 가로인 상태와 대각선인 상태에서 이동 가능.
            if (!board[i][j + 1])
                dp[i][j + 1][0] = dp[i][j][0] + dp[i][j][2];
            // 아래로 이동. 현재 세로인 상태와 대각선인 상태에서 이동 가능.
            if (!board[i + 1][j])
                dp[i + 1][j][1] = dp[i][j][1] + dp[i][j][2];
            // 대각선으로 이동. 현재 가로, 세로, 대각선인 상태에서 이동 가능.
            if (!board[i][j + 1] && !board[i + 1][j + 1] && !board[i + 1][j])
                dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        }

    long long answer = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}