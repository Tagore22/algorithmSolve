#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 백트래킹의 재귀 호출과 dp를 이용한 풀이다.
// 각 가로, 세로, 대각선마다 이동할수 있는 조건이 있으며 그 조건을 만족하는
// 경우중 N, N에 도달할수 있는 경우의 수를 출력하면 된다.
// 다만, 최대값이 int값을 벗어나기에 long long 타입을 사용하여야 한다.

// 자세한 설명은 주석으로 남긴다.

bool board[33][33];
long long dp[33][33][3];
int N;

long long BackTrack(int y, int x, int pos)
{
    if (y == N && x == N)
        return 1;

    // 각 위치와 현재 방향에 대해 dp를 구축한다.
    long long& ans = dp[y][x][pos];
    if (ans != -1)
        return ans;

    ans = 0;

    // 현재 파이프가 가로일때.
    if (pos == 0)
    {
        if (!board[y][x + 1] && y <= N && x + 1 <= N)
            ans += BackTrack(y, x + 1, pos);
    }

    else if (pos == 1)
    {
        if (!board[y + 1][x] && y + 1 <= N && x <= N)
            ans += BackTrack(y + 1, x, pos);
    }

    else
    {
        if (!board[y][x + 1] && y <= N && x + 1 <= N)
            ans += BackTrack(y, x + 1, 0);
        if (!board[y + 1][x] && y + 1 <= N && x <= N)
            ans += BackTrack(y + 1, x, 1);
    }
    // 대각선은 모든 상황에서 움직일수 있기에 조건만 만족하면 무조건 이동.
    if (!board[y][x + 1] && !board[y + 1][x + 1] && !board[y + 1][x] &&
        y + 1 <= N && x + 1 <= N)
        ans += BackTrack(y + 1, x + 1, 2);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    long long answer = BackTrack(1, 2, 0);

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