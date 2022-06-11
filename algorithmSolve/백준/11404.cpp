#include <iostream>
#include <vector>

using namespace std; // 방향 그래프, 어떤 두 정점 사이에 길이 하나가 아닐수도 있다. 정점의 번호는 1번부터 n까지

vector<vector<int>> board;// 어떤 정점으로 도달하는 길이 없을 경우 0을 출력한다. 또한, 음수 가중치는 주어지지 않는다.
int n, m;
const int MAXNUM = 987654321;

void Floyd()
{
    for (int i = 0; i < n; ++i)
        board[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void ShowAnswer()
{
    Floyd();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << (board[i][j] != MAXNUM ? board[i][j] : 0) << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>(n, MAXNUM));
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1][b - 1] = min(board[a - 1][b - 1], c);
    }
    ShowAnswer();
    return 0;
}