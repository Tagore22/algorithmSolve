#include <iostream>

using namespace std;

// 10835번의 더 빠른 풀이.
// 기존에는 재귀함수를 이용했기에 더 많은 연산과 시간이 필요했다.
// 하지만 간단히 for문을 이용하여도 아래와 같이 풀수 있다.
// 주의해야하는 점은 다음 2가지와 같다.

// 1. for문을 이용하는 DP풀이는 위에서 아래로 내려간다. 기존 재귀와 반대 방향이다.
// 2. N - 1에서 시작하되, + 1 되는 상황이 존재하기에 board와 dp의 값이 1씩 늘어나야 한다.

int boardL[2001], boardR[2001], dp[2001][2001];
int N;

void MakeAnswer()
{
    for (int l = N - 1; l >= 0; --l)
        for (int r = N - 1; r >= 0; --r)
        {
            if (boardL[l] > boardR[r])
                dp[l][r] = dp[l][r + 1] + boardR[r];
            else
                dp[l][r] = max(dp[l + 1][r], dp[l + 1][r + 1]);
        }
    cout << dp[0][0] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> boardL[i];
    for (int i = 0; i < N; ++i)
        cin >> boardR[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}