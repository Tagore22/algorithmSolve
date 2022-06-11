#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board;
int v, e;
const int MAXNUM = 987654321;

void Floyd()
{
    for (int i = 0; i < v; ++i)
        board[i][i] = 0;
    for (int k = 0; k < v; ++k)
        for (int i = 0; i < v; ++i)
            for (int j = 0; j < v; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void ShowAnswer()
{
    Floyd();
    int answer = MAXNUM;
    for (int i = 0; i < v; ++i)
        for (int j = 0; j < v; ++j)
            if (i != j)
                answer = min(answer, board[i][j] + board[j][i]);
    cout << (answer != MAXNUM ? answer : -1) << '\n';
}

int main() //방향 그래프, 정점의 번호는 1번부터 v번까지
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    board.assign(v, vector<int>(v, MAXNUM));
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1][b - 1] = c;
    }
    ShowAnswer();
    return 0;
}