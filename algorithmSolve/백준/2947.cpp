#include <iostream>

using namespace std;

// Ǯ��.
// ������ �����̴�. ������� ������ ���Ͽ� ������� Ŭ��� �������� �ٲٸ�
// 4��° ������ �̵��Ѵ�. ���� 1, 2, 3, 4, 5�� ���ĵǾ��ٸ� �ݺ��� ������,
// �׷��� �ʴٸ� �ٽ� �ݺ��Ѵ�. �Ѱ��� ���������� �� ���� �ٲ𶧸� 5���� ���� ����Ѵٴ� ���̴�.
// �̰��� �򰥷��� Ʋ�����ߴ�.

// �ڼ��� ������ �ּ����� �����.

int board[5];
int ans[5] = { 1, 2, 3, 4, 5 };

void MakeAnswer()
{
    // ���� 1, 2, 3, 4, 5�� ���ĵɶ����� ��� �ݺ��Ѵ�.
    while (true)
    {
        // 0 ~ 4��° ������ ��ȸ�ϸ� �������� ������� ���Ѵ�.
        for (int iter = 0; iter < 4; ++iter)
        {
            // ������� �� ũ�ٸ� �������� �ٲٰ� �̶����� 5���� ���� ����Ѵ�.
            if (board[iter] > board[iter + 1])
            {
                swap(board[iter], board[iter + 1]);
                for (int i = 0; i < 5; ++i)
                    cout << board[i] << ' ';
                cout << '\n';
            }
        }

        // 4��°������ ��ȸ�� ���� ���� 1, 2, 3, 4, 5�� ���ĵǾ����� Ȯ���Ͽ�
        // ���ĵǾ��ٸ� �ݺ����� Ż���ϰ� �׷��� �ʴٸ� �ٽ� �ݺ��Ѵ�.
        bool isfind = true;
        for (int i = 0; i < 5; ++i)
        {
            if (board[i] != ans[i])
            {
                isfind = false;
                break;
            }
        }

        if (isfind)
            break;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}