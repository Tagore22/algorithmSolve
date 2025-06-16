#include <iostream>

using namespace std;

int map[1000][1000], board[9][9];
int N, M, R, C;

bool IsSameHeight(int fromy, int fromx)
{
    int cur = map[fromy][fromx] - board[0][0];
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (map[fromy + i][fromx + j] - board[i][j] != cur)
                return false;
    return true;
}

void Solve()
{
    int answer = 0;
    for (int i = 0; i <= N - R; ++i)
        for (int j = 0; j <= M - C; ++j)
            if (IsSameHeight(i, j))
                ++answer;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> R >> C;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}