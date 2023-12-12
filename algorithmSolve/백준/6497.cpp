#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 익숙치 않은 최소 스패닝 트리 문제였다. 말 그대로 트리를 이루는 최소 가중치를 구하는 알고리즘이다.
// 프림 알고리즘을 이용하였으나, 우선순위 큐를 이용하지도 않았기에 시간이 많이 걸린다.
// 크루스칼이나 우선순위 큐를 이용하여야겠다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<pair<int, int>>> board;
int M, N, answer;

// 최소 스패닝 트리를 구하는 프림 알고리즘.
void Prim()
{
    // 모든 최소 가중치는 최대로 초기화시킨다.
    vector<int> dist(M, 987654321);
    // 시작점의 가중치는 0으로 시작한다.(임의로 루트로 지정해도 되며 여기서 가중치는 부모정점에서 현재 정점으로의
    // 가중치를 뜻하기에 루트인 dist[0]은 0이 된다.)
    dist[0] = 0;
    vector<bool> visit(M, false);

    // 매번 각 정점을 트리에 추가하기 때문에 결과적으로 정점의 수만큼만 반복하면 된다.
    for (int iter = 0; iter < M; ++iter)
    {
        int u = -1;
        // 모든 정점을 순회한다.
        for (int v = 0; v < M; ++v)
            // 현재 정점이 트리에 아직 속하지 않은 첫번째 정점이거나, 현재까지 정점들의 가중치보다
            // 더작다면 현재 정점을 선택한다.
            if (!visit[v] && (u == -1 || dist[u] > dist[v]))
                u = v;

        // 이 문제는 기존의 모든 가중치에서 최소 가중치들의 합을 제외하여야 하기에 -= 연산을 사용한다.
        answer -= dist[u];
        // 가장 가중치가 적은 현재 정점을 트리에 포함시킨다.
        visit[u] = true;
        // 현재 정점에서 도달할수 있는 모든 정점을 순회한다.
        for (int i = 0; i < board[u].size(); ++i)
        {
            int v = board[u][i].first;
            int cost = board[u][i].second;
            // v가 아직 트리에 도달하지 않았으며 v의 최소 가중치가
            // cost보다 크다면 dist[v]를 갱신한다.
            if (!visit[v] && dist[v] > cost)
                dist[v] = cost;
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    while (true)
    {
        cin >> M >> N;
        if (M == 0 && N == 0)
            return;

        answer = 0;
        board.clear();
        board.resize(M, vector<pair<int, int>>());
        int from, to, dist;
        for (int i = 0; i < N; ++i)
        {
            cin >> from >> to >> dist;
            board[from].push_back(make_pair(to, dist));
            board[to].push_back(make_pair(from, dist));
            answer += dist;
        }

        Prim();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}