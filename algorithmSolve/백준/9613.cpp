#include <iostream>

using namespace std;

// Ǯ��.
// �ִ������� ���ϴ� ������. �����Ͽ��� ���� �ñ⿡ ����� �ʾҴ�.
// �־����� ���̽����� ��� ���ҵ��� �ѽ����� ���� �ִ������� ���� �� ������
// ������ answer�� ������ ����ϸ� �ȴ�.

// �ٸ� �Ѱ��� �Ǽ��� �߾��µ� � ���� �ִ� ������� �ִ밪 100���̶�� �Ҷ�
// ���� �𸣰ڴµ� �ѹ��� ���̽����� 100�� ���� �ִ밪�� 1���̶�� �����Ͽ���.
// �����δ� �� ���̽��� ���Ұ� �ִ밪�� 100���� �־����� 99 + 98 + ... + 1���� �� 4950���� �־���
// 40���� ��½ �پ�Ѱ� �ȴ�. ���� ������ answer�� int�� �ƴ� long long���� �����ؾ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[100];
int T, N;

// �ִ������� ���ϴ� �Լ�.
int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

void MakeAnswer()
{
    // �� ����Ͽ��� answer�� �� ���̽����� �ִ� 40���� ������ �����Ƿ� int�� �ƴ� long long���� �����ؾ��Ѵ�.
    long long answer;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        answer = 0;
        for (int j = 0; j < N; ++j)
        {
            cin >> board[j];
        }

        // ��� ���ҵ��� �ѽ����� ���� �ִ������� ���ϰ� �� ������ ������ answer�� ���Ѵ�.
        for (int from = 0; from < N - 1; ++from)
        {
            for (int to = from + 1; to < N; ++to)
            {
                answer += GCD(board[from], board[to]);
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