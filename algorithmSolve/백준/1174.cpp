#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    --N;

    vector<long long> board;
    for (int i = 0; i < 10; ++i)
        board.push_back(i);
    int from = 0, idx = 10;
    while (idx < 1022)
    {
        for (int i = from; i < board.size(); ++i)
        {
            int prev = board[i] % 10;
            for (int j = 0; j < prev; ++j)
            {
                board.push_back(board[i] * 10 + j);
                ++idx;
            }
        }
        from = board.size();
    }

    if (N >= board.size())
        cout << -1 << '\n';
    else
        cout << board[N] << '\n';
    return 0;
}