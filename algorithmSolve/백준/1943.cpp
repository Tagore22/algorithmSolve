#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �������� 20�۵� �ȳ����� ��������. DP�� �̿��� ���� �������µ� 2���� ��쿡��
// �� ���ų� ���� ��츦 ����ϴ� ������ ��İ��� �޶��⿡ �߻���� ���� �ɷȴ�.
// ��������� ������ ��츦 1��, �Ұ����� ��츦 0�� ��ȯ�Ͽ� ���� �� ū���� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

pair<int, int> board[100];
int dp[50001][100];
int N, sum;

int Nap(int cost, int idx)
{
    // ���� ã�� ���. 1�� ��ȯ.
    if (cost == sum)
        return 1;
    // ���������� ã�� ���� ���. 0�� ��ȯ.
    if (idx == N)
        return 0;

    int& ans = dp[cost][idx];
    if (ans != -1)
        return ans;
    ans = 0;

    // ������ �ִ� ������ ������ŭ ��ȸ�Ѵ�.
    for (int i = 0; i <= board[idx].second; ++i)
    {
        // ���ݰ����� ������ Ŀ�� ��� �����Ѵ�.
        if (cost + board[idx].first * i > sum)
            continue;
        // ��� ����� ���� ū ���� ��ȯ�Ѵ�.
        // ���д� 0, ������ 1�̱� ������ �� �ѹ��� �����ص�
        // 1�� ��ȯ�ȴ�.
        ans = max(ans, Nap(cost + board[idx].first * i, idx + 1));
    }
    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < 3; ++iter)
    {
        cin >> N;
        sum = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> board[i].first >> board[i].second;
            sum += board[i].first * board[i].second;
        }
        // �ֽô��� ������ Ȧ����� 0�� ��ȯ�Ѵ�.
        if (sum % 2 != 0)
        {
            cout << 0 << '\n';
            continue;
        }
        sum /= 2;
        memset(dp, -1, sizeof(dp));
        cout << Nap(0, 0) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}