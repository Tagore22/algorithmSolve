#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �־����� 5���� ������ ��հ� 3��°�� ū ���� ����ϴ� ������.
// ����� �׳� ���ؼ� 5�� ������ �ǰ�, 3��°�� ū ���� �����Ͽ� ������ �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[5];
int sum = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 5���� ���� �Է¹޴´�.
    for (int i = 0; i < 5; ++i)
    {
        // ������ �迭�� �����Ѵ�.
        cin >> board[i];
        // ����� ���ϱ� ���� ��� ���Ѵ�.
        sum += board[i];
    }

    // ����� ����Ѵ�.
    cout << sum / 5 << '\n';
    // �����Ͽ� 3��°�� ū ���� ����Ѵ�.
    sort(board, board + 5);
    cout << board[2] << '\n';

    return 0;
}