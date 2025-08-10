#include <iostream>

using namespace std;

int main()
{
    int board[4];
    for (int i = 0; i < 4; ++i)
        cin >> board[i];

    if (board[0] < board[1] && board[1] < board[2] && board[2] < board[3])
        cout << "Fish Rising" << '\n';
    else if (board[0] > board[1] && board[1] > board[2] && board[2] > board[3])
        cout << "Fish Diving" << '\n';
    else if (board[0] == board[1] && board[1] == board[2] && board[2] == board[3])
        cout << "Fish At Constant Depth" << '\n';
    else
        cout << "No Fish" << '\n';
    return 0;
}