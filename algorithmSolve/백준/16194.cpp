#include <iostream>
#include <cstring>
#include <algorithm>

// 풀이.
// 단순한 백트래킹 문제다.
// 주어진 N을 줄어가며 얻을수 있는 board[i]의 합들중 최소값을 출력한다.

using namespace std;

int board[1001], dp[1001];
int N, answer = 987654321;

int DFS(int sum)
{
    if (sum == 0)
        return sum;

    int& ans = dp[sum];
    if (ans != -1)
        return ans;

    ans = 987654321;

    for (int i = 1; i <= N; ++i)
        if (i <= sum)
            ans = min(ans, DFS(sum - i) + board[i]);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));

    cout << DFS(N) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}