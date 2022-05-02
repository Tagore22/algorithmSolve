#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> board;
vector<vector<pair<int, int>>> point;
vector<vector<int>> sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    point.assign(n, vector<pair<int, int>>(n, make_pair(0, 0)));
    sum.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        board.push_back(make_pair(a, b));
    }
    for (int i = 0; i < n; ++i)
        point[i][i] = board[i];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            sum[j][i + j] = 2000000000;
            for (int k = j; k < i + j; ++k)
            {
                sum[j][i + j] = min(sum[j][i + j], sum[j][k] + sum[k + 1][i + j] + (point[j][k].first * point[j][k].second * point[k + 1][i + j].second));
                point[j][i + j].first = point[j][k].first;
                point[j][i + j].second = point[k + 1][i + j].second;
            }
        }
    }
    cout << sum[0][n - 1] << '\n';
    return 0;
}