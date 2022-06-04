#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, from, to;
vector<vector<int>> board;

void DK()
{
    vector<int> way(n + 1, 987654321);
    way[from] = 0;
    vector<int> parent(n + 1, -1);
    parent[from] = -10;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, from));
    while (!que.empty())
    {
        auto here = que.top();
        que.pop();
        int cost = here.first;
        int where = here.second;

        if (cost > way[where])
            continue;
        for (int there = 0; there < board[where].size(); ++there)
        {
            if (board[where][there] != 100000 && (board[where][there] + cost < way[there]))
            {
                parent[there] = where;
                way[there] = cost + board[where][there];
                que.push(make_pair(way[there], there));
            }
        }
    }
    cout << way[to] << '\n';
    vector<int> answer;
    while (parent[to] != -10)
    {
        answer.push_back(to);
        to = parent[to];
    }
    answer.push_back(to);
    cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n + 1, vector<int>(n + 1, 100000));
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }
    cin >> from >> to;
    DK();
    return 0;
}