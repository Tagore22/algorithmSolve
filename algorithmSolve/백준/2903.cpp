#include <iostream>

using namespace std;

// Ǯ��.
// �� �������� ���� 2�� �����ŭ �þ��. ���� �������� ���� �� �����̴�.

int N;

int main()
{
    cin >> N;
    int idx = 1, num = 3;
    for (int i = 1; i < N; ++i)
    {
        idx *= 2;
        num += idx;
    }
    cout << num * num << '\n';
    return 0;
}