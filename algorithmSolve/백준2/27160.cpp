#include <iostream>
#include <unordered_map>

using namespace std;

int N;
unordered_map<string, int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        int num;
        cin >> str >> num;
        board[str] += num;
    }
    for (auto iter = board.begin(); iter != board.end(); ++iter)
    {
        if (iter->second == 5)
        {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}