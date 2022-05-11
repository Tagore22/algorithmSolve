#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<vector<int>> board;
vector<int> answer;


void dfs(int here)
{
    if (answer[here] == -1)
        answer[here] = 1;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (answer[there] == -1)
        {
            answer[there] = (answer[here] + 1) % 2;
            dfs(there);
        }
    }
}

bool isBipar()
{
    for (int i = 0; i < v; ++i)
        for (int j = 0; j < board[i].size(); ++j)
            if (answer[i] == answer[board[i][j]])
                return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> v >> e;
        board.assign(v, vector<int>());
        answer.assign(v, -1);
        for (int j = 0; j < e; ++j)
        {
            int a, b;
            cin >> a >> b;
            board[a - 1].push_back(b - 1);
            board[b - 1].push_back(a - 1);
        }
        for (int j = 0; j < v; ++j)
            if (answer[j] == -1)
                dfs(j);
        if (isBipar())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}