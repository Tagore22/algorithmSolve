#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> answer;
int trans[8][2] = { {-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1} };
int L, endY, endX;

void bfs(int y, int x)
{
    answer[y][x] = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    while (!que.empty())
    {
        auto here = que.front();
        que.pop();
        if (here.first == endY && here.second == endX)
            break;
        for (int i = 0; i < 8; ++i)
        {
            int cy = here.first + trans[i][0];
            int cx = here.second + trans[i][1];
            if (cy < 0 || cy >= L || cx < 0 || cx >= L || answer[cy][cx] != -1)
                continue;
            answer[cy][cx] = answer[here.first][here.second] + 1;
            que.push(make_pair(cy, cx));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> L;
        answer.assign(L, vector<int>(L, -1));
        int startY, startX;
        cin >> startY >> startX >> endY >> endX;
        bfs(startY, startX);
        cout << answer[endY][endX] << '\n';
    }
    return 0;
}