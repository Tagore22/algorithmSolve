#include <iostream>

using namespace std;

// 풀이.
// 정답율이 증명하듯 어려운 문제였다. DP의 점화식을 이끌어내기가 힘들었다.
// 결과적으로 말하자면 DP를 2중 배열로 사용해야 한다.

// dp[100000][2]; 
// dp[N][0] = 어떠한 원소를 지운 상태.
// dp[N][1] = 아직 원소를 지우지 않은 상태.

// 또한, 맨 뒤부터 시작해야했다. 맨뒤는 원소를 지울것도 없고 만들수 있는 최대수가 늘
// 자기 자신이기 때문이다. 따라서 맨 뒤부터 시작해서 0번째 원소까지 되돌아가는 순회를 해야한다.
// 순회중 점화식은 다음과 같다.

// dp[N][0] = max(dp[N + 1][1] + (-1 * board[N + 1]), dp[N + 1][0]) + board[N];
// dp[N][1] = dp[N + 1][1] < 0 ? board[N] : board[N] + dp[N + 1][1];

// dp[N][0]은 2가지로 다시 나뉘어지는데 dp[N + 1][1]에서 현재 지움을 행하는 상태와
// dp{N + 1][0]가 그에 해당한다. 따라서 2개중 더 큰 상태에서 현재값을 더하면 된다.
// dp[N][1]은 아무것도 지우지 않은 상태에서의 최대값이므로 만약 dp[N + 1][1]이 양수라면 더하고
// 그렇지 않으면 현재값이 dp[N][1]이 된다. 
// 지우는것 이외에 음수라서 무시되는 값들은 상술한 dp[N + 1][1]이 양수인지 음수인지에 따라 나뉘어지는것에서
// 걸러지기 때문에 신경쓰지 않아도 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100000], dp[100000][2];
int N;

void MakeAnswer()
{
    // 맨 마지막 원소는 지울것이 없기에 모두 현재값으로 초기화된다.
    dp[N - 1][0] = dp[N - 1][1] = board[N - 1];
    for (int i = N - 2; i >= 0; --i)
    {
        // 상술한 점화식들.
        dp[i][0] = max(dp[i + 1][1] + (-1 * board[i + 1]), dp[i + 1][0]) + board[i];
        dp[i][1] = dp[i + 1][1] < 0 ? board[i] : board[i] + dp[i + 1][1];
    }
    int answer = -1987654321;
    // 모든 원소들을 순회하며 최대값을 찾는다.
    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, dp[i][0]);
        answer = max(answer, dp[i][1]);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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