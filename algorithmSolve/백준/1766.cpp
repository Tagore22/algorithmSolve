#include <iostream> //정점의 번호는 1번부터 n번까지, 사이클은 없고 방향 그래프이다.
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<int> link;
int n, m;

void ShowAnswer()
{
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 1; i <= n; ++i)
        if (link[i] == 0)
            que.push(i);

    vector<int> answer;
    while (!que.empty())
    {
        int here = que.top();
        que.pop();
        answer.push_back(here);

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n + 1, vector<int>());
    link.assign(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        ++link[b];
    }
    ShowAnswer();
    return 0;
}