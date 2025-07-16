#include <iostream>
#include <queue>

using namespace std;

int n, s;
int board[100001];
bool visit[100001] = { false, };

void BFS()
{
    queue<int> que;
    que.push(s);
    visit[s] = true;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = -1; i <= 1; i += 2)
        {
            int there = here + board[here] * i;

            if (there <= 0 || there > n || visit[there])
                continue;

            que.push(there);
            visit[there] = true;
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; ++i)
        if (visit[i])
            ++answer;

    cout << answer << '\n';
}

void Solve()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> board[i];
    cin >> s;
}

int main()
{
    Input();
    Solve();
    return 0;
}