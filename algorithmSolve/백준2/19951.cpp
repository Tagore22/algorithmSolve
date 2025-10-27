#include <iostream>

using namespace std;

// Ǯ��.
// ���� �迭 Ʈ���̶�� �˰����� ����ؾ��ϴ� ��������. ó�� ���� �˰����ε�
// �������ڸ� ���׸�Ʈ Ʈ���� ����ϴ�. �������� �ִٸ� ���׸�Ʈ Ʈ���� ������Ʈ��
// ����� ��������� ���� �迭 Ʈ���� ����� �� �������� �� �ѹ����̶�� ���̴�.
// �����̳� ���� ��ü�� ���� ����� ������ ������.

// �ڼ��� ������ �ּ����� �����.

int N, M;
int board[100001], diff[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    for (int i = 0; i < M; ++i)
    {
        int from, to, k;
        cin >> from >> to >> k;
        diff[from] += k;
        diff[to + 1] -= k;
    }
    for (int i = 1; i <= N; ++i)
    {
        diff[i] += diff[i - 1];
        board[i] += diff[i];
        cout << board[i] << ' ';
    }
    return 0;
}