#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��
// ������ ���ø��°� ũ�� ����� �ʾҴ�. ���ܰ��� ���簡 �������� ȸ���Ͽ�
// ���� �ܰ��� ���絵 ���ư� �� �����Ƿ� dp�� [���� �ܰ�][���ư� ��]�� �ؾ��ߴ�.
// ���� �ִ� 9�� ���ư� �� �����Ƿ� ���� ��� �̵��� 10���� ������ ������ �ؾ��ߴ�.
// �ٸ� ���ʰ� ������ ȸ���� �Ųٷ� �ؼ� �ϳ� ��̴�;

// �ڼ��� ������ �ּ����� �����.

int N, dp[10000][10];
string from, to;

int DPFunc(int idx, int rolnum)
{
    // ���� ���.
    if (idx >= N)
        return 0;

    int& ans = dp[idx][rolnum];
    if (ans != -1)
        return ans;
    ans = 987654321;

    // ���� ��ġ. ���ܰ��� ������� �������� �̵��ߴ� ���� �ݿ���.
    int cur = ((from[idx] - '0') + rolnum) % 10;
    int left = ((to[idx] - '0') + 10 - cur) % 10;
    ans = min(ans, DPFunc(idx + 1, (rolnum + left) % 10) + left);
    int right = (cur + 10 - (to[idx] - '0')) % 10;
    ans = min(ans, DPFunc(idx + 1, rolnum) + right);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N >> from >> to;
    cout << DPFunc(0, 0) << '\n';
    return 0;
}