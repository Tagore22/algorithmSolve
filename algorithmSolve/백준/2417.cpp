#include <iostream>

using namespace std;

// Ǯ��.
// n�� �ִ밪�� 2�� 63���� - 1�̾��� ������ 1�� �÷����� ���ϱ⿣ �� ����������
// 10���� ��½ �پ�Ѵ� ���̱⿡ �Ұ����ߴ�. ������ �̺� Ž���� �̿��Ѵٸ�
// 100���� �ȵǼ� ���� �� �־���.

int main()
{
    unsigned long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    unsigned long long from = 1, to = 3037000500, mid;
    while (from <= to)
    {
        mid = (from + to) / 2;
        if (mid * mid >= n)
            to = mid - 1;
        else
            from = mid + 1;
    }
    cout << to + 1 << '\n';
    return 0;
}