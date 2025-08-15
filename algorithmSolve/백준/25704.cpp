#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;

    if (N < 5)
    {
        cout << P << '\n';
        return 0;
    }

    int board[4];
    board[0] = 500, board[1] = P / 10, board[2] = 2000, board[3] = P / 4;
    int to = min(N / 5, 4);
    sort(board, board + to);
    int answer = max(P - board[to - 1], 0);
    cout << answer << '\n';
    return 0;
}