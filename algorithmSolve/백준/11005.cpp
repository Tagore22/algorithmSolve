#include <iostream>

using namespace std;

// Ǯ��.
// ���� ��ȯ �����̴�. ������ ��ȯ�Ϸ��� �� N�� 0���� ū���� ���� B�� ������ �� �������� �տ������� ���̸� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int N, B;

int main()
{
    cin >> N >> B;

    string answer;
    // N�� 0���� Ŭ���� �ݺ��Ѵ�.
    while (N > 0)
    {
        // N�� B�� ������ �� ���� 10���� ���ų� �۴ٸ� ���� �״��,
        // �׷��� �ʴٸ� ���ĺ����� �������� �պ��� ����ִ´�.
        int div = N % B;
        char plus = div >= 10 ? div + 55 : div + 48;
        answer = plus + answer;

        // N�� B�� ������.
        N /= B;
    }

    // ������ answer ���.
    cout << answer << '\n';
    return 0;
}