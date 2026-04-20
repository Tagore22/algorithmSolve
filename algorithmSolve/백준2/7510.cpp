#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long board[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int iter = 1; iter <= n; ++iter)
    {
        for (int i = 0; i < 3; ++i)
            cin >> board[i];
        sort(board, board + 3);
        long long first = board[2] * board[2];
        long long second = board[0] * board[0] + board[1] * board[1];
        cout << "Scenario #" << iter << ':' << '\n';
        cout << (first == second ? "yes" : "no") << '\n' << '\n';
    }
    return 0;
}