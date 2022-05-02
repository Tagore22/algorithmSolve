#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
vector<int> sum;
vector<vector<int>> cashe;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int k;
        cin >> k;
        board.assign(k + 1, 0);
        sum.assign(k + 1, 0);
        cashe.assign(k + 1, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; ++j)
        {
            cin >> board[j];
            sum[j] = sum[j - 1] + board[j];
        }
        for (int a = 1; a <= k; ++a)
            for (int b = 1; b <= k - a; ++b)
            {
                cashe[b][b + a] = 1000000000;
                for (int c = b; c < b + a; ++c)
                    cashe[b][b + a] = min(cashe[b][b + a], cashe[b][c] + cashe[c + 1][b + a] + sum[b + a] - sum[b - 1]);
            }
        cout << cashe[1][k] << '\n';
    }
    return 0;
}