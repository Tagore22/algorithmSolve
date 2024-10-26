#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int board[3];
    for (int i = 0; i < 3; ++i)
        cin >> board[i];
    sort(board, board + 3);
    cout << board[1] + board[2] << '\n';
    return 0;
}