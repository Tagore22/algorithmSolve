#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int K, W, H;
int cashe[200][200][31];
char board[200][200];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int jy[8] = { -2,-1,1,2,2,1,-1,-2 };
int jx[8] = { -1,-2,-2,-1,1,2,2,1 };
const int MAXNUM = 987654321;

void BFS()
{
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(0, 0), K));
    cashe[0][0][K] = 0;
    while (!que.empty())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int jump = que.front().second;
        que.pop();

        if (y == H - 1 && x == W - 1)
        {
            cout << cashe[y][x][jump] << '\n';
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int cy = y + dy[i];
            int cx = x + dx[i];
            if (cy >= H || cx >= W || cy < 0 || cx < 0 || board[cy][cx] == '1' || cashe[cy][cx][jump] != -1)
                continue;
            cashe[cy][cx][jump] = cashe[y][x][jump] + 1;
            que.push(make_pair(make_pair(cy, cx), jump));
        }
        if (jump > 0)
            for (int i = 0; i < 8; ++i)
            {
                int cy = y + jy[i];
                int cx = x + jx[i];
                if (cy >= H || cx >= W || cy < 0 || cx < 0 || board[cy][cx] == '1' || cashe[cy][cx][jump - 1] != -1)
                    continue;
                cashe[cy][cx][jump - 1] = cashe[y][x][jump] + 1;
                que.push(make_pair(make_pair(cy, cx), jump - 1));
            }
    }
    cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> K >> W >> H;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    BFS();
    return 0;
}