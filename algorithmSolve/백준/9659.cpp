#include <iostream>

using namespace std;

// Ǯ��.
// ��� Ǯ��� ������ ��Ȯ�� ����� �ȳ���. ���� ������ 1���� ���ϴ°� ��°ġ��
// �ֽô��� �ѹ��� ���� �ִ� ���� ������ Ȧ������ ���� ���۽� ¦����� â���̰� �̱��
// Ȧ����� ������ ����̰� �̱��.

int main()
{
    long long N;
    cin >> N;
    string answer = N % 2 == 0 ? "CY" : "SK";
    cout << answer << '\n';
    return 0;
}