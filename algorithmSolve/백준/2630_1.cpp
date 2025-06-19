#include <iostream>

using namespace std;

// 버그였는지 내가 잘못본건지 푼 문제를 또 풀었다. 다만 3년전에 풀었을 때보다
// 더 깔끔하게 풀어서 다행이다.

int N;
const int MAX = 128;
int board[MAX][MAX], answer[2] = { 0, 0 };

bool IsSameBoard(int fromY, int fromX, int len)
{
    int cur = board[fromY][fromX];
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            if (board[fromY + i][fromX + j] != cur)
                return false;
    return true;
}

void DivideQuater(int fromY, int fromX, int len)
{
    if (IsSameBoard(fromY, fromX, len))
    {
        ++answer[board[fromY][fromX]];
        return;
    }

    int nextlen = len / 2;
    DivideQuater(fromY, fromX, nextlen);
    DivideQuater(fromY, fromX + nextlen, nextlen);
    DivideQuater(fromY + nextlen, fromX, nextlen);
    DivideQuater(fromY + nextlen, fromX + nextlen, nextlen);
}

void Solve()
{
    DivideQuater(0, 0, N);
    for (int i = 0; i < 2; ++i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}