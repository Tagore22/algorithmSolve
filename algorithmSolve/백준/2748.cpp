#include <iostream>

using namespace std;

// Ǯ��.
// �Ǻ���ġ ���� ���� �����̴�. 
// 2��°���� �����ϵ� i - 1, i - 2���� �̿��Ͽ� ���ϸ� �ȴ�.
// �ٸ� �ִ� 90��°���� ���ؾ��ϴµ� �� �������� int���� ����� ������
// long long Ÿ���� �迭�� ����ؾ� �Ѵ�.

long long dp[91];
int N;

void MakeAnswer()
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}