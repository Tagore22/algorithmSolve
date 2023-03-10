#include <iostream>

using namespace std;

// Ǯ��
// ����� DP�����ε� �ʹ� �����ɷȴ�.
// �� �Ʒ� N���� �迭���� ���� DP[0][K] Ȥ�� DP[1][K]�� �ִ밪�� ����ϸ� �ȴ�.
// �� ���� k - 1�� �밢�� ���� ������ ��� Ȥ�� k - 2�� �밢���� ������ ��� 2�����̹Ƿ� �� ���� �ִ밪��
// �Ź� �����ϸ� �ȴ�.

int board[2][100000], dp[2][100000];
int T, N, answer;

void CalDP()
{
    dp[0][0] = board[0][0];
    dp[1][0] = board[1][0];
    dp[0][1] = board[1][0] + board[0][1];
    dp[1][1] = board[0][0] + board[1][1];

    for (int i = 1; i < N; ++i)
    {
        dp[0][i] = max(dp[1][i - 1] + board[0][i], dp[1][i - 2] + board[0][i]);
        dp[1][i] = max(dp[0][i - 1] + board[1][i], dp[0][i - 2] + board[1][i]);
    }

    cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
}

void MakeAnswer()
{
    for (int test = 0; test < T; ++test)
    {
        answer = 0;
        cin >> N;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];
        CalDP();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}