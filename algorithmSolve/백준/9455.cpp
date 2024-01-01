#include <iostream>

using namespace std;

// Ǯ��.
// �� ĭ���� �߷¿� ���� �������� �̵��� ĭ�� ���� ����ϴ� ������.
// �� �Ʒ����� ���� �ö󰡸� ��ĭ(���Ұ��� 0��ĭ)�� �� ���� ����ĭ�� �ִٸ� �̵��ϴ� ĭ�̹Ƿ�
// �����̴� ĭ�� �ȴ�. �̰͵��� ��� ����ؼ� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100][100];
int T, M, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> M >> N;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];

        // ���� ���̽��� ������.
        int answer = 0;
        // ������ ����ؼ� ��� ����� ����Ѵ�.
        for (int i = 0; i < N; ++i)
        {
            // ���� ������ �̵��ϴ� ĭ.
            int num = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                // ���� ĭ�� �������̶�� ���±��� ���ؿԴ� �̵������� ��ĭ���� ����ŭ �̵��Ѵ�.
                if (board[j][i] == 1)
                    answer += num;
                // ���� ĭ�� ��ĭ�̶�� �̵������� ĭ�� �ȴ�.
                else
                    ++num;
            }
        }
        cout << answer << '\n';
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