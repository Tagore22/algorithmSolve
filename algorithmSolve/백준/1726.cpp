#include <iostream>
#include <queue>

using namespace std;

struct where
{
    int y;
    int x;
    int dir;
};

where now, goal;
bool check[100][100][4] = { 0, };
int board[100][100];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int dd[4] = { 0,2,1,3 };
int M, N;

int BFS()
{
    queue<pair<where, int>> que;
    que.push(make_pair(now, 0));
    check[now.y][now.x][now.dir] = true;
    while (!que.empty())
    {
        where cur = que.front().first;
        int num = que.front().second;
        que.pop();

        if (cur.y == goal.y && cur.x == goal.x && cur.dir == goal.dir)
            return num;

        int cy = cur.y;
        int cx = cur.x;
        int dir = cur.dir;

        for (int i = 0; i < 3; ++i)
        {
            cy += dy[dir];
            cx += dx[dir];

            if (cy >= M || cx >= N || cy < 0 || cx < 0 || board[cy][cx] == 1)
            {
                break;
            }
            else if (!check[cy][cx][dir])
            {
                que.push(make_pair(where{ cy,cx,dir }, num + 1));
                check[cy][cx][dir] = true;
            }
        }

        if (!check[cur.y][cur.x][(cur.dir + 1) % 4])
        {
            que.push(make_pair(where{ cur.y,cur.x,(cur.dir + 1) % 4 }, num + 1));
            check[cur.y][cur.x][(cur.dir + 1) % 4] = true;
        }
        if (!check[cur.y][cur.x][(cur.dir + 3) % 4])
        {
            que.push(make_pair(where{ cur.y,cur.x,(cur.dir + 3) % 4 }, num + 1));
            check[cur.y][cur.x][(cur.dir + 3) % 4] = true;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    cin >> now.y >> now.x >> now.dir;
    cin >> goal.y >> goal.x >> goal.dir;
    now.y -= 1;
    now.x -= 1;
    now.dir = dd[now.dir - 1];
    goal.y -= 1;
    goal.x -= 1;
    goal.dir = dd[goal.dir - 1];
}

int main()
{
    Input();
    cout << BFS() << '\n';
    return 0;
}