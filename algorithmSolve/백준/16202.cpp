#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// K번동안 최소 스패닝 트리를 계산한다. 이때 최소 스패닝 트리를 구할수 있다면 그 값을 출력하고
// 가장 짧은 가중치를 이후에 사용하지 못하게 최대값으로 갱신한다. 구할수 없다면 0을 출력한다.
// 아래 풀이는 프림 알고리즘으로 구현하였으나, 간선의 길이가 적기에 크루스칼 알고리즘이 더 빠를듯하다.

// 자세한 설명은 주석으로 남긴다.

struct ver
{
    int from;
    int to;
    int cost;
};

vector<pair<int, int>> V[1001];
int N, M, K;
const int MAXNUM = 987654321;

void Prim()
{
    bool visit[1001] = { false, };
    // from에서 시작하여 to까지 연결되는 cost길이의 가중치.
    vector<ver> dist(N + 1, ver{ -1, -1, MAXNUM });
    dist[1].cost = 0;
    // 현재 MST에서 가장 짧은 간선.
    ver edge = ver{ -1, -1, MAXNUM };
    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        // 시작값은 -1로 초기화
        int u = -1;
        for (int j = 1; j <= N; ++j)
        {
            if (!visit[j] && (u == -1 || dist[j].cost < dist[u].cost))
                u = j;
        }

        // 도달할수 있는 정점이 없다면 0을 출력한다.
        if (dist[u].cost == MAXNUM)
        {
            cout << 0 << ' ';
            return;
        }
        visit[u] = true;
        ans += dist[u].cost;
        if (u != 1 && dist[u].cost < edge.cost)
            edge = dist[u];

        for (auto& next : V[u])
        {
            int there = next.first;
            int len = next.second;
            if (dist[there].cost > len)
                dist[there] = ver{ u, there, len };
        }
    }
    cout << ans << ' ';
    // 가장 짧은 간선의 값을 갱신하여 이후 사용하지 않는다.
    for (auto& p : V[edge.from])
        if (p.first == edge.to)
            p.second = MAXNUM;
    for (auto& p : V[edge.to])
        if (p.first == edge.from)
            p.second = MAXNUM;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
        Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i)
    {
        int from, to;
        cin >> from >> to;
        V[from].push_back(make_pair(to, i));
        V[to].push_back(make_pair(from, i));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}