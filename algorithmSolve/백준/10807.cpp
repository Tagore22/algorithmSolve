#include <iostream>

using namespace std;

// Ǯ��.
// �迭�� �����Ͽ� �Է¹��� ���� ������Ű�� �Ͽ����� ������ -100 ~ 100�̿���.
// ���� �Է¹����� + 100�� �迭�� �������Ѿ��ߴ�.

int board[201];
int N, V;

int main()
{
    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        ++board[num + 100];
    }
    cin >> V;
    cout << board[V + 100] << '\n';
    return 0;
}