#include <iostream>

using namespace std;

// �̺� Ž���� �ι�° Ǯ��. for���� �ƴ϶� while���� ����Ѵ�.

// 1. while���� �̿��� Ǯ�̴� �������� ������ �������� �����⿡
// mid���� ��ȯ ���� �߰����� ������ �ʿ���.
// 2. �׷��Ƿ� �ʱ� ������ ������ �ʿ����� ����.
// 3. for���� ������ 100���� �ǽ����� Ż���ϱ⿡ mid���� ��ȯ ���� �߰����� ������ �ʿ����.
// 4. �׷��Ƿ� �ʹ� ������ -1, +1�� �߰����� ������ �ʿ���.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int N, M, cur;

bool CheckSum(int num)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans += board[i] > num ? num : board[i];
        if (ans > M)
            return false;
    }
    return true;
}

void MakeAnswer()
{
    // ������ for���� �ٸ��� ��� ���ԵǾ� �ִ� ���¿��� �����Ѵ�.
    int left = 0;
    int right = cur;
    // left�� right�� ������������ �ǽ���.
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // �������� �ϱ⿡ mid���� ��ȯ ���� �߰����� ������ �ִ�.
        if (CheckSum(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    // ���� �ֱ� ������ mid ���� left�� mid + 1�̾����Ƿ� left - 1�� ���� �ֱ� �����̴�.
    cout << left - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        cur = max(cur, board[i]);
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}