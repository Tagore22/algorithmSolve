#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 풀이
// 트리이기에 A에서 B로 도달하는 길이 2가지 이상일리는 없었다. 우선 각 노드에서 노드로 이어지는지조차 알수 없기에 2차원 배열의 시작값을
// -1로 두고(도달할수 없음) 입력에서 주어지는 길이를 양쪽 모두에 연결한다. (A, B, 2일시 board[A][B] = 2와 board[B][A] = 2)
// 그 후 주어지는 두 노드를 각 시작점과 끝점으로 두어 시작점에서 BFS()를 순회한다. 현재 노드를 here로 두어 아직 도달하지 않았고, 또한
// 도달할수 있는 모든 노드에 도달하여 끝점이 나올때까지 길이를 늘려간다.

int board[1001][1001];
bool check[1001];
int N, M, from, to;

void BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(from, 0));
    check[from] = true;
    while (!que.empty())
    {
        int here = que.front().first;
        int len = que.front().second;
        que.pop();

        if (here == to)
        {
            cout << len << '\n';
            return;
        }

        for (int there = 1; there <= N; ++there)
            if (board[here][there] != -1 && !check[there])
            {
                que.push(make_pair(there, len + board[here][there]));
                check[there] = true;
            }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        memset(check, false, sizeof(check));
        BFS();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, -1, sizeof(board));

    cin >> N >> M;
    for (int i = 0; i < N - 1; ++i)
    {
        int from, to, len;
        cin >> from >> to >> len;
        board[from][to] = len;
        board[to][from] = len;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}