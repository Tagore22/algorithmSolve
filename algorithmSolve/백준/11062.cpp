#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �̴ϸƽ� �˰����� �ȴٸ� ����� ���� ������.
// ������ ���� ��������� ó�������� Ȯ��ġ ������ ��̴�;
// �̴ϸƽ� �˰����� ������ �������ڸ� �����϶����� �ִ밪��,
// ������϶����� �ּҰ��� ���ϸ� �ȴ�.
// ���� MakeMax()�� 3��° �Ű������� dp�� ���� Ǯ�̵� �ִµ� �̰�
// ����ġ�� ������. �ֳ��ϸ� ó���� 4���� ���� ������ ù��° �÷��̾��϶�����
// ������ ¦������ �����ϰ�, �ι�° �÷��̾��϶����� ������ Ȧ������ �����ϱ� ������
// �ֽô��� ������ �������� ���� �����̴�.

// �ڼ��� ������ �ּ����� �����.

int board[1000];
int dp[1000][1000];
int T;

// ��� ����� ���� �̴ϸƽ� �˰����� �̿��Ͽ� ��ȸ�ϴ� �Լ�.
int MakeMax(int left, int right, bool ismine)
{
    if (left > right)
        return 0;

    int& ans = dp[left][right];
    if (ans != -1)
        return ans;

    // ����Ͽ��� �����϶����� �ִ�� ����� ���϶����� �ּҸ� ���Ѵ�.
    if (ismine)
        ans = max(MakeMax(left + 1, right, !ismine) + board[left],
            MakeMax(left, right - 1, !ismine) + board[right]);

    else
        ans = min(MakeMax(left + 1, right, !ismine),
            MakeMax(left, right - 1, !ismine));

    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i)
            cin >> board[i];

        memset(dp, -1, sizeof(dp));
        // ���⼭ �ִ밪�� ���Ѵ�.
        int answer = MakeMax(0, num - 1, true);

        cout << answer << '\n';
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