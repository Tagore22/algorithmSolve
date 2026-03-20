#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, P, Q;
vector<int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 1; iter <= T; ++iter)
    {
        cin >> N >> P >> Q;
        board.clear();
        for (int i = 0; i < N; ++i)
        {
            int num;
            cin >> num;
            board.push_back(num);
        }
        sort(board.begin(), board.end());
        int sum = 0, ans, to = min(P, N);
        for (ans = 0; ans < to; ++ans)
        {
            if (sum + board[ans] > Q)
                break;
            sum += board[ans];
        }
        cout << "Case " << iter << ": " << ans << '\n';
    }
    return 0;
}