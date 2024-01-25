#include <iostream>

using namespace std;

// Ǯ��.
// �����佺�׳׽��� ü�� �̿��ϴ� ������. N�� �־����� 1 ~ N���� �� ������ ������� ���� ���� ���ؾ� �Ѵ�.
// ���� �̸� �����佺�׳׽��� ü�� �̿��Ͽ� ������ ��� ���س����� �Ź� N�� �Է¹��������� �߰����� �������
// �ٷ� ����Ҽ� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[1000001];
long long dp[1000001];
int N, T;

// �̸� ��� ���� ���س��� �����佺�׳׽��� ü �Լ�.
void Era()
{
    // �� ���鿡 ��������� ��� ���Ѵ�.
    for (int i = 1; i <= 1000000; ++i)
        for (int j = i; j <= 1000000; j += i)
            board[j] += i;
    // i������ ������� ���� ��� ���Ѵ�.
    long long sum = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        sum += board[i];
        dp[i] = sum;
    }
}

void MakeAnswer()
{
    // �����佺�׳׽��� ü�� �̿��Ͽ� �̸� ��� ���� ���س��´�.
    Era();
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        // N�� �Է¹޾� �߰����� ������� �ٷ� ���.
        cout << dp[N] << '\n';
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