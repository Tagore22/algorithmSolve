#include <iostream>
#include <vector>

using namespace std;

// 1660번의 up_down DP 구현 방식.
// 훨씬 더 빠르고 코드도 간략하다. 다만 생각해내는게 어렵다.

int N;
vector<int> board;

int main()
{
    cin >> N;
    int plus = 1, sum = 0, cur = 0;
    while (true)
    {
        cur += plus;
        sum += cur;
        if (sum > N)
            break;
        board.push_back(sum);
        ++plus;
    }
    vector<int> dp(N + 1, 300001);
    dp[0] = 0;
    for (int i = 0; i < board.size(); ++i)
        for (int j = board[i]; j <= N; ++j)
            dp[j] = min(dp[j], dp[j - board[i]] + 1);
    cout << dp[N] << '\n';
    return 0;
}