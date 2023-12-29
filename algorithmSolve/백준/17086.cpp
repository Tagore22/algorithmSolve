#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 처음에 문제를 이해못해서 한참 헤맸다. 상어들 사이의 안전거리를 구하는줄 알았는데
// 빈칸에서 가장 가까운 상어와의 거리를 안전거리라고 할때 가장 큰 안전거리를 가지는 칸의
// 안전거리를 구하는 것이었다. 각 상어들의 위치를 구하여 모두 BFS순회를 하되 각 칸은
// 매번 최소값으로 갱신하였다. 그런데 굳이 이럴 필요가 없었다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
vector<pair<int, int>> shark;
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int N, M;

// BFS순회를 하는 함수.
void BFS(int y, int x)
{
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    visit[y][x] = true;
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(y, x), 0));

    while (!que.empty())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int cost = que.front().second;
        que.pop();

        // 8방향으로 모두 이동해본다.
        for (int i = 0; i < 8; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 이동한 위치가 배열값을 벗어났거나 이미 방문한 위치라면 무시한다.
            if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx])
                continue;

            // 방문 여부를 갱신하고 각 칸의 최소 안전거리를 갱신한다.
            visit[dy][dx] = true;
            board[dy][dx] = min(board[dy][dx], cost + 1);
            // 큐에 새로 집어넣는다.
            que.push(make_pair(make_pair(dy, dx), cost + 1));
        }
    }
}

void MakeAnswer()
{
    // 모든 상어수만큼 BFS순회를 한다.
    for (auto p : shark)
        BFS(p.first, p.second);

    // 각 상어들이 위치한 칸은 제외시킨다.
    for (auto p : shark)
        board[p.first][p.second] = -1;

    // 모든 칸을 순회하며 가장 큰 수를 찾는다.
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            answer = max(answer, board[i][j]);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(M, 987654321));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int point;
            cin >> point;
            if (point == 1)
                shark.push_back(make_pair(i, j));
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}