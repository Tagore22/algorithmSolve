#include <iostream>

using namespace std;

// Ǯ��.
// double�ε� 1000�ڸ��� ���������� �Ǹ��Ҽ� �����Ƿ� ���� ����ؾ��Ѵ�.
// ���� 1 / 3�� 1000�ڸ����� �Ҽ��ο� �����η� ������ ���� ����ϸ� �ȴ�.

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a / b << '.';

    for (int i = 0; i < 1000; ++i)
    {
        a %= b;
        a *= 10;
        cout << a / b;
    }
    return 0;
}