#include <iostream>

using namespace std;

int board[2];

void MakeAnswer()
{
    cout << (board[0] >= board[1] ? board[0] : board[1]) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 2; ++i)
    {
        board[i] = 0;
        for (int j = 0; j < 4; ++j)
        {
            int a;
            cin >> a;
            board[i] += a;
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}