#include <iostream>

using namespace std;

char board[10][10];
int R, C;
bool IsRand[10][10] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void CheckRand(int y, int x)
{
    int num = 0;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + rot[i][0];
        int nx = x + rot[i][1];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C || board[ny][nx] == '.')
            continue;
        ++num;
    }
    IsRand[y][x] = num >= 2 ? true : false;
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == 'X')
                CheckRand(i, j);

    int wmin = 11, wmax = -1, hmin = 11, hmax = -1;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (IsRand[i][j])
            {
                wmin = min(wmin, j);
                wmax = max(wmax, j);
                hmin = min(hmin, i);
                hmax = max(hmax, i);
            }
        }
    }
    for (int i = hmin; i <= hmax; ++i)
    {
        for (int j = wmin; j <= wmax; ++j)
            cout << (IsRand[i][j] ? 'X' : '.');
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
    MakeAnswer();
    return 0;
}