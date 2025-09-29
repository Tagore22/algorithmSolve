#include <iostream>

using namespace std;

// Ǯ��.
// �������� �÷��̵� ���� �˰����� �̿��� ��������. �����ؾ��� �κ��� ������ ����.

// 1. � �������� �ٸ� ���������� �ּҰŸ�(����ġ)�� �˾ƾ� �ϴµ� �̰��� ������ �ݺ��ǹǷ�
// �÷��̵� ���� �˰����� ����ؾ��Ѵ�.
// 2. �÷��̵� ���� �˰��򿡼� ���������� ������� ���� ��δ� ��û ū ����, A -> A ��
// �� �ڽ������� �̵��� 0���� �ʱ�ȭ�� �ؾ��ϴµ� ������ ���̵��� ���Ƽ����� �Է¿���
// ���� ó�����ֱ� ������ �Ű澵 �ʿ䰡 ����.

// ����, �� �Ÿ����� �Է¹޾� �ּҰŸ��� ã�� �Ŀ� �ٽ� �Է��� �޾� �־��� �ð�����
// ª�ų� �������� Ȯ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[501][501];
int N, M;

// �÷��̵� ���� �˰����� �����ϴ� �Լ�.
void Floyd()
{
    // ����Ѵ�� A -> A = 0 ���� ó���� �Ű澲�� �ʾƵ� �ȴ�.
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];

    Floyd();

    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        if (cost >= board[from][to])
            cout << "Enjoy other party" << '\n';
        else
            cout << "Stay here" << '\n';
    }
    return 0;
}