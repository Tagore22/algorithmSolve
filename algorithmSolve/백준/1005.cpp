#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> TimeNum;
vector<vector<int>> board;
vector<int> link;
vector<int> answer;
int n;

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
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            answer[there] = max(answer[there], answer[here] + TimeNum[there]);
            --link[there];

            if (link[there] == 0)
                que.push(there);
        }
    }
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
        int k, w;
        cin >> n >> k;
        TimeNum.assign(n, 0);
        board.assign(n, vector<int>());
        link.assign(n, 0);
        answer.assign(n, 0);
        for (int j = 0; j < n; ++j)
        {
            cin >> TimeNum[j];
            answer[j] = TimeNum[j];
        }
        for (int j = 0; j < k; ++j)
        {
            int a, b;
            cin >> a >> b;
            board[a - 1].push_back(b - 1);
            ++link[b - 1];
        }
        cin >> w;
        Calcul();
        cout << answer[w - 1] << '\n';
    }
    return 0;
}