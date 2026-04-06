#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 접근은 매우 간단하다. 현재 위치가 i번째일 때 앞으로 한칸씩 이동하면서 조를 짜는 모든
// 경우를 살펴본다. 만약 조를 짜는 위치가 j라서 j ~ i가 하나의 조를 이룬다면 점화식은
// dp[i] = max(dp[i], dp[j - 1] + j ~ i의 조값)이 된다. 다만 j가 0이라면 j - 1은
// 있을 수 없으니 그냥 j ~ i의 조값을 비교하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N;
int board[1000], dp[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    dp[0] = 0;
    for (int i = 1; i < N; ++i)
    {
        int minnum = board[i];
        int maxnum = board[i];

        // 처음에는 j = i - 1부터 시작하면 되는게 아닌가 하는 생각도 했으나
        // 반드시 i ~ i가 조가 되는 즉, 현재 수를 무시해야하는 경우가 생기기 때문에
        // j = i부터 시작해야한다.
        for (int j = i; j >= 0; --j)
        {
            minnum = min(minnum, board[j]);
            maxnum = max(maxnum, board[j]);

            int plus = maxnum - minnum;

            if (j > 0)
                dp[i] = max(dp[i], dp[j - 1] + plus);
            else
                dp[i] = max(dp[i], plus);
        }
    }
    cout << dp[N - 1] << '\n';
    return 0;
}