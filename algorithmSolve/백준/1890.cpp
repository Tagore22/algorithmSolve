#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 전형적인 DP 문제인데 이상하게 정답률이 낮은 문제다.
// 내려갈수 있는 경우는 오른쪽과 아래 2가지인데, 최대 100 X 100 = 10000개의 칸이 있기에
// DP를 쓰지 않으면 2의 10000제곱이 되어 연산량이 너무 커진다.

// 각 좌표에서 [N - 1][N - 1]에 도달하는 경로를 저장하여
// 결과적으로 [0][0]을 출력하면 된다.

int board[100][100];
long long dp[100][100];
int rot[4][2] = { {0, 1}, {1, 0} }; // 우, 하.
int N;

long long DP(int y, int x)
{
    if (y == N - 1 && x == N - 1)
        return 1;

    long long& ans = dp[y][x];
    if (ans != -1)
        return ans;

    ans = 0;

    int dy, dx;
    for (int i = 0; i < 2; ++i)
    {
        dy = y + rot[i][0] * board[y][x];
        dx = x + rot[i][1] * board[y][x];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N)
            continue;

        ans += DP(dy, dx);
    }

    return ans;
}

void MakeAnswer()
{
    DP(0, 0);

    cout << dp[0][0] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}