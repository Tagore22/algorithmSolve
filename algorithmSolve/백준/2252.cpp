#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<bool> check;
vector<int> answer;
int n, m;

void DFS(int here)
{
    check[here] = true;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (!check[there])
            DFS(there);
    }
    answer.push_back(here + 1);
}

void ShowAnswer()
{
    check.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!check[i])
            DFS(i);
    reverse(answer.begin(), answer.end());
    for (int i = 0; i < n; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

int main() //방향 그래프, 정점의 번호는 1번부터 n-1
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>());
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1].push_back(b - 1);
    }
    ShowAnswer();
    return 0;
}