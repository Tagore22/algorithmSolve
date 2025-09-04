#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ����� ��������. �� �״�� ��� ����� ���� �����������Ƿ� dp�� ����ؾ��ߴµ�
// �ű⿡ �ּҰ��� �˱� ���� ������ ���� �׸���� ������ �ߴ�.

// �ڼ��� ������ �ּ����� �����.

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

    // �ڵ��� ���Ǹ� ���� ���л��� ������ ���ٰ� �����Ѵ�.
    if (n > m)
    {
        swap(n, m);
        swap(man, woman);
    }

    // �ּҰ��� ���ؼ� ������ �Ѵ�. �̴� ������ ����
    // ���� ���� ���� ������, ū ���� ū ������ ������ �Ͽ�
    // �ּҰ��� ���ϱ� �����̴�.
    sort(man.begin(), man.end());
    sort(woman.begin(), woman.end());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    // �Ʒ� ����� ���� ���л��� ���л��� 0���� ���� ���л���
    // 0���� ���� �����ϳ�, ���л��� 0���� ���� �������� �ʱ� ������
    // dp[0][i]�� 0���� �ʱ�ȭ�ص� �������.
    for (int i = 0; i <= m; ++i)
        dp[0][i] = 0;

    // �Ʒ� ��꿡�� �ε������� �����ߴµ� dp������ �ε������� ������ man�̳�
    // woman������ �ε������� �ٸ���. ���ڴ� ���°�� �f�ϴ� ���̰� ���ڴ�
    // ��������� ���ϴ� ���̴�.
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + abs(man[i - 1] - woman[j - 1]), dp[i][j]);

            // �׻� ���л��� ���л����� ũ�ų� ���� ������
            // �̷��� ��쿡�� ���л��� �ǳʶ� �� �ִ�.
            if (j > i)
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}