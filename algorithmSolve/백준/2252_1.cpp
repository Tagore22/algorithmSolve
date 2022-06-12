#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<int> link, answer;
int n, m;

void Calcul()
{
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (link[i] == 0)
            que.push(i);
    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        answer.push_back(here + 1);
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            --link[there];
            if (link[there] == 0)
                que.push(there);
        }
    }
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

int main() //방향 그래프, 정점의 번호는 1번부터 n번까지
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>());
    link.assign(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1].push_back(b - 1);
        ++link[b - 1];
    }
    Calcul();
    return 0;
}