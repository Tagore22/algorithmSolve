#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 문제에서 제시하는 가까워지며 이동하는 경우가 이해가 잘 안갔다. 어떤 기준이 있어야
// 가깝거나 멀거나를 평하는데 그 기준이 애매했다. 이후 최단거리를 이용하는 로직이라는
// 것을 알았으나 그래도 이해가 안가서 한참을 찾았다. 설명하자면 최단거리는 최소값을
// 의미한다. 따라서 1 -> 3 -> 2 경로로 이동하고 각 최단거리가 5, 3, 0이라면
// 1번 정점에서는 최소 5를 이동해야 2번 정점에 도달하는 반면 3번 정점에서는 최소 3만 이동하면
// 2번 정점에 도달할 수 있으므로 가까워졌다고 할 수 있으나 최단 거리가 5, 8, 0이라면
// 3번 정점에서 2번 정점으로 최소 8을 이동해야 도달할 수 있기에 결코 가까워졌다고 할 수 없다.
// 이렇게 설명을 들으니 이해가 갔다. 

// 로직은 어려울게 없는데 다익스트라로 각 정점의 최단거리를 찾는다. 다만 시작지점이 아닌
// 도착지점에서의 최단거리들을 구해야 위에서 말한 로직에 이용할 수 있음을 주의할 것.
// 그 이후 DFS 혹은 BFS로 시작점에서 도착점까지 최단경로가 짧은 순으로 이동하는
// 경로들의 수를 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
vector<pair<int, int>> board[1001];
vector<int> dist(1001, 1987654321), dp(1001, -1);

void DK()
{
    // 상술한대로 시작 지점이 아닌 도착 지점에서의 최단 거리를 구해야 한다.
    dist[2] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 2));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > dist[here])
            continue;

        for (const auto& next : board[here])
        {
            int there = next.first;
            int len = next.second;
            if (cost + len < dist[there])
            {
                dist[there] = cost + len;
                que.push(make_pair(-dist[there], there));
            }
        }
    }
}

int CalPathNum(int here)
{
    if (here == 2)
        return 1;

    int& ans = dp[here];
    if (ans != -1)
        return ans;

    ans = 0;
    for (const auto& next : board[here])
    {
        int there = next.first;
        // 현재 정점보다 도착 지점까지의 최단 거리가 짧은 정점들만을
        // 순회한다. 이는 상술하였듯 최단거리는 최소값을 의미하며
        // 이동하려는 정점의 최소값이 현재 정점의 최소값보다 크다면
        // 결코 가까워졌다고 할 수 없기 때문이다.
        if (dist[here] > dist[there])
            ans += CalPathNum(there);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }

    DK();
    cout << CalPathNum(1) << '\n';
    return 0;
}