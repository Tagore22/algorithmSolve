#include <iostream>

using namespace std;

// Ǯ��
// n�� ���� �ִ� 50���̱� ������ ��ȭ�Ŀ� ���� ���� int���� �����.
// n�� �̿��� ���갪�̱� ������ Ÿ���� int�� �Ǿ� �־� �����÷ο찡 �Ͼ����
// n�� Ÿ���� long long���� ���־�� �Ѵ�.

int main()
{
    long long n;
    cin >> n;
    cout << n * (n - 1) / 2 << '\n';
    cout << 2 << '\n';
    return 0;
}