#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;
vector<int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> T;
    for (int i = 1; i * i <= T; ++i)
    {
        int div = T / i;
        if (div * i == T)
        {
            board.push_back(i);
            board.push_back(div);
        }
    }
    sort(board.begin(), board.end());
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        int idx = upper_bound(board.begin(), board.end(), num) - board.begin();
        if (idx == board.size())
            answer += num - board[idx - 1];
        else
            answer += min(board[idx] - num, num - board[idx - 1]);
    }
    cout << answer << '\n';
    return 0;
}