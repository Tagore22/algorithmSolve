#include <iostream>
#include <cstring>

using namespace std;

int cashe[51][51][51][51];
int arcade[51][51];
int N, M, C;
const int DIVNUM = 1000007;

int DP(int y, int x, int num, int prev)
{
    if (y > N || x > M || num < 0)
        return 0;
    if (y == N && x == M)
    {
        if ((num == 0 && arcade[y][x] == 0) || (num == 1 && arcade[y][x] > prev))
            return 1;
        else
            return 0;
    }
    int& ans = cashe[y][x][num][prev];
    if (ans != -1)
        return ans;
    ans = 0;

    if (arcade[y][x] == 0)
        ans = (DP(y + 1, x, num, prev) + DP(y, x + 1, num, prev)) % DIVNUM;
    else if (arcade[y][x] > prev)
        ans = (DP(y + 1, x, num - 1, arcade[y][x]) + DP(y, x + 1, num - 1, arcade[y][x])) % DIVNUM;
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i <= C; ++i)
        cout << DP(1, 1, i, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(cashe, -1, sizeof(cashe));
    cin >> N >> M >> C;
    for (int i = 1; i <= C; ++i)
    {
        int a, b;
        cin >> a >> b;
        arcade[a][b] = i;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}