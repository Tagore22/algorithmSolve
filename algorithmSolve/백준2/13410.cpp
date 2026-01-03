#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, K;
vector<int> board;

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= K; ++i)
    {
        string cur = to_string(N * i);
        reverse(cur.begin(), cur.end());
        board.push_back(stoi(cur));
    }
    sort(board.begin(), board.end());
    cout << board[board.size() - 1] << '\n';
    return 0;
}