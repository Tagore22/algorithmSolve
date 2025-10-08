#include <iostream>
#include <cmath>

using namespace std;

int board[1000][1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    pair<int, int> s, p;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                s = make_pair(i, j);
            else if (board[i][j] == 5)
                p = make_pair(i, j);
        }
    }
    int dis = sqrt(pow(s.first - p.first, 2) + pow(s.second - p.second, 2));
    if (dis < 5)
    {
        cout << 0 << '\n';
        return 0;
    }
    int student = 0;
    if (s.first == p.first)
    {
        int from = min(s.second, p.second);
        int to = max(s.second, p.second);
        for (int i = from; i <= to; ++i)
            if (board[s.first][i] == 1)
                ++student;
    }
    else if (s.second == p.second)
    {
        int from = min(s.first, p.first);
        int to = max(s.first, p.first);
        for (int i = from; i <= to; ++i)
            if (board[i][s.second] == 1)
                ++student;
    }
    else
    {
        int colfrom = s.first;
        int colto = p.first;
        if (colfrom > colto)
            swap(colfrom, colto);
        int rowfrom = s.second;
        int rowto = p.second;
        if (rowfrom > rowto)
            swap(rowfrom, rowto);
        for (int i = colfrom; i <= colto; ++i)
            for (int j = rowfrom; j <= rowto; ++j)
                if (board[i][j] == 1)
                    ++student;
    }
    cout << (student >= 3 ? 1 : 0) << '\n';
    return 0;
}