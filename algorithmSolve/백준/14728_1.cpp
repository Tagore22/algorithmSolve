#include <iostream>

using namespace std;

// 14728�� �� ���� Ǯ��.
// ��͸� ������� �ʰ� �ܼ� �ݺ������� ����ϴ� Ǯ���̴�.
// � ������ �����Ҽ� ������ ���� �ִ� ������ ���������� Ȥ�� �������� �ʾ��� ��� 2������ �ִ������� �̿��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int dp[10001];
int N, T, K, S;

void MakeAnswer()
{
    // ����� N����ŭ �Է��� �ް� �׶����� dp���� ���Ž�Ų��.
    for (int i = 0; i < N; ++i)
    {
        cin >> K >> S;
        // ����Ͽ��� ������ �����Ҷ��� ���� Ȥ�� �������� �ʾ��� ��� 2������ �ִ밪�� �Ź� �����Ѵ�.
        for (int iter = T; iter >= K; --iter)
            dp[iter] = max(dp[iter], dp[iter - K] + S);
    }

    cout << dp[T] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}