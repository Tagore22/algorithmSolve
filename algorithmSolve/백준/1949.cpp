#include <iostream>
#include <vector>

using namespace std; //양방향, 사이클없는 트리 또한 최대값을 구해야한다.(리프부터 1씩 증가)

vector<vector<int>> board;
vector<int> w;
vector<bool> check;
vector<vector<int>> cashe;
int n;

void DFS(int here)
{
    check[here] = true;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (check[there])
            continue;
        DFS(there);
        cashe[here][1] += cashe[there][0];
        cashe[here][0] += max(cashe[there][0], cashe[there][1]);
    }
    cashe[here][1] += w[here];
}

void ShowAnswer()
{
    cashe.assign(n + 1, vector<int>(2, 0));
    check.assign(n + 1, false);
    DFS(1);
    cout << (cashe[1][0] > cashe[1][1] ? cashe[1][0] : cashe[1][1]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    w.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    board.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    ShowAnswer();
    return 0;
}