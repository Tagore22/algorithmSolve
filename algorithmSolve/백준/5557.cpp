#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// 100������ + Ȥ�� - �� �����Ͽ� �� ���귮�� 2�� 100�������� ���� �ð����� ���� Ǯ�� �������Ƿ�
// DP���� Ȯ��������, ��� DP�� ������ϴ��� �� ���������� �ʾҴ�.
// �ߺ��Ǵ� ���� �����Ͽ��� DP�� ���� �ߺ��� ���־� �ϴµ� �� �ߺ��Ǵ� ���� �� �������� �ʾҴ� ���̴�.
// �� �����غ��� idx��°���� �����Ҷ� ���� ���� sum�϶� �ߺ��� �����ߴ�. �̰��� DP�� ����
// ����Ž���� �����ϸ� �ȴ�. ����, �ִ밪�� 2�� 64���� - 1�����̹Ƿ� int�� �ƴ� long long�� ����Ͽ�
// Ǯ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[100];
long long dp[21][100];
int N;

// sum = board[0], idx = 1�� ����
// ����Ž���� �����ϴ� �Լ�. ����Ͽ��� idx��°�� ���簪�� sum�϶�
// �ߺ����� �����ϱ⿡ �̰��� DP�� ������ �ȴ�.
long long BackTrack(int sum, int idx)
{
    if (idx == N - 1)
        return sum == board[idx] ? 1 : 0;

    long long& ans = dp[sum][idx];
    if (ans != -1)
        return ans;

    ans = 0;
    // ���� ����.
    if (sum + board[idx] <= 20)
        ans += BackTrack(sum + board[idx], idx + 1);
    // ���� ����.
    if (sum >= board[idx])
        ans += BackTrack(sum - board[idx], idx + 1);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    long long answer = BackTrack(board[0], 1);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}