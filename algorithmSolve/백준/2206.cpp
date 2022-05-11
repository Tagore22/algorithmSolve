#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int answer[1000][1000][2];
int n, m;
int trans[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

int bfs()
{
    queue<pair<pair<int, int>, int>> que;
    answer[0][0][1] = 1;
    que.push(make_pair(make_pair(0, 0), 1));
    while (!que.empty())
    {
        auto here = que.front();
        que.pop();
        if (here.first.first == n - 1 && here.first.second == m - 1)
            return answer[here.first.first][here.first.second][here.second];
        for (int i = 0; i < 4; ++i)
        {
            int cy = here.first.first + trans[i][0];
            int cx = here.first.second + trans[i][1];
            if (cy < 0 || cy >= n || cx < 0 || cx >= m || answer[cy][cx][here.second] != 0)
                continue;
            if (board[cy][cx] == 0)
            {
                answer[cy][cx][here.second] = answer[here.first.first][here.first.second][here.second] + 1;
                que.push(make_pair(make_pair(cy, cx), here.second));
            }
            else
            {
                if (here.second == 1)
                {
                    answer[cy][cx][0] = answer[here.first.first][here.first.second][1] + 1;
                    que.push(make_pair(make_pair(cy, cx), 0));
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j)
            board[i][j] = str[j] - '0';
    }
    cout << bfs() << '\n';
    return 0;
}