#include <iostream>

using namespace std;

// 풀이.
// DP를 활용해야했으나 늘 그렇듯 DP배열의 구상이 쉽지 않았다. 처음에는 3중 배열을
// 이용하여 idx번째 이름이 i열j행에 있을 때로 로직을 짜서 구현하려고 했으나
// 그럴 경우 배열의 원소값만 10억개가 되어 불가능했다. 진짜 풀이는 idx번째
// 원소로부터 시작하여 한칸씩 앞의 원소값과 같은 줄에 놓았을 경우의 최소값을
// 구하는 방식이었다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
int board[1001], dp[1001];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];

    for (int i = 0; i <= N; ++i)
        dp[i] = 987654321;
    dp[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        int len = 0;
        // i번째 원소부터 한칸씩 앞으로 이동하며 같은 줄에
        // 이름을 적을 수 있는지 확인하고 그 때의 최소값을
        // 계산한다.
        for (int j = i; j >= 1; --j)
        {
            // j가 i보다 작을 경우 사이에 한칸을 비워둔다.
            len = j < i ? len + 1 : len;
            len += board[j];

            // i부터 j까지 같은 줄에 적을 수 없다면 
            // 현재 for문을 탈출하여 i + 1번째 원소로 넘어간다.
            if (len > M)
                break;

            int cost = M - len;

            // i가 N이라면 필연적으로 마지막 줄이 되어버리기에 
            // 남은 칸 cost는 0이 된다.
            if (i == N)
                cost = 0;
            else
                cost *= cost;
            dp[i] = min(dp[i], dp[j - 1] + cost);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}