#include <iostream>

using namespace std;

// 풀이.
// DP와 재귀함수를 구현하는 문제다. 

long long dp[68];
int T;

long long CalDP(int num)
{
    long long& ans = dp[num];
    if (ans != -1)
        return ans;
    ans = 0;
    return ans = CalDP(num - 1) + CalDP(num - 2) +
        CalDP(num - 3) + CalDP(num - 4);
}

void MakeAnswer()
{
    int num;
    for (int i = 0; i <= 67; ++i)
        dp[i] = -1;
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;
        cout << CalDP(num) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}