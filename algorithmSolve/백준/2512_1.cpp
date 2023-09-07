#include <iostream>

using namespace std;

// 2512���� �̺�Ž�� Ǯ���� ù��° Ǯ��.
// �̺�Ž���� ũ�� 2������ ������. 

// 1. for���� �̿��Ͽ� ������ 100���� �̺� Ž���� �ǽ��ϴ� Ǯ��.
// 2. while���� �̿��Ͽ� �������� ������ ��߳������� Ž���� �ǽ��ϴ� Ǯ��.

// �Ѵ� �����ϴ��� ������ ��������� �����ڸ� �̺� Ž���� 100���̻��� ���� 1����
// �׷��� ���� ���� 2���� �̿��Ͽ� Ǯ�� �ȴ�. �׷��� ������ ������ �˾Ƶξ�� �Ѵ�.
// �̹� Ǯ�̴� ���� ù��° Ǯ�̴�. ��� ������ �� ������ �ٸ���.

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
    // for���� �̿��� ������ ��� ���� ������ ���Ե��� �ʴ� -+1���� ���۵ȴ�.
    int left = 0;
    int right = cur + 1;
    // 100���� ���������� �̺� Ž��.
    for (int i = 0; i < 100; ++i)
    {
        int mid = (left + right) / 2;
        // ������ ���н� left Ȥ�� right�� mid���� �ɻ� �߰����� ������ ����.
        if (CheckSum(mid))
            left = mid;
        else
            right = mid;
    }
    // ���� �������� left����. ������ ��ȭ�ϴ� ���� ����ϸ� �ȴ�.
    cout << left << '\n';
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