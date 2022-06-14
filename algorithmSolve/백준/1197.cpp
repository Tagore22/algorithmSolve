#include <iostream>
#include <vector>

using namespace std; // 정점의 번호는 1번부터 n번까지. 양방향 그래프이며 답은 int

vector<vector<pair<int, int>>> board;
int V, E;
const int MINNUM = 987654321;

void Prim()
{
    int answer = 0;
    vector<bool> Use(V, false);
    vector<int> Minlen(V, MINNUM);
    Minlen[0] = 0;
    for (int i = 0; i < V; ++i)
    {
        int u = -1;
        for (int v = 0; v < V; ++v)
            if (!Use[v] && (u == -1 || Minlen[u] > Minlen[v]))
                u = v;

        answer += Minlen[u];
        Use[u] = true;

        for (int j = 0; j < board[u].size(); ++j)
        {
            int v = board[u][j].first;
            int cost = board[u][j].second;
            if (!Use[v] && Minlen[v] > cost)
                Minlen[v] = cost;
        }
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    board.assign(V, vector<pair<int, int>>());
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a - 1].push_back(make_pair(b - 1, c));
        board[b - 1].push_back(make_pair(a - 1, c));
    }
    Prim();
    return 0;
}