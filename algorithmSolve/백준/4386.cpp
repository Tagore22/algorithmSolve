#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std; // 소수점 둘째자리까지 출력할것.

vector<vector<pair<int, double>>> board;
vector<pair<double, double>> num;
int n;

double CalculDist(int a, int b)
{
    double x1 = num[a].first;
    double y1 = num[a].second;
    double x2 = num[b].first;
    double y2 = num[b].second;

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void MakeGraph()
{
    board.assign(n, vector<pair<int, double>>());
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            double dist = CalculDist(i, j);
            board[i].push_back(make_pair(j, dist));
            board[j].push_back(make_pair(i, dist));
        }
}

void Prim()
{
    MakeGraph();
    double answer = 0;
    vector<bool> Use(n, false);
    vector<double> Minlen(n, numeric_limits<double>::max());
    Minlen[0] = 0.0;
    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        for (int v = 0; v < n; ++v)
            if (!Use[v] && (u == -1 || Minlen[u] > Minlen[v]))
                u = v;

        answer += Minlen[u];
        Use[u] = true;

        for (int j = 0; j < board[u].size(); ++j)
        {
            int v = board[u][j].first;
            double cost = board[u][j].second;
            if (!Use[v] && Minlen[v] > cost)
                Minlen[v] = cost;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    num.assign(n, make_pair(0.0, 0.0));
    for (int i = 0; i < n; ++i)
    {
        double a, b;
        cin >> a >> b;
        num[i] = make_pair(a, b);
    }
    Prim();
    return 0;
}