#include <iostream>

using namespace std;

// 풀이.
// 각 점화식의 길이가 N에 따라 가변적이기 때문에 총 2개의 for문을 사용해야했다.
// 또한, int값을 벗어나기 때문에 long long으로 dp 배열을 구현했다.

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