#include <iostream>

using namespace std;

// Ǯ��.
// ���� �������� ����� �ϴ� ������ ���ٸ� �� ����, ���ų� ũ�ٸ� 0�� ����ϸ� �ȴ�.

int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    int answer = K * N - M;
    cout << (answer > 0 ? answer : 0) << '\n';
    return 0;
}