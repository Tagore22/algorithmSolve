#include <iostream>

using namespace std;

// Ǯ��.
// 0 ~ N������ ������ �̺� Ž���� �̿��Ͽ� ���� �ּҰ��� ã�� ������.
// ��� �� ���� Ǯ�̸� ���� �� �� �ֵ��� �̺� Ž���� ����� �ʿ䵵 ������
// ������ �����ڸ� ������ ����

// 1. 0 ~ N ������ ������ �̺� Ž���� ��ȸ�ϸ� ���� ���⸦ ���Ͽ� ���� ���� * 2��
// �� ���ε� ������ ��� �Ÿ��� ���ߴ� �ּҰ��� ���ϴ� ��.

// �ٸ� 0 ~ ù��° ���ε������ �Ÿ��� �� ������ ���ε� ~ N������ �Ÿ��� ���� �ƴ�
// �ϳ��� ���ε����� ���߾���߱⿡ �� �κ��� ���� ��ư� �����߰�, �ּ� �Ÿ���
// �� �ΰ����� �� ū������ �Ͽ���.

int N, M, from, cur, gap = 0;

void Solve()
{
    int to = N + 1;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (mid * 2 >= gap)
            to = mid - 1;
        else
            from = mid + 1;
    }
    cout << to + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int prev = cur = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur;
        if (i == 0)
            from = cur;
        if (i == M - 1)
            from = max(from, N - cur);

        gap = max(gap, cur - prev);
        prev = cur;

    }
    gap = max(gap, N - prev);
}

int main()
{
    Input();
    Solve();
    return 0;
}