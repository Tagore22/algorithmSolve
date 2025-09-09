#include <iostream>

using namespace std;

// Ǯ��.
// �������� DP���µ� ���ó� ������. ������ �帧�� DP�� ������ ��ġ��Ű�°�
// �ϳ� ������µ� DP���� ������ �԰��� ���� �󸶵��� Ŀ������ �����ϱ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

string m, a, b;
// i��° ���ڸ� j��°���� ã���� ��.
int dpA[20][100], dpB[20][100];

// ��� ��츦 ã�� �Լ�. idx��° ���ڸ� here���� ã�� ����.
int FindNum(int here, int idx, bool isA)
{
    // ��� ���ڸ� ã���� �� 1�� ��ȯ�Ѵ�.
    if (idx >= m.size() - 1)
        return 1;
    // DP���� �����ڸ� �̿��Ͽ� �����Ѵ�.
    int& ans = isA ? dpA[idx][here] : dpB[idx][here];
    if (ans != -1)
        return ans;

    // DP���� �ʱ�ȭ.
    ans = 0;
    string str = isA ? b : a;
    // here���� ã�ұ� ������ �� ������ here + 1���� ��ȸ�� �����Ѵ�.
    for (int i = here + 1; i < str.size(); ++i)
    {
        // ���� ã�Ҵٸ� ��� �Լ��� ȣ���Ͽ� �� ���ĸ� ã�´�.
        if (str[i] == m[idx + 1])
        {
            if (isA)
                ans += FindNum(i, idx + 1, false);
            else
                ans += FindNum(i, idx + 1, true);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> a >> b;
    // DP������ �ʱ�ȭ.
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            dpA[i][j] = -1;
            dpB[i][j] = -1;
        }
    }
    int answer = 0;
    // ���ڿ��� ��ȸ�ϸ� ù��° ���� ã���� ��쿡�� ��� ȣ���� ���۵ȴ�.
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == m[0])
            answer += FindNum(i, 0, true);
        if (b[i] == m[0])
            answer += FindNum(i, 0, false);
    }
    cout << answer << '\n';
    return 0;
}