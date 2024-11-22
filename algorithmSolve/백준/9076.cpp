#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int board[5];
    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        for (int i = 0; i < 5; ++i)
            cin >> board[i];
        sort(board, board + 5);
        if (board[3] - board[1] >= 4)
            cout << "KIN" << '\n';
        else
            cout << board[1] + board[2] + board[3] << '\n';
    }
    return 0;
}