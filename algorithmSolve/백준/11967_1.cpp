#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 11967번의 더 나은 풀이.
// 기존에는 불은 켜졌으나 방문하지 못한 방들을 deque에 모아서 매번 반복하였으나
// 이것은 같은 행위를 반복하는 것이었다. 불을 키거나 새로운 위치로 이동할때마다
// 인접한 4방향을 탐색하여 방문 여부를 갱신하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[101][101];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 왼쪽, 위쪽, 오른쪽, 아래쪽.
int N, M;

int BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(1, 1));
    vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
    vector<vector<bool>> isLight(N + 1, vector<bool>(N + 1, false));
    visit[1][1] = true;
    isLight[1][1] = true;
    int ans = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (auto next : board[y][x])
        {
            // 새롭게 불이 켜진 곳이라면
            if (!isLight[next.first][next.second])
            {
                // 불이 켜짐을 갱신하고 최종답 ans을 1 증가시킨다.
                isLight[next.first][next.second] = true;
                ++ans;

                // 인접한 4방향을 돌며 방문 가능한 곳을 찾는다.
                for (int i = 0; i < 4; ++i)
                {
                    int dy = next.first + rot[i][0];
                    int dx = next.second + rot[i][1];

                    // 배열 범위값을 벗어나거나 방문한적 없는 곳이라면 무시한다.
                    if (dy <= 0 || dy > N || dx <= 0 || dx > N || !visit[dy][dx])
                        continue;

                    // 인접한 4방향의 위치중 하나라도 방문한 곳이라면 바로 옆인 현재 위치도 방문이 가능하다.
                    visit[next.first][next.second] = true;
                    que.push(make_pair(next.first, next.second));
                    break;
                }
            }
        }

        // 현재 위치에서 4방향을 순회한다.
        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 배열 범위값을 벗어나거나 불이 켜지지 않은 곳이라면 무시한다.
            if (dy <= 0 || dy > N || dx <= 0 || dx > N || visit[dy][dx] || !isLight[dy][dx])
                continue;

            // 새롭게 방문할수 있는 곳들을 갱신한다.
            visit[dy][dx] = true;
            que.push(make_pair(dy, dx));
        }
    }
    return ans;
}

void MakeAnswer()
{
    int answer = BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    pair<int, int> from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from.first >> from.second >> to.first >> to.second;
        board[from.first][from.second].push_back(to);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}