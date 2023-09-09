#include <iostream>

using namespace std;

// 11048���� �Լ��� ������� �ʰ� for���� �̿��� dp Ǯ��.
// ����Լ��� ������� �ʱ� ������ �� ������.
// ���� �ڵ��� ���̵� ª�� �������� ����.

// �ڼ��� ������ �ּ����� �����.

int board[1001][1001], dp[1001][1001];
int N, M;

void MakeAnswer()
{
    // �� ��ǥ���� ������ �Դ� ���� ����, ����, �»���� ũ�Ⱚ�� ���Ͽ� ���� ū �� + ���� ��ǥ�� ���� ����
    // �������� ���� ����Ѵ�.
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            dp[i][j] += board[i][j];
        }
    }

    cout << dp[N][M] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}