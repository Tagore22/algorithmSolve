#include <iostream>
#include <algorithm>

using namespace std;


// Ǯ��.
// ó������ �̵ �ﰢ��, ��Ÿ����� ��Ģ ��� ���� ���͵� �� ���÷Ⱦ�����, �ﰢ���� ������Ģ�̶�°� �־���.
// ���� �����ߴµ� ������ ������ ���� �� ���� ���̰� ������ �κ��� ������ �պ��� �۾ƾ��Ѵٴ� ���̴�.
// ���� �� ������ ���� �Է¹޾Ƽ� ������������ �����Ͽ� board[2]���� ���� ������ ������ �����Ͽ� ���� ����ϸ� �ȴ�.

int board[3];

int main()
{
    for (int i = 0; i < 3; ++i)
        cin >> board[i];

    sort(board, board + 3);
    if (board[2] < board[0] + board[1])
        cout << board[0] + board[1] + board[2] << '\n';
    else
        cout << board[0] + board[1] + board[0] + board[1] - 1 << '\n';
    return 0;
}