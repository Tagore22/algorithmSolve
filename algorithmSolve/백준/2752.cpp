#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> board;
    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num);
    }
    sort(board.begin(), board.end());
    for (auto i : board)
        cout << i << ' ';
    cout << '\n';
    return 0;
}