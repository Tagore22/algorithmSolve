#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// �־��� ������ 3���̱⿡ idx��° ������ ���� �ִ� ���� ������ ����.
// 1. �ϳ��� ������ ��� ĥ�Ҷ�
// 2. 2���� ������ ĥ�Ҷ�. idx������ idx / 2���� �� ������ ��츦 �����ش�.
// 3. 3���� ������ ĥ�Ҷ�. idx������ idx / 3���� �� ������ ���
// idx - (idx / 3)������ 3���� �� ������ ��츦 �����ش�.

// �Ľ�Į�� �ﰢ���� ����Ͽ� �̸� ����� ���� ���� �������� ����÷ȴ�.

// �ڼ��� ������ �ּ����� �����.

long long dp[11][101][101][101];
long long com[11][11];
int N, R, G, B;

// �Ľ�Į�� �ﰢ���� �̿��� ��� ����� ���� �̸� ���ϴ� �Լ�
void Pascal()
{
    for (int i = 1; i <= N; ++i)
    {
        // �� ���� 1�� �ʱ�ȭ
        com[i][0] = com[i][i] = 1;
        // �Ľ�Į �׵�� 
        for (int j = 1; j < i; ++j)
            com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
    }
}

long long FindDP(int idx, int R, int G, int B)
{
    // ��� ������ ������� ���̻� ���Ҽ� �����Ƿ� 0�� ��ȯ�Ѵ�.
    if (R < 0 || G < 0 || B < 0)
        return 0;
    // 0���� �����Ͽ��ٸ� �����Ͽ����Ƿ� 1�� ��ȯ�Ѵ�.
    if (idx == 0)
        return 1;

    long long& ans = dp[idx][R][G][B];
    if (ans != -1)
        return ans;
    ans = 0;

    // 1���� ������ ��� ĥ�Ҷ�.
    ans += FindDP(idx - 1, R - idx, G, B);
    ans += FindDP(idx - 1, R, G - idx, B);
    ans += FindDP(idx - 1, R, G, B - idx);

    // 2���� ������ ĥ�Ҷ�.
    if (idx % 2 == 0)
    {
        int half = idx / 2;
        // idx���� ������ ���� �������� ���� ���� 1�̹Ƿ� �Ű澲�� �ʴ´�.
        ans += com[idx][half] * FindDP(idx - 1, R - half, G - half, B);
        ans += com[idx][half] * FindDP(idx - 1, R - half, G, B - half);
        ans += com[idx][half] * FindDP(idx - 1, R, G - half, B - half);
    }

    // 3���� ������ ĥ�Ҷ�.
    if (idx % 3 == 0)
    {
        int third = idx / 3;
        // idx���� 3���� 1���� ���� �ٽ� �������� 3���� 1���� ���� �������� ���� ���� 1�̹Ƿ� �Ű澲�� �ʴ´�.
        ans += com[idx][third] * com[idx - third][third] * FindDP(idx - 1, R - third, G - third, B - third);
    }
    return ans;
}

void MakeAnswer()
{
    // memset���� 0�̿��� ���� �ʱ�ȭ�ϱ⿡�� �Ҿ����ϱ⿡ fill()�� �̿��� �ʱ�ȭ�Ѵ�.
    fill(&dp[0][0][0][0], &dp[10][100][100][101], -1);
    Pascal();
    cout << FindDP(N, R, G, B) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> R >> G >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}