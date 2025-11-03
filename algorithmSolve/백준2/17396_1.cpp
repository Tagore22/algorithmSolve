#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력받을 때에 도달할 수 없는 부분을 걸러내는 1번 풀이.

int N, M;
bool cantgo[100000] = { false, };
vector<pair<int, int>> board[100000];

void DK()
{
    priority_queue<pair<long long, int>> que;
    que.push(make_pair(0, 0));
    vector<long long> dist(N, 30000000001);
    dist[0] = 0;

    while (!que.empty())
    {
        long long cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > dist[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int time = board[here][i].second;
            if (dist[there] > cost + time)
            {
                dist[there] = cost + time;
                que.push(make_pair(-dist[there], there));
            }
        }
    }
    cout << (dist[N - 1] == 30000000001 ? -1 : dist[N - 1]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> cantgo[i];
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        // 출발 지점 혹은 도착 지점이 N - 1이 아닌데 도달할 수 없는 지역이라면
        // 무시한다.
        if ((from != N - 1 && cantgo[from]) || (to != N - 1 && cantgo[to]))
            continue;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
    DK();
    return 0;
}