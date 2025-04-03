#include <iostream>

using namespace std;

// Ǯ��.
// DP ������ ó���� �����ϰ� ����������, ���� �׷��� �ʾҴ�. �ִ� 4���� ���� ���� �����Ƿ�
// 5�� ���������� ���� ���ϰ� �� ���� DP ��ȸ�� ��ġ�� �Ǿ���.

int main()
{
    int dp[1001];
    int N;
    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    for (int i = 5; i <= N; ++i)
    {
        if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    cout << (dp[N] ? "SK" : "CY") << '\n';
    return 0;
}