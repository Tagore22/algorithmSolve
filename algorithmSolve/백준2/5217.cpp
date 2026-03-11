#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        board.clear();
        for (int j = 1; j <= num / 2; ++j)
            if (num - j != j)
                board.push_back(make_pair(j, num - j));

        cout << "Pairs for " << num << ": ";
        for (int i = 0; i < board.size(); ++i)
        {
            if (i != 0)
                cout << ", ";
            cout << board[i].first << ' ' << board[i].second;
        }
        cout << '\n';
    }
    return 0;
}