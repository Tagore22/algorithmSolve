#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// DP�� �̿��Ͽ� Ǭ �ڵ��. �� ��Ȳ�� �°� �������� ��츦 �����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int N, M;
int dp[101][200], cost[3] = { 10000, 25000, 37000 };
bool notgo[101];

int DPFunc(int day, int coupon)
{
    // ó������ DPFunc�� ȣ���� �� day�� �ʱⰪ�� 0���� �����Ͽ� if(day >= N)�̾�����
    // �׷��� ���������� �ȸ±� ������ day ���� 1�� �ٲٸ鼭 if���� �Բ� �����Ͽ���.
    if (day > N)
        return 0;

    int& ans = dp[day][coupon];
    if (ans != -1)
        return ans;

    ans = 987654321;
    // ����Ʈ�� �� �� ���� ��.
    if (notgo[day])
        return ans = min(ans, DPFunc(day + 1, coupon));
    // ���� �Ϸ�, 3��, 5�� �̿���� ������ ���.
    ans = min(ans, DPFunc(day + 1, coupon) + cost[0]);
    ans = min(ans, DPFunc(day + 3, coupon + 1) + cost[1]);
    ans = min(ans, DPFunc(day + 5, coupon + 2) + cost[2]);
    // ������ ����� ���.
    if (coupon >= 3)
        ans = min(ans, DPFunc(day + 1, coupon - 3));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(notgo, false, sizeof(notgo));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int day;
        cin >> day;
        notgo[day] = true;
    }

    cout << DPFunc(1, 0) << '\n';
    return 0;
}