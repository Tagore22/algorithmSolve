#include <iostream>

using namespace std;

// ���� �ƴ� dp�����ε� ���� �ɷȴ�.
// ��������� ó���� �����ߴ� �� ������ dp�� ����Ǫ�� ���̾��µ�
// Ǫ�� ������ ���� �߸������. ��ȭ�ĸ� �� ����� ���� �����̴�.

// �ڼ��� ������ �ּ����� �����.

long long board[3];
const int div_num = 1000000000;
int N;

void MakeAnswer()
{
    // ����ġ��.
    if (N <= 2)
    {
        cout << N - 1 << '\n';
        return;
    }
    // ��ȭ�Ŀ� �ʿ��� �ʱⰪ.
    for (int i = 1; i < 3; ++i)
        board[i] = i - 1;
    // �����̵� �����츦 �̿��Ͽ� ���귮�� �� ���ϼ��� �ִ�.
    // ��ȭ���� board[N] = (board[N - 1] + board[N - 2]) * N - 1�̴�.
    for (int i = 3; i <= N; ++i)
        board[i % 3] = (board[(i - 1) % 3] + board[(i - 2) % 3]) * (i - 1) % div_num;
    cout << board[N % 3] << '\n';
}

void Input()
{
    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}