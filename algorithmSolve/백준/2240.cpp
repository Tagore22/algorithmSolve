#include <iostream>

using namespace std;

// 풀이.
// 냅색과 DP를 이용한 풀이다. 처음에는 DP가 필요없을줄 알았다. 겹치지 않을 거라 생각했기 때문이다.
// 하지만 그렇지 않았다. 예를 들어서 현재 4번째 상황에 돌입했을때 1번, 2번에서 움직인 것과,
// 2번, 3번에서 움직인 이후 두 상태는 같다. 모두 2번 움직였기에 현 위치도 같고, 남은 W의 값도 같다.
// 따라서 똑같은 함수가 중복 호출된다. 결과적으로 DP는 필수불가결이다. 조금 헤맸으나 어쨌든 스스로 풀어서 다행이다.

// 자세한 설명은 주석으로 남긴다.

// dp의 배열 부분에서 실수를 했다. 맨 앞은 cur을 나타내는데 1 ~ 2 이기 때문에 2가 아닌 3이 되어야한다.
// 또한 맨 뒤는 W를 나타내는데 마찬가지로 0 ~ 30이기 때문에 31이 되어야한다.
int board[1000], dp[3][1000][31];
int T, W;

// 모든 상황을 다 계산해보는 함수.
int Nap(int cur, int idx, int move)
{
    // T개의 원소를 모두 계산해보았다면 탈출한다.
    if (idx == T)
        return 0;

    int& ans = dp[cur][idx][move];
    if (ans != -1)
        return ans;
    ans = 0;

    // 움직이기 않았을 경우.
    int plus = board[idx] == cur ? 1 : 0;
    ans = max(ans, plus + Nap(cur, idx + 1, move));

    // 움직였을 경우.
    if (move != 0)
    {
        int next = cur == 1 ? 2 : 1;
        plus = board[idx] == next ? 1 : 0;
        ans = max(ans, plus + Nap(next, idx + 1, move - 1));
    }
    return ans;
}

void MakeAnswer()
{
    // dp 배열의 초기화.
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j < T; ++j)
            for (int k = 0; k <= W; ++k)
                dp[i][j][k] = -1;
    cout << Nap(1, 0, W) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> W;
    for (int i = 0; i < T; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}