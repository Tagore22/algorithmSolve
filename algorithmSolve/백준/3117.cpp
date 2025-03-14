#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 평범한 희소 배열 문제와는 살짝 다른 면이 있었다. 기존에는 시작값까지 희소 배열에 포함되어 돌고 돌지만
// 이 문제에서는 맨 첫번째 배열이 희소 배열과는 관계없이 주어진다는 것이다. 따라서 도는 횟수 M을 1 제외하여
// 답을 구해야한다.

// 자세한 설명은 주석으로 남긴다.

int dp[30][100001], board[100001];
int N, K, M;

void MakeAnswer()
{
    int to = log2(M);
    for (int i = 1; i <= to; ++i)
        for (int j = 1; j <= K; ++j)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    for (int i = 1; i <= N; ++i)
    {
        // 비트마스크를 순회하며 도달한 j번째를 찾는다.
        // 다만 상술한대로 희소 배열과 관계없는 첫번째 배열값이 존재하기에
        // M - 1과 비교한다.
        int answer = board[i];
        for (int j = to; j >= 0; --j)
            if ((1 << j) & (M - 1))
                answer = dp[j][answer];
        cout << answer << ' ';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    for (int i = 1; i <= K; ++i)
        cin >> dp[0][i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}