#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<int> cashe;
int n, r, q;

int DFS(int here)
{
    cashe[here] = 0;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (cashe[there] != -1)
            continue;
        DFS(there);
        cashe[here] += cashe[there];
    }
    cashe[here] += 1;
    return cashe[here];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> q;
    board.assign(n + 1, vector<int>());
    cashe.assign(n + 1, -1);
    cashe[r] = n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    DFS(r);
    for (int i = 0; i < q; ++i)
    {
        int a;
        cin >> a;
        cout << cashe[a] << '\n';
    }
    return 0;
}