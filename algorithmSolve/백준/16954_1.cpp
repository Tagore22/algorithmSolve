#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 16954번의 더 빠르며 용량도 더적은 풀이.
// dp의 해답은 시간초에 있었다. 그렇다면 최대 초가 몇초인지를 알아야 하는데
// 그것은 다음과 같은 이유로 간단하게 구할수 있다.

// 1. 매초 벽이 내려온다.
// 2. 미로는 가로세로 8칸이다.
// 3. 따라서 8초를 벽에 갇히지 않은채로 버틴다면 미로에 벽은 존재하지 않게 되고
// 목적지에 무조건 도달할수 있게 된다.
// 4. 따라서 초는 최대 8초이다.

// 이렇게 dp를 이용하여 더 빠르게 구할수 있다.

// 자세한 설명은 주석으로 남긴다.

char board[8][8];
int trans[9][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {0, 0} }; // 위쪽부터 시계방향으로.

// 벽의 이동을 구현하는 함수.
void MoveWall()
{
    for (int i = 7; i > 0; --i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = board[i - 1][j];

    for (int i = 0; i < 8; ++i)
        board[0][i] = '.';
}

bool BFS()
{
    bool visit[8][8][9];
    memset(visit, false, sizeof(visit));
    visit[7][0][0] = true;
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(7, 0), 0));

    while (!que.empty())
    {
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int y = que.front().first.first;
            int x = que.front().first.second;
            int cost = que.front().second;
            que.pop();

            // 8초를 버티어냈다면 모든 벽이 사라졌으므로 무조건 이동이 가능하다.
            if (cost >= 8)
                return true;

            // 현재 도달한 곳이 벽으로 막혔다면 더이상의 이동이 불가능하다.
            if (board[y][x] == '#')
                continue;

            // 이동할수 있는 곳을 모두 시도해본다.
            for (int i = 0; i < 9; ++i)
            {
                int dy = y + trans[i][0];
                int dx = x + trans[i][1];

                // 조건을 만족시키는 이동만이 실제로 행해진다.
                if (dy < 0 || dy > 7 || dx < 0 || dx > 7 || board[dy][dx] == '#' || visit[dy][dx][cost + 1])
                    continue;

                // 목적지에 8초 이전에 도달하였다면 true를 반환하며 함수를 끝낸다.
                if (dy == 0 && dx == 7)
                    return true;

                visit[dy][dx][cost + 1] = true;
                que.push(make_pair(make_pair(dy, dx), cost + 1));
            }
        }

        // 여기서 한칸씩 벽이 이동.
        MoveWall();
    }

    return false;
}

void MakeAnswer()
{
    bool answer = BFS();

    cout << (answer ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}