#include <iostream>

using namespace std;

// Ǯ��.
// L�� �Ÿ��� �ּ����� �ð����� �����Ѵٴ� ���� �Ź� �ִ� �Ÿ��� �̵��ؾ� �Ѵٴ� ���̴�.
// ���� L�� 5�� ������ ���� �������� �����Ѵٸ� �� �Ÿ���ŭ 1�� �� �̵��ؾ��Ѵ�.

int main()
{
    int L;
    cin >> L;
    int answer = L % 5 == 0 ? L / 5 : L / 5 + 1;
    cout << answer << '\n';
    return 0;
}