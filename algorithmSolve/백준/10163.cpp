#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ����� ���ϼ� ������ �������� �ܼ��� ������.
// �� �����̵��� �迭�Ͽ����� ������ ���̴� �������� ����ϴ� ������.
// �ܼ��� 0 ~ N - 1��°�� �����̵��� ������ ������ �� ĭ�� ���� ���° �����̷� �����ִ�����
// üũ�س�����. �� ���� ��� ĭ�� ��ȸ�ϸ� �����ִ� �����̵��� ũ�⸦ ��� ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[1001][1001], answer[100];
int N;

void MakeAnswer()
{
    // ���� �����̰� ������ �ʴ´ٸ�(�����̰� ���ٸ�) 0�� ����Ѵ�.
    if (N == 0)
    {
        cout << 0 << '\n';
        return;
    }
    // �� ĭ�� �ƹ��͵� ������ -1�� �ʱ�ȭ�Ͽ� �����ϰ�, �� �����̵��� ������ 0���� �ʱ�ȭ�Ѵ�.
    memset(board, -1, sizeof(board));
    memset(answer, 0, sizeof(answer));
    int y, x, row, col;
    // 0 ~ N - 1��° �����̵��� ������ �Է¹޾� �� ĭ�� �����Ѵ�.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> x >> y >> row >> col;
        for (int i = 0; i < col; ++i)
            for (int j = 0; j < row; ++j)
                board[y + i][x + j] = iter;
    }

    // ��� ĭ�� ��ȸ�ϸ� ���� ����Ǿ��ִ�(���������� ������) �������� ��ȣ���� �����Ͽ� ���Ѵ�.
    for (int i = 0; i <= 1000; ++i)
        for (int j = 0; j <= 1000; ++j)
            if (board[i][j] != -1)
                ++answer[board[i][j]];

    // ��� �����̵��� ������ ����Ѵ�.
    for (int i = 0; i < N; ++i)
        cout << answer[i] << '\n';
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