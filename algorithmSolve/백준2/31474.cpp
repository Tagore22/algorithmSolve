#include <iostream>

using namespace std;

int N;
long long dp[29];

int main()
{
    cin >> N;

    dp[2] = 1, dp[4] = 3;
    for (int i = 6; i <= N; i += 2)
        dp[i] = (i - 1) * dp[i - 2];

    cout << dp[N] << '\n';
    return 0;
}