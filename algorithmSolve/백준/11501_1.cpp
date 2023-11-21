#include <iostream>

using namespace std;

// 11501���� �� ���� Ǯ��.
// �� �������� ��������� ���� �߿��Ѱ� ���� �ε��� idx�������� ������ ���ұ��� ���� ���� ������ ���ϴ� ���̴�.
// ���� Ǯ�̿����� �켱����ť�� ���ؼ� ���� ���� ���� ������ ���ڿ� ���� ���ڸ� ���ϴµ� ���ʿ��� ������ ���Ҵ�.
// �ܼ��ϰ� �ڿ������� ���� ���� ���ݵ��� ���س����� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[1000000];
int T, N;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        // �� ���ں� ���ݵ��� �Է¹޴´�.
        for (int i = 0; i < N; ++i)
        {
            cin >> board[i];
        }

        long long answer = 0;
        int max_num = 0;
        // �ǵں��� ���� ���� ���ݵ� �����ϰ� ���� ���Ҹ� �� ���͵���
        // ��� ���Ѵ�.
        for (int i = N - 1; i >= 0; --i)
        {
            max_num = max(max_num, board[i]);
            answer += max_num - board[i];
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