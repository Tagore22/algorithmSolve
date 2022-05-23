#include <iostream>
#include <cstring>

using namespace std;

int n, MaxNum;
int board[30];
int cashe[15001][30];

int Calcul(int sum, int idx)
{
    if (idx == n)
        return sum == 0 ? 1 : 0;
    int& ans = cashe[sum][idx];
    if (ans != -1)
        return ans;
    ans = 0;
    ans |= Calcul(sum, idx + 1);
    ans |= Calcul(abs(sum - board[idx]), idx + 1);
    if (sum + board[idx] <= MaxNum)
        ans |= Calcul(sum + board[idx], idx + 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> n;
    MaxNum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        MaxNum += board[i];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;
        if (x > MaxNum)
            cout << 'N' << '\n';
        else
        {
            char answer = Calcul(x, 0) == 1 ? 'Y' : 'N';
            cout << answer << '\n';
        }
    }
    return 0;
}