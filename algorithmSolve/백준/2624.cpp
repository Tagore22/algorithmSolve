#include <iostream>

using namespace std;

// Ǯ��.
// DP�� ����ϴ� ������. �� ������ 0������ ����Ͽ� ��ȸ�ϱ� ������ �������� �������� �ߺ��� ������,
// idx��° ������ ����Ҷ� ���� �ݾ��� �� ��찡 �����Ѵ�. ���� ��� 1��°���� 10��¥�� �ϳ��� ������� ����
// 1��°�� �ǳʶٰ� 2��°���� 5��¥�� ������ 2���� ��������� 3��°������ �Ȱ��� 10���� ���ܵ� ���·� �����Ѵ�.
// �� ��� �ߺ��� �Ұ����ϴ�. ���� �� �κ��� DP�� �������ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

pair<int, int> board[100];
int dp[100][10001];
int T, K;

// ��� ��츦 ��ȸ�ϴ� �Լ�. ����Ѵ�� DP�� �ߺ��� ���´�.
int CalAnswer(int idx, int sum)
{
    // �ݾ��� 0���̶�� ����� �ϳ� ã�ұ� ������ 1�� ����Ѵ�.
    if (sum == 0)
        return 1;
    // ���������� �ݾ��� 0���� �ƴ϶�� �ᱹ ã�� ���Ѵ�. �׷��Ƿ� 0�� ��ȯ�Ѵ�.
    if (idx == K)
        return 0;

    // ����� DP�� ����.
    int& ans = dp[idx][sum];
    if (ans != -1)
        return ans;
    ans = 0;

    int cost = board[idx].first;
    int num = board[idx].second;
    for (int i = 0; i <= num; ++i)
    {
        // ���� ���� ���� �ݾ��� ������ ������ ũ�ٸ� ��������.
        // �� ������ �ݾ��� ���纸�� ������ Ŀ���� ������ for���� Ż���Ѵ�.
        if (cost * i > sum)
            break;
        // �׷��� ���� ��� ���� �ݾ��� �����Ͽ� ���ȣ���Ѵ�.
        else
            ans += CalAnswer(idx + 1, sum - cost * i);
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
        for (int j = 0; j <= T; ++j)
            dp[i][j] = -1;
    cout << CalAnswer(0, T) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> K;
    for (int i = 0; i < K; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}