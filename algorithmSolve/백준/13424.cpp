#include <iostream>

using namespace std;

// Ǯ��.
// �ν��� �ִܰŸ��� �Ѳ����� ������ ���ؾ��ϹǷ� �÷��̵� ���� �˰����� ����ؾ��ߴ�.
// �װ͸� �˸� ���� ����� �;��� ���Ը� �ϸ� �ȴ�.

int T, N, M, K;
int board[101][101], friends[100];

void Floyd()
{
    for (int i = 1; i <= N; ++i)
        board[i][i] = 0;
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = 987654321;
        int from, to, dist;
        for (int i = 0; i < M; ++i)
        {
            cin >> from >> to >> dist;
            board[from][to] = dist;
            board[to][from] = dist;
        }
        cin >> K;
        for (int i = 0; i < K; ++i)
            cin >> friends[i];
        Floyd();
        pair<int, int> answer = make_pair(-1, 987654321);
        for (int i = 1; i <= N; ++i)
        {
            int cur = 0;
            for (int j = 0; j < K; ++j)
                cur += board[friends[j]][i];
            if (answer.second > cur)
                answer = make_pair(i, cur);
        }
        cout << answer.first << '\n';
    }
    return 0;
}