#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 어려운 문제였다. 말 그대로 모든 경우의 수를 따져야했으므로 dp를 사용해야했는데
// 거기에 최소값을 알기 위해 정렬을 통한 그리디로 시작을 했다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> man(n), woman(m);
    for (int i = 0; i < n; ++i)
        cin >> man[i];
    for (int i = 0; i < m; ++i)
        cin >> woman[i];

    // 코드의 편의를 위해 남학생이 무조건 적다고 가정한다.
    if (n > m)
    {
        swap(n, m);
        swap(man, woman);
    }

    // 최소값을 위해서 정렬을 한다. 이는 정렬을 통해
    // 작은 값은 작은 값끼리, 큰 값은 큰 값끼리 만나게 하여
    // 최소값을 구하기 위함이다.
    sort(man.begin(), man.end());
    sort(woman.begin(), woman.end());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    // 아래 계산을 통해 남학생과 여학생이 0명인 경우와 남학생만
    // 0명인 경우는 존재하나, 여학생만 0명인 경우는 존재하지 않기 때문에
    // dp[0][i]만 0으로 초기화해도 상관없다.
    for (int i = 0; i <= m; ++i)
        dp[0][i] = 0;

    // 아래 계산에서 인덱스값이 복잡했는데 dp에서의 인덱스값은 실제로 man이나
    // woman에서의 인덱스값과 다르다. 전자는 몇번째를 똣하는 값이고 후자는
    // 몇명인지를 뜻하는 값이다.
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + abs(man[i - 1] - woman[j - 1]), dp[i][j]);

            // 항상 여학생이 남학생보다 크거나 같기 때문에
            // 이러한 경우에만 여학생을 건너뛸 수 있다.
            if (j > i)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}