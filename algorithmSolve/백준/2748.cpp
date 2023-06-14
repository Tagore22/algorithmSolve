#include <iostream>

using namespace std;

// 풀이.
// 피보나치 수의 구현 문제이다. 
// 2번째부터 시작하되 i - 1, i - 2임을 이용하여 구하면 된다.
// 다만 최대 90번째까지 구해야하는데 이 시점에서 int값을 벗어나기 때문에
// long long 타입의 배열을 사용해야 한다.

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