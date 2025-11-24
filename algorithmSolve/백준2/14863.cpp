#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 냅색을 이용해야하지만 N이 최대 100이라 시간내에 다 풀 수 없는데 이 부분을
// DP로 보완해야하는 문제이다. 두가지 실수를 했는데 이는 후술한다.

// 자세한 설명은 주석으로 남긴다.

int N, K;
// 처음에 dp는 long long이었다. 문제를 잘못본 것인데 K가 최대 10만이고
// 모금액이 최대 100만이기 때문이었다. 실제로는 최대 100인 N번 순회하며
// 최대 모금액인 100만을 모으기 때문에 1억을 넘지 않는다.
int board[100][4], dp[100][100001];

int DFS(int idx, int time)
{
    if (idx == N)
        return 0;

    int& ans = dp[idx][time];
    if (ans != -1)
        return ans;

    // 이 부분이 2번째 실수다. 최대값을 구해야하기 때문에
    // 습관적으로 ans의 초기값을 0으로 했는데 이렇게 하니까
    // 시간 부족으로 마지막 도시까지 도달하지 못하는 경우가
    // 더 많은 모금액을 모으는 걸로 계산되고 있었다.
    ans = -987654321;
    if (time >= board[idx][0])
        ans = max(ans, DFS(idx + 1, time - board[idx][0]) + board[idx][1]);
    if (time >= board[idx][2])
        ans = max(ans, DFS(idx + 1, time - board[idx][2]) + board[idx][3]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> board[i][j];

    cout << DFS(0, K) << '\n';
    return 0;
}