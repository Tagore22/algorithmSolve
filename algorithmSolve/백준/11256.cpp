#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int iter = 0; iter < T; ++iter)
    {
        int J, N;
        cin >> J >> N;
        int board[1000];
        for (int i = 0; i < N; ++i)
        {
            int R, C;
            cin >> R >> C;
            board[i] = R * C;
        }
        sort(board, board + N, greater<>());
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            sum += board[i];
            if (sum >= J)
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}