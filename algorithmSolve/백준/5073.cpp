#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���ǿ� �´� ���ڿ��� ����ϸ� �ȴ�.

int board[3];

void MakeAnswer()
{
    while (true)
    {
        cin >> board[0] >> board[1] >> board[2];
        if (board[0] == 0 && board[1] == 0 && board[2] == 0)
            break;
        sort(board, board + 3);
        if (board[2] >= board[1] + board[0])
            cout << "Invalid" << '\n';
        else if (board[0] == board[1] && board[1] == board[2])
            cout << "Equilateral" << '\n';
        else if (board[0] == board[1] || board[1] == board[2] || board[2] == board[0])
            cout << "Isosceles" << '\n';
        else
            cout << "Scalene" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}