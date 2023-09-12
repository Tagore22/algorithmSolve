#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// 15486���� Ʋ�� Ǯ������ ������ ���� ���ܵд�.
// ���� ��ü�� ����� �ʴ�. ���� Ž���� �̿��Ͽ� ��� ��쿡�� ���� ū ������ ���ϸ� �Ǵµ�
// ���� Ǯ���� �������� �ʹ� ���� �������� ���� �ð��ʰ��� ���ٴ� ���̴�.
// ó������ dp�̱⿡ �迭���� 150������ ������ �������� ���������� �׷��� �ʾҴ�.
// CalMax()�� for���� ���� ���� ���� ���� idx���� N���� ��ȸ�� �ϴµ� ���Ⱑ ������.
// ���� ��� 1 ~ 150���ϵ��� �۾��ð��� 1���� ��츦 �����غ��� for����
// 150�������� 1�� �پ��� ��û�� ������ �ʿ�� �Ѵ�. �ٷ� �̰Ͷ����� �ð��ʰ��� �����̴�.
// ��¥ Ǯ�̴� ������ ������ �̿��ؾ� �Ѵ�.

pair<int, int> board[1500000];
int dp[1500000];
int N;

int CalMax(int idx)
{
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = idx; i < N; ++i)
        if (i + board[i].first <= N)
            ans = max(ans, CalMax(i + board[i].first) + board[i].second);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = CalMax(0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}