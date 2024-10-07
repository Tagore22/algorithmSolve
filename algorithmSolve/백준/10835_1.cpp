#include <iostream>

using namespace std;

// 10835���� �� ���� Ǯ��.
// �������� ����Լ��� �̿��߱⿡ �� ���� ����� �ð��� �ʿ��ߴ�.
// ������ ������ for���� �̿��Ͽ��� �Ʒ��� ���� Ǯ�� �ִ�.
// �����ؾ��ϴ� ���� ���� 2������ ����.

// 1. for���� �̿��ϴ� DPǮ�̴� ������ �Ʒ��� ��������. ���� ��Ϳ� �ݴ� �����̴�.
// 2. N - 1���� �����ϵ�, + 1 �Ǵ� ��Ȳ�� �����ϱ⿡ board�� dp�� ���� 1�� �þ�� �Ѵ�.

int boardL[2001], boardR[2001], dp[2001][2001];
int N;

void MakeAnswer()
{
    for (int l = N - 1; l >= 0; --l)
        for (int r = N - 1; r >= 0; --r)
        {
            if (boardL[l] > boardR[r])
                dp[l][r] = dp[l][r + 1] + boardR[r];
            else
                dp[l][r] = max(dp[l + 1][r], dp[l + 1][r + 1]);
        }
    cout << dp[0][0] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> boardL[i];
    for (int i = 0; i < N; ++i)
        cin >> boardR[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}