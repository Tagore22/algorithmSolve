#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[100][100];
bool visit[100][100] = { false, };
int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int T, H, W, answer = 0;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;
    ++answer;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W || visit[ny][nx] ||
                board[ny][nx] == '.')
                continue;
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void Solve()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> H >> W;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                cin >> board[i][j];

        answer = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (board[i][j] == '#' && !visit[i][j])
                    BFS(i, j);
        cout << answer << '\n';
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
    Solve();
    return 0;
}