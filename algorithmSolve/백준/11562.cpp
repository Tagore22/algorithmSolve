#include <iostream>

using namespace std;

// Ǯ��.
// �׷��� �����ΰ� Ȯ���ߴ�. �÷��̵� ���� �ƴϸ� DFS�� Ž���ϴ� �����ε� �Ѵ� �ָ��ߴ�.
// ��������� ���ڿ��µ� �Ź� �Է½� ��������� �Ϲݹ��������� ���� �ʱ�ȭ���� �ٲٸ� �Ǿ���.
// ���� �˰� ���� �ſ� �翬�ϸ� ���� �������� �����س��Ⱑ ���� �ɷȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[251][251];
int N, M, K, S, E;

// ��� ���ҿ��� �ٸ� ���ҷ� �ٲپ���ϴ� ������� �ּҰ��� �̸� ���ϴ� �Լ�.
void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                // i���� j���� �ּҰ��� k�� ����ϴ� �� ����� �հ� �������� �ּҰ��̴�.
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void MakeAnswer()
{
    Floyd();
    for (int iter = 0; iter < K; ++iter)
    {
        cin >> S >> E;
        cout << board[S][E] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // ��������� �ٲپ���ϴ� �ּҰ����� �ʱ�ȭ.
    // N���� ������ �����ϴ� �ִ밪�� N - 1�ε� ����ϴ�.
    // ���� �ڽſ��� �ڽ������� ���� ������ 0�̴�.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                board[i][j] = 0;
            else
                board[i][j] = N - 1;
        }
    for (int i = 0; i < M; ++i)
    {
        int u, v, b;
        cin >> u >> v >> b;
        // u���� v���� �ּҰ��� ������ 0�̴�. �̵��� ������. 
        board[u][v] = 0;
        // ������̶�� �Ѵ� ���� �̵��� �����ϴ� 0�̰�,
        // �׷��� �ʴٸ� u���� v���� ���� �ϴ� 1�̴�.
        if (b == 0)
            board[v][u] = 1;
        else
            board[v][u] = 0;
    }
    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}