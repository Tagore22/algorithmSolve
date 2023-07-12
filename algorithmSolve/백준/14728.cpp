#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// dp와 냅색문제를 섞은 문제다.
// 총 N개의 과목이 있을때 각 과목을 선택하느냐 하지 않느냐의 2가지 경우를 모두 선택하되,
// dp로 중복을 막으면 된다.

// 자세한 풀이는 주석으로 남긴다.

pair<int, int> board[100];
int dp[10001][100];
int N, T;

// 모든 선택을 해보는 함수. 상술하였듯이 dp로 중복을 막는다.
int BackTrack(int num, int idx)
{
    if (idx == N)
        return 0;

    int& ans = dp[num][idx];
    if (ans != -1)
        return ans;

    // 현재 과목을 선택하지 않는 경우.
    ans = BackTrack(num, idx + 1);

    // 현재 과목을 선택할수 있을때 선택하는 경우.
    if (board[idx].first <= num)
        ans = max(ans, BackTrack(num - board[idx].first, idx + 1) + board[idx].second);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));

    int answer = BackTrack(T, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}