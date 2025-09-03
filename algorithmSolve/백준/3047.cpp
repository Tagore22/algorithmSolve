#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int board[3];
    for (int i = 0; i < 3; ++i)
        cin >> board[i];
    string str;
    cin >> str;

    sort(board, board + 3);
    for (int i = 0; i < 3; ++i)
        cout << board[str[i] - 'A'] << ' ';

    cout << '\n';
    return 0;
}