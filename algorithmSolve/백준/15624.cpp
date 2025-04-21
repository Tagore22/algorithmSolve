#include <iostream>

using namespace std;

const int DIVNUM = 1000000007;
int N;
int dp[3];

int main()
{
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    if (N < 2)
    {
        cout << dp[N] << '\n';
        return 0;
    }
    for (int i = 2; i <= N; ++i)
    {
        dp[2] = (dp[1] + dp[0]) % DIVNUM;
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    cout << dp[2] << '\n';
    return 0;
}