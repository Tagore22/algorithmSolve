#include <iostream>

using namespace std;

// Ǯ��.
// ó������ BFS�� �̿��ؼ� Ǯ���µ�, �ǵ�� �������� ���� �׷� �ʿ䰡 ���ٴ°� ���޾Ҵ�.
// ��Ÿ���� �ּҷ� �Ѵٴ��� �ϴ� ������ �ƴϱ⿡ �����ϰ� ���� �αٿ� ��Ÿ���� ��� �Ĺ����� �Ǳ� �����̴�.

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