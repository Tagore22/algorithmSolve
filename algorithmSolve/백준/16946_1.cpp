#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// 16946번의 BFS풀이.
// 속도는 조금 더 느리지만 차지하는 메모리가 거의 3분의 1까지 줄어들었다.
// 재귀횟수가 늘어난다면 DFS보다 BFS를 사용하고
// 재귀횟수가 적다면 BFS보다 DFS를 사용하자.

int N, M, path;
int dp[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
bool board[1000][1000], visit[1000][1000];
vector<int> dps;

void BFS(int y, int x)
{
    ++path;
    visit[y][x] = true;
    int cur = dps.size();
    dp[y][x] = cur;
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx] || board[dy][dx])
                continue;

            visit[dy][dx] = true;
            dp[dy][dx] = cur;
            que.push(make_pair(dy, dx));
            ++path;
        }
    }
}

void CalDPAll()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!board[i][j] && !visit[i][j])
            {
                path = 0;
                BFS(i, j);
                dps.push_back(path);
            }
}

void MakeAnswer()
{
    CalDPAll();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j])
            {
                int answer = 1;
                set<int> check;
                for (int idx = 0; idx < 4; ++idx)
                {
                    int dy = i + rot[idx][0];
                    int dx = j + rot[idx][1];

                    if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx])
                        continue;

                    int cur = dp[dy][dx];
                    if (check.find(cur) == check.end())
                    {
                        answer += dps[cur];
                        check.insert(cur);
                    }
                }
                cout << answer % 10;
            }
            else
            {
                cout << 0;
            }
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}