#include <iostream>
#include <queue>

using namespace std;

int ladder[15][2];
int snake[15][2];
int answer[101];
int n, m;

void bfs()
{
    queue<int> que;
    answer[1] = 0;
    que.push(1);
    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        if (here == 100)
            break;
        for (int i = 0; i < n; ++i)
            if (here == ladder[i][0])
            {
                answer[ladder[i][1]] = answer[here];
                here = ladder[i][1];
                break;
            }
        for (int i = 0; i < m; ++i)
            if (here == snake[i][0])
            {
                answer[snake[i][1]] = answer[here];
                here = snake[i][1];
                break;
            }
        for (int i = 1; i <= 6; ++i)
        {
            int there = here + i;
            if (there > 100 || answer[there] != 0)
                continue;
            answer[there] = answer[here] + 1;
            que.push(there);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> ladder[i][0];
        cin >> ladder[i][1];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> snake[i][0];
        cin >> snake[i][1];
    }
    bfs();
    cout << answer[100] << '\n';
    return 0;
}