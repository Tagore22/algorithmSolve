#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board, cashe;
int N;
const int MAXNUM = 987654321;

int MakeAnswer(int ManNum, int mask) // mask´Â 0ºÎÅÍ
{
    if (mask == (1 << N) - 1)
        return 0;
    int& ans = cashe[ManNum][mask];
    if (ans != MAXNUM)
        return ans;
    for (int i = 0; i < N; ++i)
        if ((mask & 1 << i) == 0)
            ans = min(ans, MakeAnswer(ManNum + 1, mask | 1 << i) + board[ManNum][i]);
    return ans;
}

void Input()
{
    cin >> N;
    board.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    cashe.assign(N, vector<int>((1 << N), MAXNUM));
}

int main()
{
    Input();
    cout << MakeAnswer(0, 0) << '\n';
    return 0;
}