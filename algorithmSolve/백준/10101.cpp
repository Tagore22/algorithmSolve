#include <iostream>

using namespace std;

// Ǯ��.
// �� ���ǹ��� ���� if ~ else������ �Ÿ��� �ȴ�.

int board[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> board[i];

    if (board[0] == 60 && board[1] == 60 && board[2] == 60)
        cout << "Equilateral" << '\n';
    else if (board[0] + board[1] + board[2] == 180 && board[0] == board[1]
        || board[1] == board[2] || board[2] == board[0])
        cout << "Isosceles" << '\n';
    else if (board[0] + board[1] + board[2] == 180 && board[0] != board[1]
        && board[1] != board[2] && board[2] != board[0])
        cout << "Scalene" << '\n';
    else
        cout << "Error" << '\n';

    return 0;
}