#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// BFS로 격자들을 순회하여 산봉우리들의 개수를 찾는 문제다. BFS순회의 조건은 다음과 같다.

// 1. 좌표값을 벗어났거나, 값이 같은 좌표를 재방문할때, 인접한 좌표값이 현재 좌표값보다 작을때에는 무시한다.
// 2. 인접한 좌표값이 현재 좌표값보다 클때에는 산봉우리가 될수 없으므로 bool 변수 isFind를 false로 갱신후
// 무시한다.

// 모든 좌표값을 순회하며 방문하지 않은 좌표를 만났을때 BFS 순회를 해주면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100][70];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int N, M, answer = 0;
bool visit[100][70] = { false, };
bool isFind = true;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 8; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // 좌표값을 벗어났거나, 인접한 좌표값이 현재 좌표값보다 작거나, 값이 같은 곳을 재방문할때에는
            // 무시한다.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] < board[y][x]
                || (visit[ny][nx] && board[ny][nx] == board[y][x]))
                continue;
            // 인접한 좌표값이 클때 현재 좌표는 산봉우리가 될수 없으므로 isFind를 false로 갱신후
            // 무시한다.
            if (board[ny][nx] > board[y][x])
            {
                isFind = false;
                continue;
            }
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void MakeAnswer()
{
    // 모든 좌표들을 순회하며 아직 방문하지 않은 곳에서 BFS순회를 하여
    // 산봉우리들의 개수를 찾는다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (!visit[i][j])
            {
                isFind = true;
                BFS(i, j);
                if (isFind)
                    ++answer;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}