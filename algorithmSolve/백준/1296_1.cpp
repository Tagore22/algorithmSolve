#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// 1926번의 BFS풀이.
// 1926.cpp에 기록하였듯 재귀횟수가 많이 때문에
// 오히려 BFS풀이가 더 가볍다.

bool board[500][500];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
bool visit[500][500];
int N, M;

int BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;
    int ans = 1;

    while (!que.empty())
    {
        int cur_y = que.front().first;
        int cur_x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = cur_y + rot[i][0];
            int dx = cur_x + rot[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= M || !board[dy][dx] || visit[dy][dx])
                continue;

            visit[dy][dx] = true;
            que.push(make_pair(dy, dx));
            ++ans;
        }
    }
    return ans;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    int num = 0, answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] && !visit[i][j])
            {
                ++num;
                answer = max(answer, BFS(i, j));
            }
    cout << num << '\n';
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int cur;
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