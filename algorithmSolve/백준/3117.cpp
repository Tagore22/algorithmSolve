#include <iostream>
#include <cmath>

using namespace std;

// Ǯ��.
// ����� ��� �迭 �����ʹ� ��¦ �ٸ� ���� �־���. �������� ���۰����� ��� �迭�� ���ԵǾ� ���� ������
// �� ���������� �� ù��° �迭�� ��� �迭���� ������� �־����ٴ� ���̴�. ���� ���� Ƚ�� M�� 1 �����Ͽ�
// ���� ���ؾ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int dp[30][100001], board[100001];
int N, K, M;

void MakeAnswer()
{
    int to = log2(M);
    for (int i = 1; i <= to; ++i)
        for (int j = 1; j <= K; ++j)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    for (int i = 1; i <= N; ++i)
    {
        // ��Ʈ����ũ�� ��ȸ�ϸ� ������ j��°�� ã�´�.
        // �ٸ� ����Ѵ�� ��� �迭�� ������� ù��° �迭���� �����ϱ⿡
        // M - 1�� ���Ѵ�.
        int answer = board[i];
        for (int j = to; j >= 0; --j)
            if ((1 << j) & (M - 1))
                answer = dp[j][answer];
        cout << answer << ' ';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    for (int i = 1; i <= K; ++i)
        cin >> dp[0][i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}