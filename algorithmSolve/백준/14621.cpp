#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 운이 좋게도 어제 풀었던 최소 스패닝 트리 문제가 또나왔다.
// 기본적으로는 크게 차이가 없으나 2가지 차이점이 존재했다.

// 1. 더 최소한의 가중치를 가지더라도 남학교 -> 남학교 혹은 여학교 -> 여학교는 연결이 불가능함.
// 2. 트리가 구성되지 않을 경우를 비교해야함.

// 1번째는 크게 어렵지 않았다. 학교수만큼 배열을 하나 만들어서 남학교와 여학교의 차이를 둔후
// 현재 정점 u에서 도달가능한 v를 순회할때 두학교가 같은지 다른지만 비교하면 됐다.
// 2번째가 조금 헷갈렸는데 결과적으로는 각 학교들의 최소 가중치를 확인하는 것이다.
// 초창기에 987654321으로 아주 큰 수로 둔 후 모든 정점수만큼의 순회가 끝난 이후
// 최소 가중치가 그대로 987654321이라면 도달도 이동도 불가능한 것이므로 트리를 이룰수 없다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<pair<int, int>>> board;
bool isMan[1001];
int N, M;

void MakeAnswer()
{
    // 모든 최소 가중치들의 총합.
    int answer = 0;
    vector<int> min_dist(N + 1, 987654321);
    min_dist[1] = 0;
    vector<bool> visit(N + 1, false);

    // 매번 하나의 정점을 트리에 추가하기 때문에 결과적으로 정점의 수만큼 순회한다.
    for (int iter = 0; iter < N; ++iter)
    {
        int u = -1;
        // 다른 모든 정점들을 순회하며 이번에 추가할 정점을 찾는다.
        for (int v = 1; v <= N; ++v)
            // 아직 트리에 추가되지 않은 첫번째 정점이거나, 이전 정점보다 최소 가중치가 적다면
            // 현재 정점이 변경된다.
            if (!visit[v] && (u == -1 || min_dist[u] > min_dist[v]))
                u = v;

        // 현재 정점의 최소 가중치를 추가하고 트리에 추가한다.
        answer += min_dist[u];
        visit[u] = true;

        // 현재 정점 u에서 도달가능한 모든 정점들을 순회한다.
        for (int i = 0; i < board[u].size(); ++i)
        {
            int v = board[u][i].first;
            int cost = board[u][i].second;
            // 아직 트리에 추가되지 않은 정점들중 u에서 이동한 가중치가 기존의 최소 가중치보다 작으며
            // 남 -> 남 혹은 여 -> 여가 아닐때 최소가중치를 현재 가중치로 변경한다.
            if (!visit[v] && min_dist[v] > cost && isMan[u] != isMan[v])
                min_dist[v] = cost;
        }
    }
    // 모든 정점들을 순회한다.
    for (int i = 1; i <= N; ++i)
    {
        // 현재 정점의 최소 가중치가 987654321이라면 즉,
        // 현재 정점으로 이동하지 못하는 경우 트리를 만들수없다.
        if (min_dist[i] == 987654321)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    char p;
    for (int i = 1; i <= N; ++i)
    {
        cin >> p;
        isMan[i] = p == 'M' ? true : false;
    }
    board.resize(N + 1, vector<pair<int, int>>());
    int from, to, dist;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> dist;
        board[from].push_back(make_pair(to, dist));
        board[to].push_back(make_pair(from, dist));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}