#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> board;
vector<int> way;
int v, e, k;

void DK()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, k));
    way.assign(v + 1, 987654321);
    way[k] = 0;
    while (!que.empty())
    {
        auto now = que.top();
        que.pop();
        int cost = now.first;
        int here = now.second;

        if (cost > way[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            auto next = board[here][i];
            int there = next.first;
            int len = next.second;

            if (cost + len < way[there])
            {
                way[there] = cost + len;
                que.push(make_pair(way[there], there));
            }
        }
    }
}

void ShowAll()
{
    for (int i = 1; i <= v; ++i)
    {
        if (way[i] == 987654321)
            cout << "INF" << '\n';
        else
            cout << way[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> v >> e >> k;
    board.assign(v + 1, vector<pair<int, int>>());
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
    }
    DK();
    ShowAll();
    return 0;
}