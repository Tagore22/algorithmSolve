#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<vector<int>> board;
vector<bool> check;
int point = 1;

void dfs(int here)
{
    check[here] = true;
    answer[here] = point;
    ++point;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (!check[there])
            dfs(there);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    board.assign(n, vector<int>());
    check.assign(n, false);
    answer.assign(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1].push_back(b - 1);
        board[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; ++i)
        sort(board[i].begin(), board[i].end(), greater<>());
    dfs(r - 1);
    for (int i = 0; i < n; ++i)
        cout << answer[i] << '\n';
    return 0;
}