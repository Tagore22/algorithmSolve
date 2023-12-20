#include <iostream>

using namespace std;

// �����̵� �����츦 �̿��� 5582���� �� ���� Ǯ��.
// ������ ������ ������ ����ϴ� �޸𸮰� �ǹ��ְ� ���̳���
// �ӵ� ���� ��������. �Ƹ� �迭 ���� �� �ʱ�ȭ�� �ð��� ����Ǿ�
// �׸�ŭ �ӵ��� �������µ� �ϴ�.

// �ڼ��� ������ �ּ����� �����.

int board[2][4001] = { 0 };
string A, B;

void MakeAnswer()
{
    // �����̵� �����츦 ������ ��� ������ ����.
    int Asize = A.size(), Bsize = B.size();
    int answer = 0, idx = 0;
    for (int i = 0; i < Asize; ++i)
    {
        for (int j = 0; j < Bsize; ++j)
        {
            if (A[i] == B[j])
            {
                board[idx][j + 1] = board[1 - idx][j] + 1;
                if (board[idx][j + 1] > answer)
                    answer = board[idx][j + 1];
            }
            else
            {
                board[idx][j + 1] = 0;
            }
        }
        // 0���� 1��, 1���� 0����.
        idx ^= 1;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}