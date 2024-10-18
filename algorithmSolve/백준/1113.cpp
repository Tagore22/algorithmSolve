#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 쉽게 생각하면 꽤나 쉽고, 그렇지 않으면 무진장 어려운 문제였다. 내 안좋은점 중 하나인 후자를 통해서
// 어렵게 풀었다. 모든 좌표를 순회하되, 그곳에서 영역을 찾았다면 그 영역의 높이를 반환하는 BFS와
// 다시 한번 순회를 하며 그 높이값으로 조정하고, 이미 영역을 구했음을 갱신하는 BFS를 통해서 구현하였다.
// 중간에 조건문도 까다롭고 그래서 뭐랄까. 근성이 담겼으나 너무 어렵게 푼 방법 같다. 꽤나 끔찍했던 문제다.

// 자세한 설명은 주석으로 남긴다.

struct pos
{
    int y;
    int x;
    int h;
};

int board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool point[50][50] = { false, };
int N, M, answer = 0;

// y, x에서 시작하여 도달할수 있는 모든 좌표의 높이를 len으로 조정하는 함수.
void BFS_Plus(int y, int x, int len)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    bool visit[50][50] = { false, };
    visit[y][x] = true;
    // 매번 추가되는 값을 구한다.
    int ans = len - board[y][x];
    // 이 좌표값은 이미 영역에 들었음을 갱신한다.
    point[y][x] = true;
    // 좌표값의 높이를 갱신한다.
    board[y][x] = len;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 4방향 모두 순회한다.
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 좌표값을 벗어났거나, 이번 순회에서 중복방문이거나, 좌표값의 높이값이 len보다 크거나 같다면 무시한다.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] ||
                    board[ny][nx] >= len)
                    continue;

                // 방문과 영역에 들어섰음을 갱신한다.
                visit[ny][nx] = true;
                point[ny][nx] = true;
                // 큐에 집어넣고 높이값을 갱신하며, 추가되는 값을 계산한다.
                que.push(make_pair(ny, nx));
                ans += len - board[ny][nx];
                board[ny][nx] = len;
            }
        }
    }
    // 모든 추가값들을 최종값 answer에 더한다.
    answer += ans;
}

// y, x에서 만들수 있는 영역을 구하는 함수. 이곳이 매우 어려웠는데
// 예시 4번이 그 예였다. 예를 들어 3, 5에서 BFS를 시작한다면 결국 9보다 큰것이 없기에
// 무시되어야 한다. 하지만 기존에는 1에서 5로 바뀌는 순간 더 커지기 때문에 중복되는 새로운 영역이
// 생기게 되었었다. 이것을 방지하기 위해 새로운 좌표에 도달했을때 높이값을 비교하여 더 큰 높이값을
// 가지게 만들었다.
int BFS(int y, int x, int h)
{
    queue<pos> que;
    // 초기 좌표값과 높이값. 상술한대로 높이값은 점점 더 큰값으로 갱신되어간다.
    que.push(pos{ y, x, h });
    bool visit[50][50] = { false, };
    visit[y][x] = true;
    // 영역의 높이값. 공통되는 가장 작은 값이여야하기에 초기화값은 있을수 없는 가장큰 10이다.
    int len = 10;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int h = que.front().h;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 좌표값을 벗어났다면 영역을 만들수 없다. 따라서 -1을 반환한다.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    return -1;
                // 중복방문은 무시한다.
                if (visit[ny][nx])
                    continue;
                // 현재 최대 높이보다 더 높은 값을 만났다면 여기가 영역의 경계선이므로
                // 높이값을 갱신한다.
                if (board[ny][nx] > h)
                {
                    len = min(len, board[ny][nx]);
                }
                // 더 낮은 값이라면 영역에 포함되는 좌표기 때문에 높이값을 더 높은것으로 갱신하고
                // 큐에 넣는다.
                else
                {
                    visit[ny][nx] = true;
                    que.push(pos{ ny, nx, h });
                }
            }
        }
    }
    return len;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!point[i][j])
            {
                int len = BFS(i, j, board[i][j]);
                if (len != -1)
                    BFS_Plus(i, j, len);
            }
    cout << answer << '\n';
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
            board[i][j] = str[j] - 48;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}