#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 간단한 그래프 탐색 문제이다. BFS로 탐색가능한 모든 곳을 탐색하며 방문가능한 P의 수를 출력하며 된다.

// 자세한 설명은 주석으로 남긴다.

char board[600][600];
int N, M;
pair<int, int> from;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌, 상, 우, 하.

// BFS 순회 함수.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    bool visit[600][600];
    memset(visit, false, sizeof(visit));
    visit[from.first][from.second] = true;
    int answer = 0;

    while (!que.empty())
    {
        pair<int, int> here = que.front();
        que.pop();

        // 좌, 상, 우, 하 4곳을 모두 방문해본다.
        for (int i = 0; i < 4; ++i)
        {
            int y = here.first + rot[i][0];
            int x = here.second + rot[i][1];

            // 배열값을 벗어났거나, 이미 방문했거나, 벽이라면 무시한다.
            if (y < 0 || y >= N || x < 0 || x >= M || visit[y][x] || board[y][x] == 'X')
                continue;
            // 사람이라면 최종값 answer를 1 증가시킨다.
            if (board[y][x] == 'P')
                ++answer;
            // 방문 여부를 갱신하고 큐에 넣는다.
            visit[y][x] = true;
            que.push(make_pair(y, x));
        }
    }
    if (answer != 0)
        cout << answer << '\n';
    else
        cout << "TT" << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'I')
                from = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}