#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 구해야 하는 수들이 적지 않고 테스트 케이스까지 있는걸 보면 dp를 사용하여 미리 값들을 구해놓고
// 그 이전값을 이용하여 새로운값을 구해내는 것이 분명했다. 즉, dp였다.
// 다만 어떻게 dp를 구축해야하는지 바로 떠오르지가 않았다. 기존에도 이런 문제에 조금 약했는데
// 그래도 많이 헤매진 않아서 조금 뿌듯하다. 풀이의 큰 틀을 보면 다음과 같다.

// 1. dp[현재 자리수][0 ~ 9중 하나의 수 i]를 구해서 dp[현재 자리수][0] ~ dp[현재 자리수][9]를 모두 더하면 된다.
// 2. dp[0][0] ~ dp[0][9]는 모두 1이다.
// 3. 두자리수(dp[1][i])부터는 그 이전자리수에서 i부터 9까지의 수들을 더하면 된다. 다음과 같다.
// dp[1][i] = dp[0][i] + dp[0][i + 1] ........ dp[0][9];
// 4. 이것을 미리 구해놓고, dp[주어지는 자리수 - 1][0] ~ dp[주어지는 자리수 - 1][9]를 출력하면 된다.
// 5. 수가 커서 int의 범위값을 벗어나기에 long long을 이용한다.

// 자세한 설명은 주석으로 남긴다.

long long dp[64][10];
int T, N;

// 전처리로 미리 값들을 구해놓는 함수.
void Init()
{
    memset(dp, 0, sizeof(dp));
    // 2번에 상술하였듯 한자리일 경우에는 모든 수가 올수 있으나 그때마다 경우의 수는 1가지씩이다.
    for (int i = 0; i < 10; ++i)
        dp[0][i] = 1;

    // 3번에 상술하였듯 dp[현재 자리수][i]는 그 이전자리수 즉 dp[현재 자리수 - 1]의 i부터 9까지의 모든 합이다.
    for (int i = 1; i < 64; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = j; k < 10; ++k)
                dp[i][j] += dp[i - 1][k];
}

void MakeAnswer()
{
    Init();
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;

        // 5번에 상술하였듯 범위값이 int를 벗어나기도 하기에 long long을 쓴다.
        long long answer = 0;
        for (int i = 0; i < 10; ++i)
            answer += dp[N - 1][i];

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}