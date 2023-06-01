#include <iostream>

using namespace std;

// Ǯ��.
// �Ǻ���ġ ������ �ݴ� �����̴�.
// ������ D��° ������ �־������� ù��°, �ι�° ������ ���ϴ� �����̴�.
// �� ������ ���� �ּ� 1�̹Ƿ� �־��� D��° ������ 1 ~ K - 1������ ���� �ϳ��� ����
// D - 1��° ������ ���� �� ù��° �������� ������ ����������.
// �ٸ� �� �������� 

// 1. ���� Ȥ�� 0�� ���ü� ����.
// 2. dp[N]�� dp[N + 1]���� Ŭ������.

// �� 2���� ������ ���Ѿ߸� �Ѵ�.
// �� ������ ������Ű�� ù��°, �ι�° ������ ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int dp[30];
int D, K;

void MakeAnswer()
{
    // 1. dp[D - 2]���� K ~ 0������ ��ȸ�Ѵ�.
    // 2. dp[D - 3]���� dp[0]���� ����� �ִٸ� �װ��� ���ε�
    // ������ �����ų� dp[D - N]���� dp[D - N + 1]�� �� �۴ٸ� ���� �ݺ����� Ż���Ѵ�.
    bool isfind;
    for (int iter = 1; iter < K; ++iter)
    {
        isfind = true;
        dp[D - 2] = dp[D - 1] - iter;
        for (int i = D - 3; i >= 0; --i)
        {
            dp[i] = dp[i + 2] - dp[i + 1];
            if (dp[i] <= 0 || dp[i] >= dp[i + 1])
            {
                isfind = false;
                break;
            }
        }
        if (isfind)
        {
            cout << dp[0] << '\n';
            cout << dp[1] << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D >> K;
    dp[D - 1] = K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}