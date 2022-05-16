#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> board;
vector<bool> check;
int answer = 0;
int maxPoint;

void dfs(int now, int sum)
{
    check[now] = true;
    for (int i = 0; i < board[now].size(); ++i)
    {
        auto there = board[now][i];
        if (!check[there.first])
            dfs(there.first, sum + there.second);
    }
    if (sum > answer)
    {
        answer = sum;
        maxPoint = now;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    board.assign(n + 1, vector<pair<int, int>>());
    check.assign(n + 1, false);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a;
        while (true)
        {
            cin >> b;
            if (b == -1)
                break;
            cin >> c;
            board[a].push_back(make_pair(b, c));
            board[b].push_back(make_pair(a, c));
        }
    }
    dfs(1, 0);
    check.assign(n + 1, false);
    dfs(maxPoint, 0);
    cout << answer << '\n';
    return 0;
}