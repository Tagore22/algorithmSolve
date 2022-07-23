#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int N, K, S;

void Floyd()
{
    for (int c = 1; c <= N; ++c)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (board[i][j] != 0)
                    continue;
                if (board[i][c] == -1 && board[c][j] == -1)
                    board[i][j] = -1;
                else if (board[i][c] == 1 && board[c][j] == 1)
                    board[i][j] = 1;
            }
}

void MakeAnswer()
{
    Floyd();
    cin >> S;
    for (int i = 0; i < S; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << board[a][b] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    board.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = -1;
        board[b][a] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}