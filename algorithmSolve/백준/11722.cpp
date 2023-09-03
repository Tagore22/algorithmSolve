#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 요 근래 풀어봤던 문제랑 비슷한 문제였다. 감소와 증가의 차이만이 존재했다.
// 그리디로 풀수 있을것처럼 보이나, 막상 보면 규칙이 없기에 dp를 이용한 완전탐색으로
// 풀어야 한다.

// 자세한 설명은 주석으로 남긴다.

int board[1000], dp[1000];
int N;

// idx에서 시작하는 원소들중 가장 긴 감소하는 부분 수열을 찾는 함수.
int BackTrack(int idx)
{
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 1;
    // idx보다 나중의 원소들중 board[idx]보다 board[i]가 크다면 포함시킨후 그다음으로 나아가본다.
    for (int i = idx + 1; i < N; ++i)
    {
        if (board[idx] > board[i])
            ans = max(ans, BackTrack(i) + 1);
    }
    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = 0;
    // 0 ~ N - 1에서 시작하는 가장 긴 감소하는 부분 수열을 찾는다.
    for (int i = 0; i < N; ++i)
        answer = max(answer, BackTrack(i));

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