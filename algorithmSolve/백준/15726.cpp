#include <iostream>

using namespace std;

// Ǯ��.
// �������� �Ҽ����� ������淡 �� �Ǽ��� ����ؾ��ϳ� �ߴµ� ��� ���߿��� �Ҽ����� �״�� �츰 ���·�
// ����� �Ŀ� �������� ����ȭ��Ű�� ���̾���. ����, float�� �ڸ����� �۾Ƽ� ������ ���ϱ� ������
// �Ǽ��� ����ϴ� ���������� float�� �ƴ϶� long double�� �������.

int main()
{
    long double a, b, c;
    cin >> a >> b >> c;
    int answer = max((a / b * c), (a * b / c));
    cout << answer << '\n';
}