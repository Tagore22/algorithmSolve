#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 풀이.
// 처음에 생각했던 로직이 맞았다. 다만 수의 차이값이 최대 10억이기 때문에
// DP로는 절대 못푼다는 게 잘못이었다. 이번 문제는 매우 드문 경우인데
// 맵을 통해서 DP를 구현해야 한다. 아마 N이 작은 편이기에 가능한 듯하다.
// 로직 자체는 그리 복잡하지 않은데 모든 수를 정렬해놓고 순회하며
// 자신보다 작은 원소들을 다시 순회하면서 그 차이값을 DP로 캐시하여
// 최대 등차 수열 값들을 저장하는 것이다.

// 자세한 설명은 주석으로 남긴다.

int N;
int board[2000];
unordered_map<int, int> dp[2000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    // 만약 N이 2개 이하라면 계산해 볼 필요도 없다.
    if (N <= 2)
    {
        cout << N << '\n';
        return 0;
    }
    sort(board, board + N);

    int answer = 2;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            int diff = board[i] - board[j];
            // 최소값은 시작 원소와 끝 원소 2개.
            int ans = 2;
            // 시작 원소에 이미 diff만큼 차이나는 등차 수열이 있다면
            // 그 개수 + 1개(끝 원소)를 하여 갱신한다.
            if (dp[j].count(diff))
                ans = dp[j][diff] + 1;

            // 현재 원소까지의 diff만큼 차이나는 최대 등차 수열 값을 갱신한다.
            dp[i][diff] = max(dp[i][diff], ans);
            // 최대 등차 수열 값을 갱신한다.
            answer = max(answer, dp[i][diff]);
        }
    }
    cout << answer << '\n';
    return 0;
}