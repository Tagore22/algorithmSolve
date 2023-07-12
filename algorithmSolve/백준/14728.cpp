#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// dp�� ���������� ���� ������.
// �� N���� ������ ������ �� ������ �����ϴ��� ���� �ʴ����� 2���� ��츦 ��� �����ϵ�,
// dp�� �ߺ��� ������ �ȴ�.

// �ڼ��� Ǯ�̴� �ּ����� �����.

pair<int, int> board[100];
int dp[10001][100];
int N, T;

// ��� ������ �غ��� �Լ�. ����Ͽ����� dp�� �ߺ��� ���´�.
int BackTrack(int num, int idx)
{
    if (idx == N)
        return 0;

    int& ans = dp[num][idx];
    if (ans != -1)
        return ans;

    // ���� ������ �������� �ʴ� ���.
    ans = BackTrack(num, idx + 1);

    // ���� ������ �����Ҽ� ������ �����ϴ� ���.
    if (board[idx].first <= num)
        ans = max(ans, BackTrack(num - board[idx].first, idx + 1) + board[idx].second);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));

    int answer = BackTrack(T, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}