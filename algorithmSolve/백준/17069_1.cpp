#include <iostream>

using namespace std;

// 17069���� ��Ͱ� �ƴ� �Ϲ� for���� �̿��� dp Ǯ��.
// ū Ʋ�� ���� Ǯ�̿� ������, ���״�� ��͸� ���ְ� �ܼ� for���� �̿��Ͽ���.

// �ڼ��� ������ �ּ����� �����.

bool board[33][33];
long long dp[34][34][3];
int N;

void MakeAnswer()
{
    dp[1][2][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 2; j <= N; ++j)
        {
            if (board[i][j])
                continue;

            // �������� �̵�. ���� ������ ���¿� �밢���� ���¿��� �̵� ����.
            if (!board[i][j + 1])
                dp[i][j + 1][0] = dp[i][j][0] + dp[i][j][2];
            // �Ʒ��� �̵�. ���� ������ ���¿� �밢���� ���¿��� �̵� ����.
            if (!board[i + 1][j])
                dp[i + 1][j][1] = dp[i][j][1] + dp[i][j][2];
            // �밢������ �̵�. ���� ����, ����, �밢���� ���¿��� �̵� ����.
            if (!board[i][j + 1] && !board[i + 1][j + 1] && !board[i + 1][j])
                dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        }

    long long answer = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}