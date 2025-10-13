#include <iostream>

using namespace std;

// 풀이.
// 두쌍의 최단거리를 한꺼번에 여러번 비교해야하므로 플로이드 워셜 알고리즘을 사용해야했다.
// 그것만 알면 딱히 어려울 것없이 대입만 하면 된다.

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