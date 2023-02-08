#include <iostream>
#include <cstring>

using namespace std;

// BFS가 아닌 플로이드 와셜 알고리즘의 풀이. 최단거리가 아닌 문제이기에 오히려 느렸다.

int board[1001][1001];
int N, M;

void Floyd()
{
    for (int i = 1; i <= N; ++i)
        board[i][i] = 0;

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (board[i][j] == -1 && board[i][k] != -1 && board[k][j] != -1)
                    board[i][j] = board[i][k] + board[k][j];
}

void MakeAnswer()
{
    Floyd();
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        cout << board[from][to] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, -1, sizeof(board));

    cin >> N >> M;
    for (int i = 0; i < N - 1; ++i)
    {
        int from, to, len;
        cin >> from >> to >> len;
        board[from][to] = len;
        board[to][from] = len;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}