#include <iostream>

using namespace std;

// Ǯ��.
// ���������� �ٱ��Ͽ� ���� ���ٰ� �ִ� ���� ������ ��������δ� �������� �� �ٱ��Ͽ� ����ִ� ����
// ��ȣ�� ����ϸ� �ȴ�. ������ �ٱ��Ͽ� �ִ� ���� ���� ���ο� ���� �ִ°� �׳� �� �ٱ����� ����
// ���ο� ������ �ٲٸ� �Ǵ� ���̴�.

// �ڼ��� ������ �ּ����� �����.

int board[101];
int N, M;

void MakeAnswer()
{
    // ���� ���� ���� ����ִ� ������ ���۰�, ����, ���ο� ���� ��ȣ.
    int from, to, num;
    for (int i = 0; i < M; ++i)
    {
        // ������ ���� ��ȣ�� �Է¹޴´�.
        cin >> from >> to >> num;
        // ������ ��ȣ�� ���ο� ��ȣ num���� �ٲ۴�. 
        for (int j = from; j <= to; ++j)
        {
            board[j] = num;
        }
    }

    // 1������ N�������� �ٱ��ϼ� ���� ��ȣ ���.
    for (int i = 1; i <= N; ++i)
    {
        cout << board[i] << ' ';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}