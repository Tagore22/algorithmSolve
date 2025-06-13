#include <iostream>

using namespace std;

// Ǯ��.
// DP������ ū ������ ��� ���ο� ���� ��Ȳ�� ���������� ������ �̰��� DP�� �ݿ��ؾ�������
// �����ϰ� �� ��̴�. 

int N, K;
const int MAX = 20;
int jump[MAX][2], dp[MAX][2];

void CalMinEnergy(int idx, int cur, bool isCanBigJump)
{
    if (cur > dp[idx][isCanBigJump])
        return;
    dp[idx][isCanBigJump] = cur;

    if (idx == N - 1)
        return;

    CalMinEnergy(idx + 1, cur + jump[idx][0], isCanBigJump);
    if (idx + 2 <= N - 1)
        CalMinEnergy(idx + 2, cur + jump[idx][1], isCanBigJump);
    if (idx + 3 <= N - 1 && isCanBigJump)
        CalMinEnergy(idx + 3, cur + K, false);
}

void Solve()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 2; ++j)
            dp[i][j] = 110000;
    CalMinEnergy(0, 0, true);
    int answer = min(dp[N - 1][0], dp[N - 1][1]);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
        cin >> jump[i][0] >> jump[i][1];
    cin >> K;
}

int main()
{
    Input();
    Solve();
    return 0;
}