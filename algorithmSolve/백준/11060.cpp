#include <iostream>

using namespace std;

// 풀이.
// 최소한의 점프로 N번째 칸으로 이동할수 있는지 찾는 문제다.
// 처음엔 2차원 배열로 dp를 구현하는등 이것저것 생각났으나 진짜 풀이는
// 2번째부터 N번째까지 987654321를 이용하여 최대값의 dp를 초기화해놓고
// 1번째를 0으로 시작하여 갈수 있는 모든 칸으로 한칸씩 이동하며 dp값의 최소값들을 갱신하는 것이었다.

// 자세한 설명은 주석으로 남긴다.

int board[1001], dp[1001];
int N;

void MakeAnswer()
{
    // 최소값을 구해야하기에 초기값은 매우 큰 987654321으로 한다.
    for (int i = 2; i <= N; ++i)
    {
        dp[i] = 987654321;
    }
    // 1번째 칸은 아무런 이동없이 도달할수 있기에 0으로 한다.
    dp[1] = 0;

    // 1번째칸부터 1칸씩 오른쪽으로 이동하며 N - 1칸까지 순회한다.(N번째칸은 이동할 필요가 없음)
    for (int i = 1; i < N; ++i)
    {
        // 현재 칸의 값에 따라 현재칸에서 이동한값의 최소값을 갱신한다.
        for (int j = 1; j <= board[i]; ++j)
        {
            dp[i + j] = min(dp[i] + 1, dp[i + j]);
        }
    }

    // 이동할수 없다면 -1을 그렇지 않다면 dp[N]을 출력한다.
    int answer = dp[N] == 987654321 ? -1 : dp[N];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}