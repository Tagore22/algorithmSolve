#include <iostream>

using namespace std;

// Ǯ��.
// �ּҰ������ ��ȭ���� �� ���� �� / �ִ������̴�. �ִ������� �̹� ����� �����ϹǷ�
// �� ��ȭ�İ��� �״�� ����ϸ� �ȴ�.

long long a, b;

long long GDC(int a, int b)
{
    if (b == 0)
        return a;
    return GDC(b, a % b);
}

int main()
{
    cin >> a >> b;
    cout << a * b / GDC(a, b) << '\n';
    return 0;
}