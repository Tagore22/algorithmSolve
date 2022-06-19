#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board; // 정점의 번호는 1번부터 n번까지. 각 간선을 갱신할 필요는 없다.
vector<bool> Check;
int n, m;

void BFS(int now)
{
    queue<int> que;
    que.push(now);
    Check[now] = true;
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            if (!Check[there])
            {
                que.push(there);
                Check[there] = true;
            }
        }
    }
}

void ShowAnswer()
{
    Check.assign(n, false);
    int answer = 0;
    for (int i = 0; i < n; ++i)
        if (!Check[i])
        {
            ++answer;
            BFS(i);
        }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1].push_back(b - 1);
        board[b - 1].push_back(a - 1);
    }
    ShowAnswer();
    return 0;
}