#include <iostream>

using namespace std;

// Ǯ��.
// ������ �������� �ô� '�Ǽ� ���꿡���� float���ٴ� long double�� ���'��� ���� ��ﳵ�� �����̴�.
// �ٸ� �� ������ ������ ���� �Ű澵 �ʿ䰡 ������ float�� �ᵵ ����� ����.

int main()
{
    float a, b;
    cin >> a >> b;
    cout << (a - (a * b / 100) < 100) ? 1 : 0 << '\n';
    return 0;
}