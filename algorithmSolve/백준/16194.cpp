#include <iostream>
#include <cstring>
#include <algorithm>

// Ǯ��.
// �ܼ��� ��Ʈ��ŷ ������.
// �־��� N�� �پ�� ������ �ִ� board[i]�� �յ��� �ּҰ��� ����Ѵ�.

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