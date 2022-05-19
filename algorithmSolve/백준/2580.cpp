#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> zero;
bool FindAnswer = false;

bool check(int y, int x, int num)
{
    for (int i = 0; i < 9; ++i)
        if ((y != i && board[i][x] == num) || (x != i && board[y][i] == num))
            return false;
    int whereisY = y / 3;
    int whereisX = x / 3;
    for (int i = whereisY * 3; i < whereisY * 3 + 3; ++i)
        for (int j = whereisX * 3; j < whereisX * 3 + 3; ++j)
            if (!(y == i && x == j) && (board[i][j] == num))
                return false;
    return true;
}

void calcul(int idx)
{
    if (idx == zero.size())
    {
        FindAnswer = true;
        return;
    }
    int y = zero[idx].first;
    int x = zero[idx].second;
    for (int i = 1; i <= 9; ++i)
        if (check(y, x, i))
        {
            board[y][x] = i;
            calcul(idx + 1);
            if (FindAnswer)
                return;
        }
    board[y][x] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                zero.push_back(make_pair(i, j));
        }
    calcul(0);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}