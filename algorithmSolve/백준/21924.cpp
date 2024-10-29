#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 문제를 본순간 MST문제라는 것을 알아챌수 있었다. 다만 한가지 문제가 있었는데 종만북에 나와있는
// 프림 풀이로는 시간초과가 걸린다는 것이었다. 조금 어이가 없었다. 그래서 간략하게 말만 나와 있는
// 우선순위 큐를 이용한 프림을 이용해야 했다. 다행히도 예전에 풀었더 적이 있었고 그대로 응용했다.
// 앞으로 프림은 이 방식을 사용해야겠다. 오히려 기존 프림보다 더 짧고 간단한 느낌도 있다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[100001];
int N, M;
long long answer = 0;

void Prim()
{
    // 시작점에서 시작하지 않고 시작점에서 도달할수 있는 모든 정점에서 시작한다.
    priority_queue<pair<int, int>> que;
    for (auto& here : board[1])
    {
        int cur = here.first;
        int cost = here.second;
        que.push(make_pair(-cost, cur));
    }
    bool visit[100001] = { false, };
    visit[1] = true;
    long long ans = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (visit[here])
            continue;

        // 이것을 아래 for문안의 if문에 옮기는게 더 빠를수도 있지 않을까 생각했으나
        // 그러면 제대로 작동하지 않는다. 우선순위 큐를 이용하기 때문에 일단 도달가능한
        // 모든 정점들을 큐에 넣고 가장 빠른 정점이 먼저 나왔을때 방문여부를 갱신하기 때문이다.
        visit[here] = true;
        ans += cost;

        for (auto& next : board[here])
        {
            int there = next.first;
            int dist = next.second;
            if (!visit[there])
                que.push(make_pair(-dist, there));
        }
    }
    for (int i = 1; i <= N; ++i)
        if (!visit[i])
        {
            cout << -1 << '\n';
            return;
        }
    cout << answer - ans << '\n';
}

void MakeAnswer()
{
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, dist;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> dist;
        board[from].push_back(make_pair(to, dist));
        board[to].push_back(make_pair(from, dist));
        answer += dist;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}