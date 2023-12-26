#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 모든 친구들과 친구가 될 경우 요구되는 최소한의 친구비를 출력하는 문제다.
// 친구의 친구는 공짜라는 말은 친구의 무리가 있을 경우 그 무리중에서 가장 적은 친구비를 찾으면
// 그 무리의 모두와 친구가 된다는 것을 뜻한다. 즉 1번부터 N번까지 친구를 모두 순회하며 도달할수 있는
// 친구들중 가장 적은 친구비를 구해 더해나가면 된다.

// 자세한 설명은 주석으로 남긴다.

int cost[10001];
vector<vector<bool>> board;
vector<bool> visit;
int N, M, K, point;

// 각 친구의 친구들을 순회하는 함수.
void DFS(int here)
{
    // 현재 친구의 다른 친구들을 모두 순회한다.
    for (int there = 1; there <= N; ++there)
    {
        // 이미 방문한 친구거나 친구 사이가 아니라면 무시한다.
        if (visit[there] || !board[here][there])
            continue;
        // 현재 무리의 친구비들중 최소값을 갱신한다.
        point = min(point, cost[there]);
        visit[there] = true;
        DFS(there);
    }
}

void MakeAnswer()
{
    int answer = 0;
    // 모든 친구들을 순회한다.
    for (int iter = 1; iter <= N; ++iter)
    {
        // 현재 친구가 아직 방문하지 않은 친구라면.
        if (!visit[iter])
        {
            // 친구비의 최소값은 현재 친구의 친구값으로 시작한다.
            point = cost[iter];
            visit[iter] = true;
            DFS(iter);

            // 친구비의 최소값이 현재 가진 돈보다 많다면 모든 친구들을 사귈수 없다.
            if (point > K)
            {
                cout << "Oh no" << '\n';
                return;
            }
            // 친구비의 최소값을 최종값 answer에 더한다.
            answer += point;
            // 현재 가진 돈을 갱신한다.
            K -= point;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    board.resize(N + 1, vector<bool>(N + 1, false));
    visit.resize(N + 1, false);
    for (int i = 1; i <= N; ++i)
        cin >> cost[i];
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from][to] = true;
        board[to][from] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}