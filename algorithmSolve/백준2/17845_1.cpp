#include <iostream>

using namespace std;

// 재귀를 사용하지 않은 탑다운 방식.
// 코드도 훨씬 더 짧고 연산량도 줄어 매우 빠르다.

int N, K;
int dp[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        int l, t;
        cin >> l >> t;

        for (int j = N; j >= t; --j)
            dp[j] = max(dp[j], dp[j - t] + l);
    }
    cout << dp[N] << '\n';
    return 0;
}