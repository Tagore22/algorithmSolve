#include <iostream>

using namespace std;

// 11048번의 함수를 사용하지 않고 for문을 이용한 dp 풀이.
// 재귀함수를 사용하지 않기 때문에 더 빠르다.
// 또한 코드의 길이도 짧고 가독성도 좋다.

// 자세한 설명은 주석으로 남긴다.

int board[1001][1001], dp[1001][1001];
int N, M;

void MakeAnswer()
{
    // 매 좌표에서 기존에 왔던 방향 왼쪽, 위쪽, 좌상단의 크기값과 비교하여 가장 큰 수 + 현재 좌표의 값을 더해
    // 최종적은 값을 계산한다.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            dp[i][j] += board[i][j];
        }
    }

    cout << dp[N][M] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}