#include <iostream>

using namespace std;

// Ǯ��.
// �� ����� 3�����̴�. 

// 1. �׳� ������ ����.
// 2. �׳� ������ ����.
// 3. ������ �����ʺ��� Ŭ�� �����ʸ��� ������ �� ������ ȹ����.

// �׳� �����غ��� ���̰� �ִ� 2000�̸鼭 1�� 2���� ������ ���������� ������ �ʹ� Ŀ������
// DP�� �̿��ϸ� �ִ� 400������ ���귮�� ���ϼ� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int boardL[2000], boardR[2000], dp[2000][2000];
int N;

// ��� ��츦 Ȯ���غ��� �Լ�.
int CalAns(int l, int r)
{
    // ������ �ƹ����̳� ��� ī�带 �پ��ٸ� 0�� ��ȯ�ϸ� Ż���Ѵ�.
    if (l == N || r == N)
        return 0;

    int& ans = dp[l][r];
    if (ans != -1)
        return ans;
    ans = 0;

    // �׳� ������ ���� ���.
    ans = max(ans, CalAns(l + 1, r));
    // �׳� ������ ���� ���.
    ans = max(ans, CalAns(l + 1, r + 1));
    // ���� �������� �� �۴ٸ� �����ʸ��� ������ �� ������ ȹ����.
    if (boardL[l] > boardR[r])
        ans = max(ans, CalAns(l, r + 1) + boardR[r]);
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = -1;
    cout << CalAns(0, 0) << '\n';
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