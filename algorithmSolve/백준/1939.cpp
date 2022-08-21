#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> board; //정점은 1번부터 n번까지, 양방향 그래프
int N, M, from, to, maxW;

bool BFS(int weight)
{
    queue<int> que;
    que.push(from);
    vector<bool> check(N + 1, false);
    check[from] = true;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        if (here == to)
            return true;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int cost = board[here][i].second;

            if (!check[there] && cost >= weight)
            {
                que.push(there);
                check[there] = true;
            }
        }
    }
    return false;
}

void MakeAnswer()
{
    int lo = -1;
    int hi = maxW + 1;
    for (int i = 0; i < 100; ++i)
    {
        int mid = (lo + hi) / 2;
        if (BFS(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    maxW = 0;

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
        maxW = max(maxW, c);
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}