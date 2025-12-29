#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> board;
    int first = 0, second = 1;
    while (first + second < 25000)
    {
        first += second;
        board.push_back(first);
        swap(first, second);
    }
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<int> cur;
        int idx = upper_bound(board.begin(), board.end(), n) - board.begin();
        --idx;
        for (int i = idx; i >= 0; --i)
        {
            if (n >= board[i])
            {
                cur.push_back(1);
                n -= board[i];
            }
            else
            {
                cur.push_back(0);
            }
        }
        long long answer = 0;
        for (int i = 0; i < cur.size() - 1; ++i)
            answer += board[idx - 1 - i] * cur[i];
        cout << answer << '\n';
    }
    return 0;
}