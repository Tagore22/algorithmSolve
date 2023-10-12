#include <iostream>

using namespace std;

// Ǯ��.
// ó�� ������ ������ ���� ��Ȳ�ߴ�. 10������ 3���� �����ϴµ� �̰��� 10���� ��½ �ѱ� �����̴�.
// ������ dp�� ����Ǵ� ��ѱ��� �˰����̾���. �� ������ �ִ� 16������ �ִµ� N�� ũ�Ⱑ 33�̻��϶�����
// ������ ���� ������ ����� 3���̻� �����ϱ� �����̴�. ���� N�� ũ�Ⱑ 32�ʰ� Ȥ�� 33�̻��� ���
// 0�� ����ϰ� �׷��� ���� ���� ����Ž������ �ּҰ��� ����ؼ� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

string board[100000];
int T, N, answer, ans;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // �������� �ʱ�ȭ.
        answer = 987654321;
        cin >> N;

        for (int i = 0; i < N; ++i)
            cin >> board[i];
        // �� ����Ͽ��� N�� 33�̻��� ��� ���� ������ ����� 3���̻� ������ �����ϹǷ� 0�� �����.
        if (N > 32)
        {
            cout << 0 << '\n';
            continue;
        }

        // �׷��� ���� ��� ��� �ο����� ����Ž������ ����Ѵ�.
        for (int i = 0; i < N - 2; ++i)
        {
            for (int j = i + 1; j < N - 1; ++j)
            {
                for (int k = j + 1; k < N; ++k)
                {
                    for (int z = 0; z < 4; ++z)
                    {
                        if (board[i][z] != board[j][z])
                            ++ans;
                        if (board[j][z] != board[k][z])
                            ++ans;
                        if (board[i][z] != board[k][z])
                            ++ans;
                    }
                    // ������ �� ���簪�� ����.
                    answer = min(answer, ans);
                    ans = 0;
                }
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