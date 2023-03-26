#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �������� DP �����ε� �̻��ϰ� ������� ���� ������.
// �������� �ִ� ���� �����ʰ� �Ʒ� 2�����ε�, �ִ� 100 X 100 = 10000���� ĭ�� �ֱ⿡
// DP�� ���� ������ 2�� 10000������ �Ǿ� ���귮�� �ʹ� Ŀ����.

// �� ��ǥ���� [N - 1][N - 1]�� �����ϴ� ��θ� �����Ͽ�
// ��������� [0][0]�� ����ϸ� �ȴ�.

int board[100][100];
long long dp[100][100];
int rot[4][2] = { {0, 1}, {1, 0} }; // ��, ��.
int N;

long long DP(int y, int x)
{
    if (y == N - 1 && x == N - 1)
        return 1;

    long long& ans = dp[y][x];
    if (ans != -1)
        return ans;

    ans = 0;

    int dy, dx;
    for (int i = 0; i < 2; ++i)
    {
        dy = y + rot[i][0] * board[y][x];
        dx = x + rot[i][1] * board[y][x];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N)
            continue;

        ans += DP(dy, dx);
    }

    return ans;
}

void MakeAnswer()
{
    DP(0, 0);

    cout << dp[0][0] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}