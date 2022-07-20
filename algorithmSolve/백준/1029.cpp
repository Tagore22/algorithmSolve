#include <iostream>
#include <cstring>

using namespace std;

int cashe[15][10][(1 << 15) - 1];
int board[15][15];
int N;

int DP(int now, int money, int mask)
{
    int& ans = cashe[now][money][mask];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = 0; i < N; ++i)
        if ((mask & (1 << i)) == 0 && board[now][i] >= money)
            ans = max(ans, DP(i, board[now][i], mask | (1 << i)) + 1);
    return ans;
}

void MakeAnswer()
{
    cout << DP(0, 0, 1) + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}