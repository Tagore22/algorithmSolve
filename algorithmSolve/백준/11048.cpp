#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 오른쪽, 아래, 우하단으로 이동할수 있을때 (N, M)까지 이동하면서
// 얻을수 있는 가장 큰 수를 출력하는 문제다.
// dp를 이용하여 이동할수 있는 3가지 방법을 완전탐색하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1000][1000], dp[1000][1000];
int rot[3][2] = { {1, 0}, {0, 1}, {1, 1} };
int N, M;

// 이동할수 있는 모든 방법을 순회하는 함수.
int CalMax(int y, int x)
{
    if (y == N - 1 && x == M - 1)
        return board[y][x];

    int& ans = dp[y][x];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 0; i < 3; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy >= N || dx >= M)
            continue;

        ans = max(ans, CalMax(dy, dx) + board[y][x]);
    }
    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = CalMax(0, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}