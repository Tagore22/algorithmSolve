#include <iostream>

using namespace std;

// Ǯ��.
// �� ��ȭ���� ���̰� N�� ���� �������̱� ������ �� 2���� for���� ����ؾ��ߴ�.
// ����, int���� ����� ������ long long���� dp �迭�� �����ߴ�.

long long dp[36];

int main()
{
    dp[0] = 1;
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * dp[i - j - 1];
    cout << dp[N] << '\n';
    return 0;
}