#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 간선을 하나씩 없애는 것에서 실수를 했다. 처음에는 간선을 없애기 위해서 기존처럼 vector 배열이 아닌
// int 이중 배열을 통해 각 정점 사이의 간선값을 저장하여 하나씩 INF로 바꿔갔다. 당연히 시간초과가 났다.
// 그 이후 어떠한 간선도 건드리지 않았을 경우의 최단경로를 따로 저장하여 그 경로만 건드리는 것과
// 다익스트라 함수의 구현을 수정해서 int 이중 배열이 아닌 다시 vector 배열을 사용하는 것을 이용해
// 답을 도출했다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[1001];
int parent[1001]; // 최단 경로를 저장한다.
const int INF = 987654321;
int N, M, minans, maxans = -INF;

int DK(int from, int to)
{
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));
    vector<int> dist(N + 1, INF);
    dist[1] = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost < dist[here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int next = p.second;
            // 상술한 특정 간선을 지우는 방법. 기존에는 직접 int 이중 배열값에 가중치를 저장하여
            // 값을 수정하였으나 이 방법이 훨씬 더 빠르고 간단했다.
            if ((from == here && to == there) || (from == there && to == here))
                continue;
            int nextdist = cost + next;
            if (dist[there] > nextdist)
            {
                dist[there] = nextdist;
                que.push(make_pair(-nextdist, there));
                // 특정 간선을 지우지 않는 경우에만 경로를 구한다.
                if (from == 0 && to == 0)
                    parent[there] = here;
            }
        }
    }
    return dist[N];
}

void MakeAnswer()
{
    parent[1] = 0;
    minans = DK(0, 0);
    int to = N;
    // N부터 시작하여 1까지 모든 최단 경로를 순회하며 간선을 하나씩 지운다.
    while (parent[to] != 0)
    {
        int from = parent[to];
        maxans = max(maxans, DK(from, to));
        if (maxans == INF)
        {
            cout << -1 << '\n';
            return;
        }
        to = from;
    }
    cout << maxans - minans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, time;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> time;
        board[from].push_back(make_pair(to, time));
        board[to].push_back(make_pair(from, time));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}