#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 처음엔 유량 알고리즘인줄 알았는데 알고 보니 최소 스패닝 트리를 이용한
// 최대 스패닝 트리였다. 프림을 사용하였는데 우선순위 큐를 사용하여야 했고
// 가장 큰 문제는 문제에서 도달하지 못하는 경우에 어떤 식으로 출력을 하라는지
// 언급이 없어서 무조건 도달하는 줄 알았더니 그게 아니라 그럴 경우 0을 출력해야했다.
// 내가 이해를 못한 건지 문제가 조금 지저분한건지 모르겠다. 클로드를 통해서
// 따로 공부를 했는데 크루스칼이 더 구현이 간단하다고 하니 앞으로는 그냥 크루스칼을
// 써야겠다.

// 자세한 설명은 주석으로 남긴다.

int N, M, s, e;
vector<pair<int, int>> board[100001];

// 프림 알고리즘 함수.
void prim()
{
    vector<bool> isadd(N + 1, false);
    vector<int> maxw(N + 1, 0), parent(N + 1, -1);
    maxw[s] = 1e9;
    parent[s] = s;
    priority_queue<pair<int, int>> que;
    que.push({ maxw[s], s });

    while (!que.empty())
    {
        int w = que.top().first;
        int u = que.top().second;
        que.pop();

        // 이미 트리에 포함된 정점이거나 가중치가 현 최대값보다 작다면 무시한다.
        if (isadd[u] || w < maxw[u])
            continue;
        isadd[u] = true;
        // 도달할 수 있는 모든 간선들을 순회하며 가중치 별로 계산을 한다.
        for (int i = 0; i < board[u].size(); ++i)
        {
            int there = board[u][i].first;
            int weight = board[u][i].second;
            if (!isadd[there] && maxw[there] < weight)
            {
                parent[there] = u;
                maxw[there] = weight;
                que.push({ weight, there });
            }
        }
    }
    int answer = 1000001;
    while (e != s)
    {
        // 상술한대로 이 부분이 중요했다. 만약 도달하지 못한다면
        // 빼빼로를 준비할 수조차 없기에 0을 출력한다.
        if (parent[e] == -1)
        {
            cout << 0 << '\n';
            return;
        }
        answer = min(answer, maxw[e]);
        e = parent[e];
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> s >> e;
    for (int i = 0; i < M; ++i)
    {
        int from, to, k;
        cin >> from >> to >> k;
        board[from].push_back(make_pair(to, k));
        board[to].push_back(make_pair(from, k));
    }
    prim();
    return 0;
}