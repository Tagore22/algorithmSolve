#include <iostream>

using namespace std;

// Ǯ��.
// ��! ���� ����! ������� ���� Ŀ���� ���� 100000, 1�� �־����� ����ε� �̶�
// ������� 90���� �ѱ� ������ int�δ� 100���� ������ ������ �����Ұ�.

int main()
{
    long long A, B;
    cin >> A >> B;
    cout << (A + B) * (A - B) << '\n';
    return 0;
}