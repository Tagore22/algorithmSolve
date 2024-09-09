#include <iostream>

using namespace std;

// Ǯ��.
// ������ DP�� �̿��� Ǯ�̴�. ó������ DP�� �ʿ������ �˾Ҵ�. ��ġ�� ���� �Ŷ� �����߱� �����̴�.
// ������ �׷��� �ʾҴ�. ���� �� ���� 4��° ��Ȳ�� ���������� 1��, 2������ ������ �Ͱ�,
// 2��, 3������ ������ ���� �� ���´� ����. ��� 2�� �������⿡ �� ��ġ�� ����, ���� W�� ���� ����.
// ���� �Ȱ��� �Լ��� �ߺ� ȣ��ȴ�. ��������� DP�� �ʼ��Ұ����̴�. ���� ������� ��·�� ������ Ǯ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

// dp�� �迭 �κп��� �Ǽ��� �ߴ�. �� ���� cur�� ��Ÿ���µ� 1 ~ 2 �̱� ������ 2�� �ƴ� 3�� �Ǿ���Ѵ�.
// ���� �� �ڴ� W�� ��Ÿ���µ� ���������� 0 ~ 30�̱� ������ 31�� �Ǿ���Ѵ�.
int board[1000], dp[3][1000][31];
int T, W;

// ��� ��Ȳ�� �� ����غ��� �Լ�.
int Nap(int cur, int idx, int move)
{
    // T���� ���Ҹ� ��� ����غ��Ҵٸ� Ż���Ѵ�.
    if (idx == T)
        return 0;

    int& ans = dp[cur][idx][move];
    if (ans != -1)
        return ans;
    ans = 0;

    // �����̱� �ʾ��� ���.
    int plus = board[idx] == cur ? 1 : 0;
    ans = max(ans, plus + Nap(cur, idx + 1, move));

    // �������� ���.
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
    // dp �迭�� �ʱ�ȭ.
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