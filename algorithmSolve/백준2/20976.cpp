#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int board[3];
    cin >> board[0] >> board[1] >> board[2];
    sort(board, board + 3);
    cout << board[1] << '\n';
    return 0;
}