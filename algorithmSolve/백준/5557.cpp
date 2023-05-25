#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 100번동안 + 혹은 - 를 대입하여 총 연산량은 2의 100제곱으로 인해 시간내에 절대 풀수 없었으므로
// DP임을 확신했으나, 어떻게 DP로 묶어야하는지 잘 떠오르지를 않았다.
// 중복되는 곳이 존재하여야 DP로 묶어 중복을 없애야 하는데 그 중복되는 곳이 잘 떠오르질 않았던 것이다.
// 잘 생각해보니 idx번째에서 시작할때 현재 값이 sum일때 중복이 존재했다. 이것을 DP로 묶어
// 완전탐색을 실행하면 된다. 또한, 최대값이 2의 64제곱 - 1까지이므로 int가 아닌 long long을 사용하여
// 풀어야한다.

// 자세한 설명은 주석으로 남긴다.

int board[100];
long long dp[21][100];
int N;

// sum = board[0], idx = 1로 시작
// 완전탐색을 구현하는 함수. 상술하였듯 idx번째에 현재값이 sum일때
// 중복값이 존재하기에 이것을 DP로 묶으면 된다.
long long BackTrack(int sum, int idx)
{
    if (idx == N - 1)
        return sum == board[idx] ? 1 : 0;

    long long& ans = dp[sum][idx];
    if (ans != -1)
        return ans;

    ans = 0;
    // 덧셈 연산.
    if (sum + board[idx] <= 20)
        ans += BackTrack(sum + board[idx], idx + 1);
    // 뺄셈 연산.
    if (sum >= board[idx])
        ans += BackTrack(sum - board[idx], idx + 1);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    long long answer = BackTrack(board[0], 1);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}