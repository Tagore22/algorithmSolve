#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<long long> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int iter = 0; iter < n; ++iter)
    {
        string str;
        cin >> str;

        reverse(str.begin(), str.end());
        long long cur = stol(str);
        board.push_back(cur);
    }
    sort(board.begin(), board.end());
    for (const auto& here : board)
        cout << here << '\n';
    return 0;
}