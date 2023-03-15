#include <iostream>

using namespace std;

// 풀이.
// 전형적인 DP문제였으나 DP를 어떻게 이용할것인지 조금 헷갈렸던 문제이다.
// 각각 길이와 마지막으로 끝나는 수(0 ~ 9까지)를 2차원 배열을 사용하여 구현하면 어렵지 않다.

int dp[1001][10]; // 길이, N으로 끝나는 경우.
int N;
const int DIV_NUM = 10007;

void MakeAnswer()
{
    // 길이가 얼마든 0으로 끝나는 경우는 단 하나.
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 1;

    // 길이가 1일 경우, 모든 경우는 단 하나.
    for (int i = 0; i <= 9; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= 9; ++j)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIV_NUM;

    int answer = 0;
    for (int i = 0; i <= 9; ++i)
        answer = (answer + dp[N][i]) % DIV_NUM;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}