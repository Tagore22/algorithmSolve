#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 문제를 보면 알겠으나, 고슴도치와 물이 각각 동시에 움직여야 하기에 DFS가 아닌 BFS로 풀어야 하는 문제이다.
// 그래서 BFS로 구현하여 풀었으나 이상하게 메모리 초과가 나왔다. 초기에 있던 물의 위치를 파악하는 벡터들도
// 모두 삭제를 한채로 구현하였는데도 메모리 초과가 계속 나와서 뭐가 잘못되었는지 자세히 봤는데, BFS에서
// 4방향으로 이동시 왔던 방향으로 다시 돌아가는걸 방지하는 코드가 없었다. 그래서 무한으로 돌았고,
// 그로 인해 메모리 초과가 떴었다.

struct pos
{
    int y;
    int x;
    int cost;
};

char board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int R, C;
pair<int, int> S, D;

// 매 순간 고슴도치와 물이 이동하는걸 구현하는 함수.
int BFS()
{
    queue<pos> que;

    // 현재 물인 위치를 모두 큐에 집어 넣는다.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == '*')
                que.push(pos{ i, j, -1 });

    // 단 하나뿐인, 고슴도치의 위치를 넣는다. 중요한 것은 물과 고슴도치가 이동할수 있는 조건이
    // 다르기 때문에 이 둘을 구분해야한다는 것이다. 어차피 큐에는 3가지(y좌표, x좌표, 걸린 시간)가 필요하고,
    // 물은 시간이 필요하지 않기에 이곳에 무조건 -1을 두어 물과 고슴도치를 구분하였다.
    que.push(pos{ S.first, S.second, 0 });

    while (!que.empty())
    {
        int cur_y = que.front().y;
        int cur_x = que.front().x;
        int cur_cost = que.front().cost;
        que.pop();

        // 굴에 도달했다면 몇분이 걸렸는지 반환한다.
        if (cur_y == D.first && cur_x == D.second)
            return cur_cost;

        // 고슴도치와 물의 이동 조건이 다르기 때문에 어쩔수 없이 구분해야한다.
        // 현재 고슴도치라면.
        if (cur_cost != -1)
        {
            for (int i = 0; i < 4; ++i)
            {
                int dy = cur_y + rot[i][0];
                int dx = cur_x + rot[i][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == 'X' ||
                    board[dy][dx] == '*' || board[dy][dx] == 'S')
                    continue;

                board[dy][dx] = 'S';
                que.push(pos{ dy, dx, cur_cost + 1 });
            }
        }

        // 물이라면.
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                int dy = cur_y + rot[i][0];
                int dx = cur_x + rot[i][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == 'X' ||
                    board[dy][dx] == 'D' || board[dy][dx] == '*')
                    continue;

                board[dy][dx] = '*';
                que.push(pos{ dy, dx, cur_cost });
            }
        }
    }

    // 굴에 도달하지 못할 경우 -1을 반환하여 차이점을 둔다.
    return -1;
}

void MakeAnswer()
{
    int answer = BFS();

    if (answer != -1)
        cout << answer << '\n';
    else
        cout << "KAKTUS" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
                S = make_pair(i, j);
            else if (board[i][j] == 'D')
                D = make_pair(i, j);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}