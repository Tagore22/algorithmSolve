#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<int> check;
int answer = 0;
int CaseNum = 0;
bool isPlus = true;

bool dfs(int here, int prev)
{
    check[here] = true;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (there == prev)
            continue;
        if (check[there])
            return false;
        if (!dfs(there, here))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        board.assign(n, vector<int>());
        check.assign(n, false);
        answer = 0;
        ++CaseNum;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            board[a - 1].push_back(b - 1);
            board[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < n; ++i)
            if (!check[i])
            {
                if (dfs(i, i))
                    ++answer;
            }
        if (answer == 0)
            cout << "Case " << CaseNum << ": " << "No trees." << '\n';
        else if (answer == 1)
            cout << "Case " << CaseNum << ": " << "There is one tree." << '\n';
        else
            cout << "Case " << CaseNum << ": " << "A forest of " << answer << " " << "trees." << '\n';
    }
    return 0;
}