#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 길을 건너는 경우를 제외하고 각 소의 시작점에서 도달할수 있는 모든 좌표들을 방문한다.
// 그 이후 다른 소의 위치를 순회하며 도달했는지 확인하면 된다. 처음에는 연산량을 줄이기 위해
// 이전 소의 순회에서 방문한 지역은 BFS 순회를 제외하는 방식으로 구현했는데 다시 생각해보면
// 1번째 소의 순회에서 방문한 지역과 2번째 소의 순회에서 방문한 지역은 같지 않을수도 있다.
// 이런 상황에서 각 소들을 순회하며 방문한 소의 위치가 2번째 소의 순회일수도 있고
// 1번째 소의 순회일수도 있는데 2번째 소와 만날수 있다는건 잘못된 방식이기 때문이다.

// 자세한 설명은 주석으로 남긴다.

// 각 좌표에서 이동할수 없는, 건너야만 하는 좌표를 저장하는 벡터 배열.
vector<pair<int, int>> board[101][101];
pair<int, int> cow[100];
int N, K, R;
bool visit[101][101] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    // 각 방문 여부를 초기화한다.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            visit[i][j] = false;
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // 현재 좌표에서 이동하려는 좌표가 길을 건너야하는 곳이라면
            // 무시한다.
            bool bCango = true;
            for (auto& c : board[y][x])
            {
                if (c.first == ny && c.second == nx)
                {
                    bCango = false;
                    break;
                }
            }
            if (ny <= 0 || ny > N || nx <= 0 || nx > N || visit[ny][nx] || !bCango)
                continue;

            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K - 1; ++i)
    {
        // i번째 소의 위치에서 BFS 순회로 방문할수 있는 모든 곳을 방문하고
        // i + 1번부터 방문하지 못한 소들의 위치를 계산한다.
        // (i, j), (j, i) 같은 중복을 막기 위해 반드시 i + 1번째부터 순회해야한다.
        BFS(cow[i].first, cow[i].second);

        for (int j = i + 1; j < K; ++j)
            if (!visit[cow[j].first][cow[j].second])
                ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> R;
    int r1, c1, r2, c2;
    for (int i = 0; i < R; ++i)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        board[r1][c1].push_back(make_pair(r2, c2));
        board[r2][c2].push_back(make_pair(r1, c1));
    }
    for (int i = 0; i < K; ++i)
        cin >> cow[i].first >> cow[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}