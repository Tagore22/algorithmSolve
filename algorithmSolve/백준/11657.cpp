#include <iostream>
#include <vector> 
using namespace std; //시작점은 1번부터 n번까지. 방향 그래프. 1번에서 시작하는 도중 음수 사이클이 있으면 -1.

vector<vector<pair<int, int>>> board;
int n, m;
const int MAXNUM = 987654321;

void BF()
{
    vector<long long> answer(n, MAXNUM);
    answer[0] = 0;
    for (int iter = 0; iter < n - 1; ++iter)
        for (int here = 0; here < n; ++here)
            for (int i = 0; i < board[here].size(); ++i)
            {
                int there = board[here][i].first;
                int cost = board[here][i].second;

                if (answer[here] != MAXNUM)
                    answer[there] = min(answer[there], answer[here] + cost);
            }
    for (int here = 0; here < n; ++here)
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int cost = board[here][i].second;

            if (answer[here] != MAXNUM && answer[there] > answer[here] + cost)//음수 사이클 존재
            {
                cout << -1 << '\n';
                return;
            }
        }
    for (int i = 1; i < n; ++i)
        cout << (answer[i] != MAXNUM ? answer[i] : -1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1].push_back(make_pair(b - 1, c));
    }
    BF();
    return 0;
}