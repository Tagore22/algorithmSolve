#include <iostream>

using namespace std;

// 풀이.
// DP 구현을 처음엔 복잡하게 생각했으나, 전혀 그렇지 않았다. 최대 4개씩 돌을 뺄수 있으므로
// 5개 이전까지는 직접 구하고 그 이후 DP 순회를 거치면 되었다.

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