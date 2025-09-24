#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[4];

int MaxMoney()
{
    int ans = -1;
    sort(board, board + 4);
    if (board[0] == board[3])
    {
        ans = max(ans, 50000 + board[0] * 5000);
    }
    else if (board[0] == board[2] || board[1] == board[3])
    {
        ans = max(ans, 10000 + board[1] * 1000);
    }
    else if (board[0] == board[1] && board[2] == board[3])
    {
        ans = max(ans, 2000 + board[0] * 500 + board[2] * 500);
    }
    else if (board[0] == board[1] || board[1] == board[2] || board[2] == board[3])
    {
        int here = -1;
        for (int i = 0; i < 3; ++i)
        {
            if (board[i] == board[i + 1])
            {
                here = i;
                break;
            }
        }
        ans = max(ans, 1000 + board[here] * 100);
    }
    else
    {
        ans = max(ans, board[3] * 100);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int answer = -1;
    for (int iter = 0; iter < N; ++iter)
    {
        for (int i = 0; i < 4; ++i)
            cin >> board[i];

        answer = max(answer, MaxMoney());
    }
    cout << answer << '\n';
    return 0;
}