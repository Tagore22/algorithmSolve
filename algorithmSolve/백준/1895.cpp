#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 40;
int board[MAX][MAX];
int R, C, T;
vector<int> mids;

void FindMid(int y, int x)
{
    vector<int> cur;
    for (int i = y; i < y + 3; ++i)
        for (int j = x; j < x + 3; ++j)
            cur.push_back(board[i][j]);
    sort(cur.begin(), cur.end());
    mids.push_back(cur[4]);
}

void Solve()
{
    for (int i = 0; i <= R - 3; ++i)
        for (int j = 0; j <= C - 3; ++j)
            FindMid(i, j);

    int answer = 0;
    for (auto& n : mids)
        if (n >= T)
            ++answer;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];
    cin >> T;
}

int main()
{
    Input();
    Solve();
    return 0;
}