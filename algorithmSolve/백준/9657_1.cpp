#include <iostream>

using namespace std;

// 재귀를 이용하지 않고 온전히 DP만을 이용한 풀이.
// 현재 턴에서 집었을때 상대방이 이긴다면 현재 내가 진다는 것을 이용하였다.

// 자세한 설명은 주석으로 남긴다.

int dp[1001];
int N;

int main()
{
    cin >> N;
    // 현재 돌이 1개, 3개, 4개라면 무조건 이긴다.
    dp[1] = dp[3] = dp[4] = 1;
    // 현재 돌이 2개라면 무조건 진다.
    dp[2] = 0;
    // 돌이 5개일때부터 N개일때까지 순회한다.
    for (int iter = 5; iter <= N; ++iter)
    {
        // 현재 내턴에서 집을수 있는 모든 상황들중 집은 이후 상대가 진다면 그 방법을 사용한다.
        if (!dp[iter - 1] || !dp[iter - 3] || !dp[iter - 4])
            dp[iter] = 1;
        // 상대가 지는 상황이 없다면 현재 나는 무조건 진다.
        else
            dp[iter] = 0;
    }
    if (dp[N] == 1)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
    return 0;
}