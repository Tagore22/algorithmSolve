#include <iostream>
#include <queue>

using namespace std;

int R, C;
char board[100][100];
bool isvisit[100][100] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void BFS(int y, int x)
{
    isvisit[y][x] = true;
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            if (ny >= R || ny < 0 || nx >= C || nx < 0 || isvisit[ny][nx] || board[ny][nx] == '.')
                continue;

            isvisit[ny][nx] = true;
            que.push(make_pair(ny, nx));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];

    int answer = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] != '#' || isvisit[i][j])
                continue;
            BFS(i, j);
            ++answer;
        }
    }
    cout << answer << '\n';
    return 0;
}