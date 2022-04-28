#include <iostream>
#include <vector>

using namespace std;

int minusAnswer = 0;
int zeroAnswer = 0;
int plusAnswer = 0;
vector<vector<int>> board;

void calcul(int yStart, int yEnd, int xStart, int xEnd)
{
    if (yStart == yEnd)
    {
        if (board[yStart][xStart] == 0)
            ++zeroAnswer;
        else if (board[yStart][xStart] == 1)
            ++plusAnswer;
        else
            ++minusAnswer;
        return;
    }

    bool check = true;
    for (int i = yStart; i <= yEnd; ++i)
    {
        for (int j = xStart; j <= xEnd; ++j)
            if (board[i][j] != board[yStart][xStart])
            {
                check = false;
                break;
            }
        if (!check)
            break;
    }
    if (check)
    {
        if (board[yStart][xStart] == 0)
            ++zeroAnswer;
        else if (board[yStart][xStart] == 1)
            ++plusAnswer;
        else
            ++minusAnswer;
        return;
    }
    int yLo = ((2 * yStart) + yEnd) / 3;
    int yHi = (yStart + (2 * yEnd)) / 3;
    int xLo = ((2 * xStart) + xEnd) / 3;
    int xHi = (xStart + (2 * xEnd)) / 3;
    calcul(yStart, yLo, xStart, xLo);
    calcul(yStart, yLo, xLo + 1, xHi);
    calcul(yStart, yLo, xHi + 1, xEnd);
    calcul(yLo + 1, yHi, xStart, xLo);
    calcul(yLo + 1, yHi, xLo + 1, xHi);
    calcul(yLo + 1, yHi, xHi + 1, xEnd);
    calcul(yHi + 1, yEnd, xStart, xLo);
    calcul(yHi + 1, yEnd, xLo + 1, xHi);
    calcul(yHi + 1, yEnd, xHi + 1, xEnd);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    calcul(0, n - 1, 0, n - 1);
    cout << minusAnswer << '\n' << zeroAnswer << '\n' << plusAnswer << '\n';
    return 0;
}