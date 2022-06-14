#include <iostream>
#include <vector>
#include <queue>

using namespace std;//������ ��ȣ�� 1������ n����, ����� �׷���, ��� ������ ����Ǿ�����

vector<vector<int>> board;
int n, m;

void BFS()
{
    int answer = 0;
    vector<bool> check(n + 1, false);
    check[1] = true;
    queue<int> que;
    que.push(1);
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            if (!check[there])
            {
                check[there] = true;
                que.push(there);
                ++answer;
            }
        }
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        board.assign(n + 1, vector<int>());
        for (int j = 0; j < m; ++j)
        {
            int a, b;
            cin >> a >> b;
            board[a].push_back(b);
            board[b].push_back(a);
        }
        BFS();
    }
    return 0;
}