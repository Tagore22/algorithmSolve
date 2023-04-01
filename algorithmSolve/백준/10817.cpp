#include <iostream>
#include <algorithm>

using namespace std;

int board[3];

void MakeAnswer()
{
    sort(board, board + 3);
    cout << board[1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}