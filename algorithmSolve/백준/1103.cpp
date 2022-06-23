#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board, cashe;
vector<vector<bool>> check;
int n, m;
int CY[4] = { -1,0,1,0 };
int CX[4] = { 0,-1,0,1 };

int FindAnswer(int y, int x)
{
    int& ans = cashe[y][x];

    if (ans != -1)
        return ans;
    ans = 0;
    int move = board[y][x];
    check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int DY = CY[i] * move + y;
        int DX = CX[i] * move + x;
        if (DY < 0 || DY >= n || DX < 0 || DX >= m || board[DY][DX] == 0)
            continue;
        if (check[DY][DX])
            return -1;

        if (FindAnswer(DY, DX) == -1)
            return -1;
        else
            ans = max(ans, FindAnswer(DY, DX) + 1);
    }
    check[y][x] = false;
    return ans;
}

void ShowAnswer()
{
    cashe.assign(n, vector<int>(m, -1));
    check.assign(n, vector<bool>(m, false));
    int answer = FindAnswer(0, 0);
    answer = answer != -1 ? answer + 1 : answer;
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; ++j)
            if (str[j] != 'H')
                board[i][j] = str[j] - '0';
    }
    ShowAnswer();
    return 0;
}