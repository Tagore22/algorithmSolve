#include <iostream>

using namespace std;

// Ǯ��.
// ��4 �����ε� ���� ������ ���ٿ� ������ ���� �ɷȴ�.
// �������� �����ؼ� �ٽ� �������� ���� ������ ����Ŭ�� �����. ���� ����Ŭ�� �ֱ��� 8��ŭ �������־���ϴµ�
// �̶� ������ �κ��� �������� �������� 2���� ������ ����ٴ� ���̾���. ���� ���� ���ǹ��� �߰��Ͽ� ó���Ͽ���.

int main()
{
    int N;
    cin >> N;
    int answer = N % 8;
    if (answer == 1)
        cout << 1 << '\n';
    else if (answer == 0 || answer == 2)
        cout << 2 << '\n';
    else if (answer == 7 || answer == 3)
        cout << 3 << '\n';
    else if (answer == 6 || answer == 4)
        cout << 4 << '\n';
    else
        cout << 5 << '\n';
    return 0;
}