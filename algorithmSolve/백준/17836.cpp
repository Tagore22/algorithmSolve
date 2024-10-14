#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 간단한 BFS문제였다. 다만 이상하리만치 정답율이 낮다. 25퍼가 안되는데 아마
// 검을 가지고 있을때와 그렇지 않을때를 다른 사람들이 생각못하는건가 싶었다.
// 어쨌든 간단하게 요약해보자면 BFS로 순회를 하되, 검이 있는지 없는지까지 해서 3차원 배열을
// 사용하여야 한다. 이동 조건문에도 검이 있을때에만 벽을 뚫게끔하면 된다. 한번 틀렸는데
// T시간안에 도달할수 없다면 Fail을 출력해야 하는데 이것을 깜빡했다. 풀이를 다시 보는것도 중요하지만
// 문제를 잘 읽어보자!

// 자세한 설명은 주석으로 남긴다.

struct pos
{
    int y;
    int x;
    int sword; // 없으면 0, 있으면 1;
};

int board[101][101];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, T;

void BFS()
{
    queue<pos> que;
    que.push(pos{ 1, 1, 0 });
    bool visit[101][101][2] = { false, };
    visit[1][1][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        // 상술한 실수. T시간까지 구하지 못한다면 while문을 탈출하여 바로 Fail을 출력한다.
        if (answer > T)
            break;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int sword = que.front().sword;
            que.pop();

            if (y == N && x == M)
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 좌표값을 벗어나거나, 중복방문이거나, 검이 없을때 벽을 만난다면 해당 위치로 이동하지 못한다.
                if (ny <= 0 || ny > N || nx <= 0 || nx > M || (sword == 0 && board[ny][nx] == 1) ||
                    visit[ny][nx][sword])
                    continue;

                // 이미 검을 가지고 있거나 다음 이동에서 검을 찾는다면 검을 지닌 상태가 된다.
                int next = (board[ny][nx] == 2 || sword == 1) ? 1 : 0;
                que.push(pos{ ny, nx, next });
                visit[ny][nx][next] = true;
            }
        }
    }
    cout << "Fail" << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}