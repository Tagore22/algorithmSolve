#include <iostream>
#include <vector>

using namespace std; //현 그래프는 모든 정점이 연결되어있고, 사이클은 존재하지 않는 트리이며 양방향

const int NotE = 0;
const int YesE = 1;
vector<vector<int>> board;
vector<bool> check;
int n;
int answer = 0;

int DFS(int here)
{
    check[here] = true;
    int state[2] = { 0,0 };
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (check[there])
            continue;
        ++state[DFS(there)];
    }
    if (state[NotE])
    {
        ++answer;
        return YesE;
    }
    return NotE;
}

void DFSAll()
{
    check.assign(n + 1, false);
    for (int i = 1; i <= n; ++i)
        if (!check[i])
            DFS(i);
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    DFSAll();
    return 0;
}