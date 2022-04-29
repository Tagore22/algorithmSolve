#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> def;
const int Bnum = 2;
const int divv = 1000000007;
long long n;

vector<vector<int>> multiCal(const vector<vector<int>>& board1, const vector<vector<int>>& board2)
{
    vector<vector<int>> ans(Bnum, vector<int>(Bnum, 0));
    for (int k = 0; k < Bnum; ++k)
        for (int i = 0; i < Bnum; ++i)
            for (int j = 0; j < Bnum; ++j)
            {
                ans[k][i] += (static_cast<long long>(board1[k][j]) * board2[j][i]) % divv;
                ans[k][i] %= divv;
            }
    return ans;
}

vector<vector<int>> FindAns(long long num)
{
    if (num == 0LL)
        return def;
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

    cin >> n;
    board.assign(Bnum, vector<int>(Bnum, 1));
    board[Bnum - 1][Bnum - 1] = 0;
    def.assign(Bnum, vector<int>(Bnum, 0));
    for (int i = 0; i < Bnum; ++i)
        for (int j = 0; j < Bnum; ++j)
            if (i == j)
                def[i][j] = 1;
    vector<vector<int>> answer = FindAns(n);
    cout << answer[0][1] << '\n';
    return 0;
}