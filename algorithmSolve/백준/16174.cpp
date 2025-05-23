#include <iostream>
#include <queue>

using namespace std;

int N;
const int MAX = 64;
int board[MAX][MAX], dir[2][2] = { {0, 1}, {1, 0} };

void BFS()
{
    queue<pair<int, int>> que;
    que.push({ 0, 0 });
    bool visit[MAX][MAX] = { false, };
    visit[0][0] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        if (y == N - 1 && x == N - 1)
        {
            cout << "HaruHaru" << '\n';
            return;
        }

        for (int i = 0; i < 2; ++i)
        {
            int ny = y + (dir[i][0] * board[y][x]);
            int nx = x + (dir[i][1] * board[y][x]);

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visit[ny][nx])
                continue;

            que.push({ ny, nx });
            visit[ny][nx] = true;
        }
    }
    cout << "Hing" << '\n';
}

void Solve()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}