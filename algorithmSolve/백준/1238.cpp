#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; //단방향 그래프, 주어지는 정점의 번호는 1번부터 n번까지, 각 간선을 갱신할필요는 없다.

vector<vector<int>> board;
int N, M, X;
const int MAXNUM = 987654321;

void Floyd()
{
    for (int i = 0; i < N; ++i)
        board[i][i] = 0;
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void ShowAnswer()
{
    Floyd();
    int answer = -1;
    for (int i = 0; i < N; ++i)
        answer = max(answer, board[i][X - 1] + board[X - 1][i]);
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    board.assign(N, vector<int>(N, MAXNUM));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1][b - 1] = c;
    }
    ShowAnswer();
    return 0;
}