#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; //양방향 그래프, 정점의 시작번호는 1번부터 N번까지, i로부터 i의 연결도 있음.

vector<vector<pair<int, int>>> board;
int N, M;
const int MAXNUM = 987654321;

void Prim()
{
    int answer = 0;
    vector<int> money(N, MAXNUM);
    vector<bool> check(N, false);
    money[0] = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        int u = -1;
        for (int v = 0; v < N; ++v)
            if (!check[v] && (u == -1 || money[u] > money[v]))
                u = v;
        check[u] = true;
        answer += money[u];

        for (int v = 0; v < board[u].size(); ++v)
        {
            int there = board[u][v].first;
            int cost = board[u][v].second;
            money[there] = min(money[there], cost);
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.assign(N, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b)
            continue;
        board[a - 1].push_back(make_pair(b - 1, c));
        board[b - 1].push_back(make_pair(a - 1, c));
    }
}

int main()
{
    Input();
    Prim();
    return 0;
}