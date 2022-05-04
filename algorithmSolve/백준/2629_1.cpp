#include <iostream>
#include <vector>

using namespace std;

const int maxNum = 15000;
int n;
vector<int> board;
vector<vector<int>> cashe;

int calcul(int num, int idx)
{
    if (idx == n)
        return num == 0 ? 1 : 0;
    int& ans = cashe[num][idx];
    if (ans != -1)
        return ans;
    ans = 0;
    ans |= calcul(num, idx + 1);
    if (num + board[idx] <= maxNum)
        ans |= calcul(num + board[idx], idx + 1);
    ans |= calcul(abs(num - board[idx]), idx + 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, 0);
    cashe.assign(maxNum + 1, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;
        if (x > maxNum)
            cout << 'N' << '\n';
        else
        {
            char answer = calcul(x, 0) == 1 ? 'Y' : 'N';
            cout << answer << '\n';
        }
    }
    return 0;
}