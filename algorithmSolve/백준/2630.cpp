#include <iostream>
#include <vector>

using namespace std;

int blueAnswer = 0;
int whiteAnswer = 0;
vector<vector<int>> board;

void calcul(int yStart, int yEnd, int xStart, int xEnd)
{
    if (yStart == yEnd)
    {
        if (board[yStart][xStart] == 1)
            ++blueAnswer;
        else
            ++whiteAnswer;
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
        if (board[yStart][xStart] == 1)
            ++blueAnswer;
        else
            ++whiteAnswer;
        return;
    }
    int yMid = (yStart + yEnd) / 2;
    int xMid = (xStart + xEnd) / 2;
    calcul(yStart, yMid, xStart, xMid);
    calcul(yStart, yMid, xMid + 1, xEnd);
    calcul(yMid + 1, yEnd, xStart, xMid);
    calcul(yMid + 1, yEnd, xMid + 1, xEnd);
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
    cout << whiteAnswer << '\n' << blueAnswer << '\n';
    return 0;
}