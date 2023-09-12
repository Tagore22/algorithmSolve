#include <iostream>
#include <cstring>

using namespace std;

// 15486���� ����� �� Ǯ��.
// ������ �̿��Ͽ� ���� ���� ó���ϴ� ���� ���� ���� 2���� ���� ������ ó���Ѵ�.
// ���� ���� �ݺ��Ǵ� ���� �ѹ��� ó������ �ʴ� ����ε� �� ��쿡�� 150������ ó���Ǹ�
// ó���ϴ� ���� ����� ���� ������ �� ����.

// �ڼ��� ������ �ּ����� �����.

pair<int, int> board[1500000];
int dp[1500000];
int N;

// ���� Ǯ�̸� �̿��Ͽ� ��� ��츦 ��ȸ�ϴ� �Լ�.
int CalMax(int idx)
{
    // idx�� N�� �̻��� ��� ����ϴ� ���� �������Ƿ� 0�� ��ȯ�Ѵ�.
    if (idx >= N)
        return 0;

    // dpó��.
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;
    // ���� ���� ó���Ҽ� �ִ� ���. board[idx].first��ŭ ���ڰ� ������
    // board[idx].second��ŭ ������ ����.
    if (idx + board[idx].first <= N)
        ans = CalMax(idx + board[idx].first) + board[idx].second;

    // ���� ���� ó���Ҽ� ���� ���. �ð��� �Ϸ� ����Ѵ�.
    ans = max(ans, CalMax(idx + 1));

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = CalMax(0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}