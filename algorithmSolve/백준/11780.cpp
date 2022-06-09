#include <iostream>
#include <vector>

using namespace std;//정점의 번호는 1번부터 n번까지. 방향 그래프

vector<vector<int>> board;
vector<vector<int>> mid;
int n, m;
const int MAXNUM = 987654321;

void Floyd()
{
    mid.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
        board[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] > board[i][k] + board[k][j])
                {
                    mid[i][j] = k;
                    board[i][j] = board[i][k] + board[k][j];
                }
}

void MakePath(int from, int to, vector<int>& path)
{
    if (mid[from][to] == -1)
    {
        path.push_back(from + 1);
        path.push_back(to + 1);
    }
    else
    {
        MakePath(from, mid[from][to], path);
        path.pop_back();
        MakePath(mid[from][to], to, path);
    }
}

void ShowAnswer()
{
    Floyd();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << (board[i][j] == MAXNUM ? 0 : board[i][j]) << ' ';
        cout << '\n';
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (i == j || board[i][j] == MAXNUM)
                cout << 0;
            else
            {
                vector<int> path;
                MakePath(i, j, path);
                cout << path.size() << ' ';
                for (int idx = 0; idx < path.size(); ++idx)
                    cout << path[idx] << ' ';
            }
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