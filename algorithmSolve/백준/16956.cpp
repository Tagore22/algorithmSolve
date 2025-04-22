#include <iostream>

using namespace std;

// 풀이.
// 처음에는 BFS를 이용해서 풀었는데, 피드백 과정에서 굳이 그럴 필요가 없다는걸 깨달았다.
// 울타리를 최소로 한다던가 하는 문제가 아니기에 간단하게 늑대 인근에 울타리를 모두 쳐버리면 되기 때문이다.

char board[500][500];
int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int R, C;

void Solve()
{
    for (int y = 0; y < R; ++y)
    {
        for (int x = 0; x < C; ++x)
        {
            if (board[y][x] == 'W')
            {
                for (int i = 0; i < 4; ++i)
                {
                    int ny = y + dir[i][0];
                    int nx = x + dir[i][1];

                    if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                        continue;
                    if (board[ny][nx] == 'S')
                    {
                        cout << 0 << '\n';
                        return;
                    }
                    else if (board[ny][nx] == '.')
                    {
                        board[ny][nx] = 'D';
                    }
                }
            }
        }
    }
    cout << 1 << '\n';
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            cout << board[i][j];
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}