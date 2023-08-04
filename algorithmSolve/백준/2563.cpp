#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� �ƴѵ� ��ư� Ǭ ������.
// �� 0 ~ 100, 0 ~ 100�� 2���� �迭���� ���� �������� ������ bool �迭�� �̿��Ͽ� üũ�س���
// ���ο� �����̸� ���������� �̹� ���� �������� Ȯ���Ͽ� ��ġ�� �κ��� �Ź� ���ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

bool board[101][101];
int N;

void MakeAnswer()
{
    // ���ʰ��� ������(���� ũ�Ⱑ 100�̴�)�� �� N * 100;
    int answer = N * 100;
    memset(board, false, sizeof(board));
    int col, row;
    // ��� �����̵��� ����, �̹� ���� �����̶�� ��ġ�� �κ��� ���Ͽ� ���ش�.
    for (int i = 0; i < N; ++i)
    {
        cin >> row >> col;
        int a = 0;
        for (int i = col; i < col + 10; ++i)
            for (int j = row; j < row + 10; ++j)
            {
                // �̹� ���� ������. ��ġ�� �κ�.
                if (board[i][j])
                    ++a;
                board[i][j] = true;
            }
        answer -= a;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}