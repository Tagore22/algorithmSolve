#include <iostream>

using namespace std;

// Ǯ��.
// �������� DP���������� DP�� ��� �̿��Ұ����� ���� �򰥷ȴ� �����̴�.
// ���� ���̿� ���������� ������ ��(0 ~ 9����)�� 2���� �迭�� ����Ͽ� �����ϸ� ����� �ʴ�.

int dp[1001][10]; // ����, N���� ������ ���.
int N;
const int DIV_NUM = 10007;

void MakeAnswer()
{
    // ���̰� �󸶵� 0���� ������ ���� �� �ϳ�.
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 1;

    // ���̰� 1�� ���, ��� ���� �� �ϳ�.
    for (int i = 0; i <= 9; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= N; ++i)
        for (int j = 1; j <= 9; ++j)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIV_NUM;

    int answer = 0;
    for (int i = 0; i <= 9; ++i)
        answer = (answer + dp[N][i]) % DIV_NUM;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}