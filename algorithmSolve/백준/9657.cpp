#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �����̷��� �����Ͻ� Ǯ��. ��Ʈ ����� ���������� ���Ƽ�
// �ٸ� Ǯ�̰� �� �������� ������ ����. �ٸ� �̹�ĵ� �ݵ�� �˾ƾ��ϱ⿡
// �� Ǭ�Ͱ���.

// �ڼ��� ������ �ּ����� �����.

int dp[1001];
int N;

int DFS(int num)
{
    // ���̻� ���� ���� ���ٸ� �ݵ�� �й��Ѵ�.
    if (num == 0)
        return 0;

    int& ans = dp[num];
    if (ans != -1)
        return ans;

    // �ʱ�ȭ�� �й��.
    ans = 0;
    // 0�� �ƴ϶�� �ݵ�� 1�� �̻��̹Ƿ� if���� �ʿ����.
    // 1���� ������������ ����� �����Ͽ� ans�� ���Ѵ�.
    ans |= DFS(num - 1) ^ 1;
    // ���� ���� 3�� �̻��϶� ��.
    if (num >= 3)
        ans |= DFS(num - 3) ^ 1;
    // ���� ���� 4�� �̻��϶� ��.
    if (num >= 4)
        ans |= DFS(num - 4) ^ 1;

    return ans;
}

int main()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));
    int answer = DFS(N);
    if (answer == 1)
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
    return 0;
}