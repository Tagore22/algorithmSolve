#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[100][100];
int check[100][100];
int answer[100][100];
int trans[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

void bfs(int y, int x)
{
    answer[y][x] = 1;
    check[y][x] = 1;
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    while (!que.empty())
    {
        auto here = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            int cy = here.first + trans[i][0];
            int cx = here.second + trans[i][1];
            if (cy < 0 || cy >= n || cx < 0 || cx >= m || board[cy][cx] == 0 || check[cy][cx] == 1)
                continue;
            answer[cy][cx] = answer[here.first][here.second] + 1;
            check[cy][cx] = 1;
            que.push(make_pair(cy, cx));
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j)
            board[i][j] = str[j] - '0';
    }
    bfs(0, 0);
    cout << answer[n - 1][m - 1] << '\n';
    return 0;
}