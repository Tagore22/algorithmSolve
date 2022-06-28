#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; //단방향 그래프, 주어지는 정점의 번호는 1번부터 n번까지, 각 간선을 갱신할필요는 없다.

vector<vector<pair<int, int>>> board;
int N, M, X;
const int MAXNUM = 987654321;

int DK(int from, int to)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, from));
    vector<int> way(N, MAXNUM);
    way[from] = 0;
    while (!que.empty())
    {
        int cost = que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > way[here])
            continue;
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = cost + board[here][i].second;

            if (way[there] > len)
            {
                way[there] = len;
                que.push(make_pair(way[there], there));
            }
        }
    }
    return way[to];
}

void ShowAnswer()
{
    int answer = -1;
    for (int i = 0; i < N; ++i)
        answer = max(answer, DK(i, X - 1) + DK(X - 1, i));
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    board.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1].push_back(make_pair(b - 1, c));
    }
    ShowAnswer();
    return 0;
}