#include <iostream>
#include <vector>

using namespace std;

vector<string> board;

string calcul(int yStart, int yEnd, int xStart, int xEnd)
{
    if (yStart == yEnd)
        return string(1, board[yStart][xStart]);

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
        return string(1, board[yStart][xStart]);

    int yMid = (yStart + yEnd) / 2;
    int xMid = (xStart + xEnd) / 2;
    string a = calcul(yStart, yMid, xStart, xMid);
    string b = calcul(yStart, yMid, xMid + 1, xEnd);
    string c = calcul(yMid + 1, yEnd, xStart, xMid);
    string d = calcul(yMid + 1, yEnd, xMid + 1, xEnd);
    return "(" + a + b + c + d + ")";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    board.assign(n, string(""));
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cout << calcul(0, n - 1, 0, n - 1) << '\n';
    return 0;
}