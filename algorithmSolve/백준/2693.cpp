#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �� �׽�Ʈ���̽����� 10���� ���� �޾� ������ 3��° ū���� ����ϸ� �ȴ�.

int board[10];
int T;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        for (int i = 0; i < 10; ++i)
            cin >> board[i];
        sort(board, board + 10);
        cout << board[7] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}