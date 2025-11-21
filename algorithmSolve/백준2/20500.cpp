#include <iostream>

using namespace std;

int N;
long long dp[1516][3];
constexpr int DIVNUM = 1000000007;

int main()
{
    cin >> N;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= N - 1; ++i)
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % DIVNUM;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % DIVNUM;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % DIVNUM;
    }

    cout << dp[N - 1][1] << '\n';
    return 0;
}