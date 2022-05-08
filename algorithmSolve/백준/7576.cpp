#include <iostream>
#include <queue>

using namespace std;

int m, n;
int board[1000][1000];
int trans[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
queue<pair<int, int>> que;

int bfs()
{
    int answer = -1;
    while (!que.empty())
    {
        int qSize = que.size();
        for (int i = 0; i < qSize; ++i)
        {
            auto here = que.front();
            que.pop();
            for (int j = 0; j < 4; ++j)
            {
                int cy = here.first + trans[j][0];
                int cx = here.second + trans[j][1];
                if (cy < 0 || cy >= n || cx < 0 || cx >= m || board[cy][cx] != 0)
                    continue;
                board[cy][cx] = 1;
                que.push(make_pair(cy, cx));
            }
        }
        ++answer;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] == 0)
                return -1;
    return answer;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                que.push(make_pair(i, j));
        }
    cout << bfs() << '\n';
    return 0;
}