#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 정답율을 보면 알겠으나 쉽지 않은 문제다. 그래프 문제임에는 확실했다.
// 처음에는 BFS, DFS등의 그래프 순회를 생각했는데 왔던 곳을 다시 방문하기에 한참 헤맸다.
// 실제로는 최소 스패닝 트리를 이용해야 했다. 그러면 이전에 방문했던 정점에서 다른 곳으로 이동할수 있기 때문이다.
// 내림차순이 1이고 오름차순이 0인데 이걸 뒤바꿔양 문제 풀이가 수월했다. 

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[1001];
int N, M;

// 최대 피로도를 계산하는 함수.
int Prim_Max()
{
    // 가장 높은 피로도를 찾아야 하기 때문에 -1로 초기화 시킨다.
    vector<int> dist(N + 1, -1);
    dist[0] = 0;
    vector<bool> visit(N + 1, false);
    int ans = 0;

    for (int iter = 0; iter <= N; ++iter)
    {
        int u = -1;
        for (int v = 0; v <= N; ++v)
            // 아직 트리에 포함되지 않은 정점들중 가장 피로도가 높은 정점들 찾는다.
            if (!visit[v] && (u == -1 || dist[v] > dist[u]))
                u = v;

        visit[u] = true;
        ans += dist[u];

        // 새로 방문한 정점에서 도달가능한 정점들을 순회하며
        // 아직 방문하지 않은 정점들에 대한 피로도를 갱신한다.
        for (auto next : board[u])
        {
            int there = next.first;
            int cost = next.second;
            if (!visit[there] && cost > dist[there])
                dist[there] = cost;
        }
    }
    return ans;
}

// 최소 피로도를 계산하는 함수.
int Prim_Min()
{
    // 가장 높은 피로도를 찾아야 하기 때문에 1000로 초기화 시킨다.
    vector<int> dist(N + 1, 1000);
    dist[0] = 0;
    vector<bool> visit(N + 1, false);
    int ans = 0;

    for (int iter = 0; iter <= N; ++iter)
    {
        int u = -1;
        for (int v = 0; v <= N; ++v)
            // 아직 트리에 포함되지 않은 정점들중 가장 피로도가 낮은 정점들 찾는다.
            if (!visit[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visit[u] = true;
        ans += dist[u];

        // 새로 방문한 정점에서 도달가능한 정점들을 순회하며
        // 아직 방문하지 않은 정점들에 대한 피로도를 갱신한다.
        for (auto next : board[u])
        {
            int there = next.first;
            int cost = next.second;
            if (!visit[there] && cost < dist[there])
                dist[there] = cost;
        }
    }
    return ans;
}

void MakeAnswer()
{
    int max_num = Prim_Max();
    int min_num = Prim_Min();
    // 피로도는 기존의 구한 피로도의 제곱을 뜻한다. 따라서 최대 피로도뿐만 아니라
    // 최소 피로도 역시 제곱하여 계산해야한다.
    cout << max_num * max_num - min_num * min_num << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, isDownhill;
    for (int i = 0; i <= M; ++i)
    {
        cin >> from >> to >> isDownhill;
        board[from].push_back(make_pair(to, abs(isDownhill - 1)));
        board[to].push_back(make_pair(from, abs(isDownhill - 1)));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}