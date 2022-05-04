#include <iostream>
#include <vector>

using namespace std;

const int maxNum = 15000;
int n;
vector<int> board;
vector<vector<bool>> cashe;

void calcul(int num, int idx)
{
    if (idx > n || cashe[num][idx])
        return;
    cashe[num][idx] = true;
    calcul(num, idx + 1);
    calcul(num + board[idx], idx + 1);
    calcul(abs(num - board[idx]), idx + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n + 1, 0);
    cashe.assign(maxNum + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    calcul(0, 0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;
        if (x > maxNum)
            cout << 'N' << '\n';
        else if (cashe[x][n])
            cout << 'Y' << '\n';
        else
            cout << 'N' << '\n';
    }
    return 0;
}