#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// DP와 DFS의 혼합 문제다. 다만 좌표는 무조건 오른쪽, 아래쪽 등으로 증가만 함으로
// 왔던 곳을 다시 확인하는 중복 처리는 할 필요가 없다.
// 다만 3중 배열로 DP를 구현해야하는데, 어떠한 좌표에 똑같이 도달했어도
// 파이프의 모양에 따라 N, N에 도달할수 있고 없고가 차이나기 때문이다.
// 또한, 가로 혹은 세로로 움직이는 것과 대각선으로 움직이는 것이 
// 조건이 다르기 때문에 이 또한 주의해야 한다.

// P.S 이문제를 풀때 분명히 로직은 맞았는데 답이 이상하게 나왔었다. 뭐가 잘못된건지를 한참 고민했는데
// rot배열이 문제였다. 지금은 고쳤으나 이전에는 rot[3][3][2]가 아닌 rot[3][2][2]로 줄여놨었다.
// 그렇다 보니 세로의 모양이 dir = 2인데 dir = 1로 이상하게 뒤죽박죽 섞여서 답이 나오지 않았었다.
// DP는 늘 로그로 확인하기가 너무 힘들다. T^T

int rot[3][3][2] = { {{0, 1}, {-1, -1}, {-1, -1}}, {{0, 1}, {-1, -1}, {1, 0}}, {{-1, -1}, {-1, -1}, {1, 0}} };
int dp[16][16][3];
int board[16][16];
int N;

int DFS(int y, int x, int dir)
{
    // N, N에 도달했다면 1을 반환함으로 경우의 수를 증가시킨다.
    if (y == N - 1 && x == N - 1)
        return 1;

    // 상술하였듯 좌표 뿐만 아니라 그 방향까지 DP에 포함시켜야만 한다.
    int& ans = dp[y][x][dir];
    if (ans != -1)
        return ans;

    ans = 0;

    // 가로 혹은 세로로 움직일때.
    for (int i = 0; i < 3; ++i)
    {
        if (rot[dir][i][0] == -1)
            continue;

        int dy = y + rot[dir][i][0];
        int dx = x + rot[dir][i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || board[dy][dx] == 1)
            continue;

        ans += DFS(dy, dx, i);
    }

    // 대각선으로 움직일때. 만약 움직일수 없다면 그냥 현재 경우의 수를 바로 반환한다.
    int dy = y + 1;
    int dx = x + 1;

    if (dy < 0 || dy >= N || dx < 0 || dx >= N || board[dy][dx] == 1 ||
        board[dy][x] == 1 || board[y][dx] == 1)
        return ans;

    ans += DFS(dy, dx, 1);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));

    int answer = DFS(0, 1, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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