#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// BFS를 이용한 그래프 문제다.
// 친절하게도 사람이 먼저 이동하는지 벽이 먼지 이동하는지까지도 알려주었다.
// 풀이는 간단하게 큰틀만 보자면 다음과 같다.

// 1. 사람이 먼저 움직일수 있는 조건을 만족하는 이동을 한다. 이때 목적지에 도착했다면 true를 반환한채 함수를 끝낸다.
// 2. 벽이 이동한다.
// 3. 반복한다.

// 다만 한가지 문제가 있었는데 처음에는 각 좌표를 dp로 구현했었다. 하지만
// 가만히 있는다던가 하는 문제로 전혀 먹혀들지 않았기에 dp를 없앴다.
// 그 결과 que에서 무수한 연산이 일어나 속도도 느려지고 용량도 어마어마해졌다.
// 그 해결 결과는 다음 풀이에 있다.

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
    queue<pair<int, int>> que;
    que.push(make_pair(7, 0));

    while (!que.empty())
    {
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 현재 도달한 곳이 벽으로 막혔다면 더이상의 이동이 불가능하다.
            if (board[y][x] == '#')
                continue;

            // 이동할수 있는 곳을 모두 시도해본다.
            for (int i = 0; i < 9; ++i)
            {
                int dy = y + trans[i][0];
                int dx = x + trans[i][1];

                // 조건을 만족시키는 이동만이 실제로 행해진다.
                if (dy < 0 || dy > 7 || dx < 0 || dx > 7 || board[dy][dx] == '#')
                    continue;

                // 목적지에 도달하였다면 true를 반환하며 함수를 끝낸다.
                if (dy == 0 && dx == 7)
                    return true;

                que.push(make_pair(dy, dx));
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