#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<bool> check;
vector<int> parent;

void dfs(int now)
{
    check[now] = true;
    for (int i = 0; i < board[now].size(); ++i)
    {
        int there = board[now][i];
        if (!check[there])
        {
            parent[there] = now;
            dfs(there);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    board.assign(n + 1, vector<int>());
    check.assign(n + 1, false);
    parent.assign(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; ++i)
        cout << parent[i] << '\n';
    return 0;
}