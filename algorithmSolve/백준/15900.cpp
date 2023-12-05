#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 풀이.
// 언뜻 보면 게임이론 문제 같으나 그래프 탐색 문제다. 모든 게임말을 플레이어가 공유하므로
// 각 리프 노드에서 루트 노드까지의 이동거리가 홀수라면 이기고 짝수라면 지게 된다.
// 따라서 각 루트 노드에서 리프 노드까지의 총 이동거리를 구하면 된다.
// 그런데 여기서 기본적인 그래프 탐색 문제와는 다른 부분이 존재한다.
// 예제 2번을 보면 1번이 루트 노드이며 그 자식이 2번 노드이고 그 자식들이 각 3번과 4번이다.
// 실제 총 이동거리는 4지만 기본적인 DFS, BFS를 이용하면 이동거리는 3이 나온다.
// 1번에서 2번으로 이동하는 간선이 2번 더해져야 하기 때문이다. 이 부분에서 조금 헷갈렸다.
// 정답은 실제 이동거리를 각 재귀마다 가지고 있는 것이었다. 그 이후 현재 노드가 리프 노드라면
// 이동거리를 총 이동거리 answer에 더해주고 탈출하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
bool visit[500001];
int N, answer = 0;

void DFS(int here, int dist)
{
    // 현재 방문한 노드의 방문 여부를 갱신하고 이동 가능여부를 false로 초기화한다.
    visit[here] = true;
    bool isMove = false;

    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (!visit[there])
        {
            // 이동이 가능함을 갱신하고, 재귀호출을 한다.
            isMove = true;
            DFS(there, dist + 1);
        }
    }
    // 현재 이동이 불가능했다면 리프 노드이므로 이동거리를 총 이동거리 answer에 더한다.
    if (!isMove)
        answer += dist;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    DFS(1, 0);
    // 총 이동거리가 홀수라면 승리하고 짝수라면 패배한다.
    if (answer % 2 == 1)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    int a, b;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}