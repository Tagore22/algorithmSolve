#include <iostream>

using namespace std;

// Ǯ��.
// ó������ 100�� ����� ���� ������ ����.
// ���������� 100���� �־����ٸ� �����Ѵ�.

int main()
{
    int sum = 0;
    int num;
    for (int i = 0; i < 10; ++i)
    {
        cin >> num;
        if (abs(100 - (sum + num)) <= abs(100 - sum))
            sum += num;
    }
    cout << sum << '\n';
    return 0;
}