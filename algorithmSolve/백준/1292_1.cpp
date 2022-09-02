#include <iostream>

using namespace std;

int board[1000];
int from, to;

//���� Ǯ�̹��� from�� 1�϶�, �� ������ ��ó���� ����ų�� �ε������� -1�� �迭���� �����.
//�׳� �迭�� Ǯ���� ������ �¾�����, �ε��� ���� ����°� Ȯ���ϴ� ���ͷ� Ǯ�� ���������� ���� �ʴ´�.
//�����Ұ�.

void MakeBoard()
{
    int idx = 1;
    int count = 0;
    int num = 0;
    for (int i = 0; i < to; ++i)
    {
        if (count == idx)
        {
            ++idx;
            count = 0;
        }
        num += idx;
        ++count;
        board[i] = num;
    }
}

void MakeAnswer()
{
    MakeBoard();
    if (from > 1)
        cout << board[to - 1] - board[from - 2] << '\n';
    else
        cout << board[to - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}