#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 기존의 방식대로 풀어보았으나 역시 재귀를 사용한 만큼 느리다.

int N, K;
pair<int, int> board[10000];
int dp[1000][10001];

int BackTrack(int idx, int time)
{
    if (idx == K)
        return 0;

    int& ans = dp[idx][time];
    if (ans != -1)
        return ans;

    ans = BackTrack(idx + 1, time);
    if (board[idx].second <= time)
        ans = max(ans, BackTrack(idx + 1, time - board[idx].second) + board[idx].first);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < K; ++i)
        cin >> board[i].first >> board[i].second;

    cout << BackTrack(0, N) << '\n';
    return 0;
}