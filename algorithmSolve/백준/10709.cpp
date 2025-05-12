#include <iostream>

using namespace std;

char board[100][100];
int H, W;

void Solve()
{
    for (int i = 0; i < H; ++i)
    {
        int cur = -1;
        for (int j = 0; j < W; ++j)
        {
            if (board[i][j] == 'c')
            {
                cur = 0;
            }
            else
            {
                if (cur != -1)
                    ++cur;
            }
            cout << cur << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    for (int i = 0; i < H; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < W; ++j)
        {
            board[i][j] = str[j];
        }
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}