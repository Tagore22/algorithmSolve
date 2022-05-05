#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> board;
vector<int> c;
vector<vector<int>> cashe;

int calcul(int sum, int idx) {
    if (idx == n)
        return 0;

    int& ans = cashe[sum][idx];
    if (ans != -1)
        return ans;

    ans = calcul(sum, idx + 1);

    if (sum >= c[idx])
        ans = max(ans, calcul(sum - c[idx], idx + 1) + board[idx]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    board.assign(n, 0);
    c.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
        sum += c[i];
    }
    cashe.assign(sum + 1, vector<int>(n, -1));
    for (int i = 0; i <= sum; ++i)
        if (calcul(i, 0) >= m)
        {
            cout << i << '\n';
            break;
        }
    return 0;
}