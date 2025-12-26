#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    char board[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != '.')
                board[i][M - 1 - j] = board[i][j];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}