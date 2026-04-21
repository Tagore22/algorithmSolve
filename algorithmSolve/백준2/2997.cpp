#include <iostream>
#include <algorithm>

using namespace std;

int board[3];

int main()
{
    for (int i = 0; i < 3; ++i)
        cin >> board[i];
    sort(board, board + 3);
    if (board[1] - board[0] == board[2] - board[1])
    {
        cout << board[2] + board[2] - board[1] << '\n';
    }
    else
    {
        if (board[1] - board[0] == (board[2] - board[1]) * 2)
            cout << board[0] + board[2] - board[1] << '\n';
        else
            cout << board[1] + board[1] - board[0] << '\n';
    }
    return 0;
}