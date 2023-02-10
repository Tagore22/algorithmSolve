#include <iostream>

using namespace std;

// 풀이
// N번째 기관차일때 M번 칸을 끌수 있는지 확인하는 DP문제이다. 다만, 연속된 칸을 끌수 있기에 누적합 또한 필요로 한다.
// 순회문에서 dp[i][j] 값은 2가지 경우가 있는데 

// 1. 현재 객차를 이끈다.
// 2. 현재 객차를 이끌지 않는다.

// 이 2가지이다. 객차를 끌때에는 다른 기관차가 이끈걸 중복할수 없기에 이전 기관가 현재 객차 이전 M개까지만 이끈 상태이다.
// 즉 dp[i-1][j-m]이 되고, 현재 기관차가 j까지 m개를 이끈 sum[j] - sum[j-m]개를 더해주면 된다.

// 1-1 dp[i-1][j-m] + sum[j] - sum[j-m];

// 2번째 현재 객차를 무시할때에는 현재 바로 이전 객차를 이끈상태로 비교하면 된다.
// 2-1 dp[i][j-1];

// 그리고 이 2개를 비교하여 최대값을 채용한다.
// 최종점화식 dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + sum[j] - sum[j-m];

// 이후 3개의 기관차를 상술한 점화식을 돌며 dp 배열을 계산하고 dp[3][N]를 출력해주면 된다.

int sum[50001], dp[4][50001];
int N, M; // 총 객차수, 소형차로 끄는 객차수

void MakeAnswer()
{
    for (int i = 1; i <= 3; ++i)
        for (int j = i * M; j <= N; ++j)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + sum[j] - sum[j - M]);

    cout << dp[3][N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    sum[0] = 0;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}