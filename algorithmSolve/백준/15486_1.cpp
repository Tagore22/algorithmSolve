#include <iostream>
#include <cstring>

using namespace std;

// 15486번의 제대로 된 풀이.
// 냅색을 이용하여 현재 일을 처리하는 경우와 하지 않은 2가지 경우로 나누어 처리한다.
// 가장 많이 반복되는 경우는 한번도 처리하지 않는 경우인데 이 경우에도 150만번에 처리되며
// 처리하는 경우는 경우의 수가 오히려 더 적다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[1500000];
int dp[1500000];
int N;

// 냅색 풀이를 이용하여 모든 경우를 순회하는 함수.
int CalMax(int idx)
{
    // idx가 N번 이상일 경우 퇴사하는 날을 지났으므로 0을 반환한다.
    if (idx >= N)
        return 0;

    // dp처리.
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;
    // 현재 일을 처리할수 있는 경우. board[idx].first만큼 일자가 지나며
    // board[idx].second만큼 수입이 생김.
    if (idx + board[idx].first <= N)
        ans = CalMax(idx + board[idx].first) + board[idx].second;

    // 현재 일을 처리할수 없는 경우. 시간이 하루 경과한다.
    ans = max(ans, CalMax(idx + 1));

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = CalMax(0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}