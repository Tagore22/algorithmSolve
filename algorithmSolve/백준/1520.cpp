#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> cashe;
int m, n;
int nextP[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };


int findcal(int y, int x)
{
    if (y == m - 1 && x == n - 1)
        return 1;
    int& ans = cashe[y][x];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        int dy = y + nextP[i][0];
        int dx = x + nextP[i][1];
        if (dy >= 0 && dy < m && dx >= 0 && dx < n && board[y][x] > board[dy][dx])
            ans += findcal(dy, dx);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    board.assign(m, vector<int>(n, 0));
    cashe.assign(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    cout << findcal(0, 0) << '\n';
    return 0;
}