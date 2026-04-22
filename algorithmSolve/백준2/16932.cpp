// 1. 상하좌우 4방향으로 연결된 곳이 인접한 곳.
// 2. 칸의 값이 1인 곳들을 연결한 것이 모양.
// 3. 주어진 배열에서 단 하나의 칸을 골라 수를 뒤집어 만들 수 있는 가장 큰 모양의 크기를 출력.

// 1. 모든 칸을 순회하며 칸의 값이 1이라면 BFS를 순회한다. 이 때 또다른 int 배열을 이용하여
// 배열의 위치값이 0일때에만 BFS를 호출하여 중복순회를 막고 매 순회시 벡터에 위치들을 넣어놓는다. 
// 2. 순회가 종료되면 모양의 크기를 알 수 있는데 이 후 벡터를 순회하여 각 위치에
// 크기를 저장한다.
// 3. 이후 다시 모든 칸을 순회하며 현재 칸의 값이 0인 칸들중 4방향의 모양 크기를 모두 더한곳중
// 가장 큰 값을 출력한다.
// 4. 3번에서 더할때 상우하좌 순으로 더하되, 현재 더하려는 곳이 이전과 연결되어있다면 무시한다.
// 5. num[][]는 단순 int가 아니라 pair<int, int>로 바꾸어서 각 모양들의 순번 역시 기록한다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 오랜만에 더럽게 복잡한 문제였다. 요약하자면 배열에서 단 한칸만 수를 뒤집었을 때, 인접한 1이 가장
// 큰 값을 출력하는 것이다. 생각의 로그는 위에 그때그때 정리해놓았다. 이러니 확실히 생각을 줄일 수 있었다.
// 다음에도 유용하게 써먹자.

int N, M, idx = 0;
int board[1000][1000], rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
pair<int, int> num[1000][1000];
bool visit[1000][1000] = { false, };

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push({ y, x });
    visit[y][x] = true;
    vector<pair<int, int>> pos = { {y, x} };
    int sum = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] || board[ny][nx] == 0)
                continue;

            visit[ny][nx] = true;
            que.push({ ny, nx });
            pos.push_back({ ny, nx });
            ++sum;
        }
    }

    for (const auto& here : pos)
        num[here.first][here.second] = { idx, sum };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 1 && num[i][j].second == 0)
            {
                ++idx;
                BFS(i, j);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 0)
            {
                vector<int> check;
                int ans = 0;
                for (int k = 0; k < 4; ++k)
                {
                    int ni = i + rot[k][0];
                    int nj = j + rot[k][1];

                    if (ni < 0 || ni >= N || nj < 0 || nj >= M)
                        continue;
                    bool isvisited = false;
                    int here = num[ni][nj].first;
                    for (int z = 0; z < check.size(); ++z)
                    {
                        if (check[z] == here)
                        {
                            isvisited = true;
                            break;
                        }
                    }
                    if (isvisited)
                        continue;
                    check.push_back(here);
                    ans += num[ni][nj].second;
                }
                ++ans;
                answer = max(answer, ans);
            }
        }
    }
    cout << answer << '\n';
    return 0;
}