#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
int check;

void calcul(int lo, int hi)
{
    for (int i = 0; i < 100; ++i)
    {
        int mid = (lo + hi) / 2;
        if (board[mid] > check)
            hi = mid;
        else if (board[mid] < check)
            lo = mid;
        else
        {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    board.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    sort(board.begin(), board.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> check;
        calcul(-1, n);
    }
    return 0;
}