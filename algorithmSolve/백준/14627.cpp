#include <iostream>

using namespace std;

// Ǯ��.
// �̺� Ž���� �ݹ� ���÷��� ���� ����� ������ �ƴϾ��µ� �Ѱ��� ġ������ �Ǽ���
// �־���. �ļ��ϰ����� �������� ���� ���� ���� ���ϴ� �κ��ε� ���� ��� 3, 5,
// 100, 100, 100�� �־��� �� �� �Ĵ߿� �ִ� ���� ���� 50�̰� ���� ���� ����
// 50�̴�. ������ �������� ���� ���� ���� ���ϴ� ����� �� �ĸ� ��ȸ�ϸ�
// �Ĵ߿� �ִ� ���� ������ ���� ������������ ���ϰ� �־��⿡ 50�� �ƴ� 0��
// ���Դ�. ���� ���� �� ������ �Ĵ߿� �ִ� ���� �� * �Ĵ��� ������ ��
// ���� ����ؾ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int S, C;
int board[1000000];
long long sum = 0;

// mid������ ��� �Ĵ߿� �ĸ� ���� �� �ִ��� ���ϴ� �Լ�.
bool CalMax(int mid)
{
    int ans = 0;
    for (int i = 0; i < S; ++i)
        ans += board[i] / mid;

    return ans >= C;
}

void Solve()
{
    // ������ from ~ to�� int ������ �Ѿ�� ������ �Ŀ� C�� ��������
    // �������� �� ���� int���� ��� ���� �ֱ⿡ ���� �ϳ��� long long
    // Ÿ���̿��� �Ѵ�.
    long long from = 1, to = 1000000000;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (CalMax(mid))
            from = mid + 1;
        else
            to = mid - 1;
    }

    // ����Ѵ�� �̰����� �Ǽ��� �־���. ����ó�� �� �ĸ� ��ȸ�ϸ�
    // �Ĵ߿� ���� ���� ���� ���� ������ ���ϸ� �ȵȴ�.
    long long answer = sum - (from - 1) * C;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> C;
    for (int i = 0; i < S; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}