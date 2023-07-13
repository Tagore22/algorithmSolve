#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// dp문제였다. 다만 기존에 풀던 재귀호출 방식이 아닌
// 단순 for문 반복으로 풀고 싶었다. 익숙하지 않았기에 좀더 몸에 익히고 싶었기 때문이다.
// 떠오른 원리는 이러했다. 

// 1. 0원은 어느때나 딱 한가지 방법으로(아예 가지고 있지 않음)밖에 존재할수 없다.
// 2. 1원 동전이 있을때 1원은 0원인 방법에 1원 한가지만 추가하면 되므로 0원의 방법과 같다.
// 3. 마찬가지로 2원의 방법은 1원의 방법에 1원 한가지만 추가하면 되므로 1원의 방법과 같다.
// 4. 즉 N원 동전이 있을때 N원부터 ~ M원까지의 방법은 현재 금액이 i일때 dp[i] = dp[i - N]과 같다.
// 5. 이것을 모든 동전을 순회한후 dp[M]을 출력하면 된다. 다만 동전의 가지수에 따라 dp의 값이 바뀌므로
// 매 테스트케이스마다 dp를 0으로 갱신후 0원은 1로 초기화해주어야 한다.

// 자세한 설명은 주석으로 남긴다.

int dp[10001], board[20];
int T, N, M;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // 5번에 상술하였듯 동전의 가지수와 그 금액에 따라 dp가 바뀐다.
        // 따라서 매 테스트케이스마다 dp를 갱신후 dp[0]을 1로 초기화 해준다.
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];
        cin >> M;

        // 상술한 2 ~ 3번에 의해 점화식이 형성된다. 
        // dp[j] += dp[j - board[i]];
        for (int i = 0; i < N; ++i)
            for (int j = board[i]; j <= M; ++j)
                dp[j] += dp[j - board[i]];

        cout << dp[M] << '\n';
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