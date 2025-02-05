#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 오랜만에 그래프 탐색 문제다. 이 문제는 크게 다음과 같이 2가지로 나누어 풀어야 한다.

// 1. 2곳을 고른다.
// 2. 그 때의 얻을수 있는 상대의 돌의 개수를 구한다.

// 첫번째는 간단하게 백트래킹으로 구현하였다. 이때 빈칸에만 돌을 둘수 있기 때문에 반드시
// 원소값이 0인 좌표만을 골라야 한다.
// 두번째는 BFS로 구현하였는데 아래 2가지를 주의해야한다.

// 1. 주변이 1일때에는 그냥 continue를 이용하여 넘기면 되지만 0인 경우는 정답에 포함되지 않고 무시해야하면서도
// 방문을 해두어야 제대로 된 값을 구할수 있다. 0이라고 그냥 무시하고 BFS를 탈출하면 후에 이 부분에 포함된 원소값이
// 2인 좌표를 기준으로 BFS가 호출되었을때 cur가 늘어날 가능성이 존재하기 때문이다.
// 2. BFS로 돌의 개수를 구할때 이미 방문한곳은 피해야한다.

// 상술한 내용을 그대로 구현하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[20][20], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool visit[20][20] = { false, };
int N, M, answer = 0;

// y, x에서 시작하는 얻을수 있는 돌의 개수를 구하는 BFS 함수.
int BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;
    int ans = 1;
    bool isfind = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // 상하좌우 4방향으로 순회하며 이동한다.
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // 범위값을 벗어났거나 1로 막혀있다면 더이상 나아가지 못한다.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] ||
                board[ny][nx] == 1)
                continue;
            // 0이라면 현재 BFS내에서 얻을수 있는 돌의 개수는 0이다. 하지만 후의 재방문을
            // 막기 위해 바로 나가지 않고 방문할수 있는 모든 곳을 방문한다. 예를 들어 아래와 같을때
            // 0 2 1
            // 1 2 1
            // 1 1 1 
            // 위와 같은 상황일때 가장 먼저 0, 1 좌표의 2에서 BFS가 시작된다. 이때 상하좌우에서 왼쪽이
            // 가장 먼저 실행되는데 0이기 때문에 무시한다. 그 이후 1, 1의 2에서 다시 BFS가 시작된다.
            // 이 위치는 0, 1과 함께 버려져야하는 2지만, 실제로는 왼쪽, 아래, 오른쪽은 1로 막혀있고
            // 위의 2는 이미 방문한 곳이기에 아무 문제 없이 BFS에서 1을 반환하게 되어 틀린 답을 
            // 제출하게 된다. 따라서 0과 인접한 버려져야하는 2들도 바로 탈출하지 않고 isfind 변수를 통해
            // 버려져야함을 갱신만한 이후 똑같이 방문해야 한다.
            if (board[ny][nx] == 0)
            {
                isfind = false;
                continue;
            }
            ++ans;
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
    // isfind의 값에 의해 정수가 반환된다.
    return isfind ? ans : 0;
}

void MakeAnswer()
{
    // N * M으로 좌표값을 구한다. 다만 두번째 좌표 second는 무조건 first + 1부터 시작하여
    // 중복을 막는다.
    for (int first = 0; first < N * M; ++first)
    {
        int fy = first / M, fx = first % M;
        if (board[fy][fx] != 0)
            continue;
        board[fy][fx] = 1;
        for (int second = first + 1; second < N * M; ++second)
        {
            int sy = second / M, sx = second % M;
            if (board[sy][sx] != 0)
                continue;
            board[sy][sx] = 1;
            memset(visit, false, sizeof(visit));
            int cur = 0;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (board[i][j] == 2 && !visit[i][j])
                        cur += BFS(i, j);
                }
            }
            answer = max(answer, cur);
            board[sy][sx] = 0;
        }
        board[fy][fx] = 0;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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