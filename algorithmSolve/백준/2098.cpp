#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board, cashe;
int N, first;
const int MAXNUM = 17000000;

int MakeAnswer(int now, int mask)
{
    if (mask == (1 << N) - 1)
        return board[now][0] == 0 ? MAXNUM : board[now][0];
    int& ans = cashe[now][mask];
    if (ans != -1)
        return ans;
    ans = MAXNUM;
    for (int i = 0; i < N; ++i)
        if (board[now][i] != 0 && (mask & (1 << i)) == 0)
            ans = min(ans, MakeAnswer(i, mask | (1 << i)) + board[now][i]);
    return ans;
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    cashe.assign(N, vector<int>((1 << N), -1));
}

int main()
{
    Input();
    cout << MakeAnswer(0, 1) << '\n';
    return 0;
}