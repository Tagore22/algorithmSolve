#include <iostream>

using namespace std;

// 풀이.
// 전형적인 DP문제다. 다만 순서가 바뀌되, 수열을 이루는 수가 같다면 중복이 허락되는 것에 유의해야한다.
// 의외로 풀이는 어렵지 않은데 다음과 같은 원리가 매우 중요하다.

// 1. 몇개를 써도 총합이 0이 되는 경우는 언제나 1개다.
// 2. 임의의 숫자 K를 단 하나만 쓴다면 총합은 언제나 K다.

// 그 후로는 표를 직접 만들어보면 다음과 같은 규칙이 존재한다.

// dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

// 이것만 구현하면 된다.

// P.S 맨날 규칙을 머리속으로 구하니 다 집어넣지도 못하고 머리만 아프고 시간만 흘렀다.
// 이번처럼 직접 그려보자. 어렵지 않고 더 빨리 풀수 있다. 귀찮아하지말자.

int dp[201][201]; //  ~개를 써서 ~을 만들었을때.
const int DIV_NUM = 1000000000;
int N, K;

void MakeAnswer()
{
    for (int i = 0; i <= N; ++i)
        dp[1][i] = 1;

    for (int i = 1; i <= K; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= N; ++i)
        for (int j = 2; j <= K; ++j)
            dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % DIV_NUM;

    cout << dp[K][N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}