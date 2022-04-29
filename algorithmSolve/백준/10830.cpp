#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
const int divv = 1000;
int n;
long long b;

vector<vector<int>> multiCal(const vector<vector<int>>& board1, const vector<vector<int>>& board2)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                ans[k][i] += (board1[k][j] * board2[j][i]) % divv;
                ans[k][i] %= divv;
            }
    return ans;
}

vector<vector<int>> FindAns(long long num)
{
    if (num == 1LL)
        return board;
    if (num % 2 == 1LL)
        return multiCal(board, FindAns(num - 1));
    vector<vector<int>> mul = FindAns(num / 2);
    return multiCal(mul, mul);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    vector<vector<int>> answer = FindAns(b);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << answer[i][j] << " ";
        cout << '\n';
    }
    return 0;
}