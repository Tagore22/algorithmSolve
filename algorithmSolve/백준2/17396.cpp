#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 처음에는 단순히 BFS를 떠올렸는데 생각해보니 가중치가 있었다. 물론 음수는 존재하지
// 않았기에 급하기 다익스트라로 눈을 돌렸다. 기존과는 한가지 다른점이 있었는데
// 연결은 되었으나 적의 시야에 노출되어 도달하면 안되는 정점이 그것이다.
// 처리하는 방식은 다음과 같이 2가지가 존재한다.

// 1. 입력받을 때에 걸러내어 벡터에 아예 넣지 않는 것.
// 2. 입력받을 때에 무시하고 다익스트라 알고리즘에서 다음 정점으로 이동시에 처리하는 것.

// 1번이 아예 연산량 자체가 줄어들 것으로 예상하여 속도 차이가 꽤 날거라고 생각했는데
// 딱히 그렇진 않았다. 아래 풀이는 상술한 2번 풀이이다. 또한, 가중치는 최대 10만인데
// 간선의 최대치는 30만이므로 int값을 아득히 벗어난다. 이 부분을 제대로 보지 않아
// 헤맸다.

// 자세한 설명은 주석으로 남긴다.

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
            // 적의 시야에 노출되어 연결은 되었으나 도달할 수 없는 정점을 찾아낸다.
            if (there != N - 1 && cantgo[there])
                continue;
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
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
    DK();
    return 0;
}