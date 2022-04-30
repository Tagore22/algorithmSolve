#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, check;
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
        cout << upper_bound(board.begin(), board.end(), check) - lower_bound(board.begin(), board.end(), check) << ' ';
    }
    return 0;
}