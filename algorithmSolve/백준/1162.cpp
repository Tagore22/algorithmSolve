#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<pair<int, int>>> board;
int N, M, K;

void DK()
{
    vector<vector<long long>> min_dist(N + 1, vector<long long>(K + 1, numeric_limits<long long>::max()));//위치,K
    min_dist[1][0] = 0;
    priority_queue<pair<long long, pair<int, int>>> que; //거리,위치,K
    que.push(make_pair(0, make_pair(1, 0)));
    while (!que.empty())
    {
        long long len = -que.top().first;
        int here = que.top().second.first;
        int zero = que.top().second.second;
        que.pop();

        if (min_dist[here][zero] < len)
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            long long cost = board[here][i].second + len;

            if (min_dist[there][zero] > cost)
            {
                min_dist[there][zero] = cost;
                que.push(make_pair(-cost, make_pair(there, zero)));
            }

            if (zero + 1 <= K && len < min_dist[there][zero + 1])
            {
                min_dist[there][zero + 1] = len;
                que.push(make_pair(-len, make_pair(there, zero + 1)));
            }
        }
    }
    long long answer = numeric_limits<long long>::max();
    for (int i = 0; i <= K; ++i)
        answer = min(answer, min_dist[N][i]);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    board.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
}

int main()
{
    Input();
    DK();
    return 0;
}