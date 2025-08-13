#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int ClockNum(int a, int b, int c, int d)
{
    return a * 1000 + b * 100 + c * 10 + d;
}

int CalClockNum(int a, int b, int c, int d)
{
    int n1 = ClockNum(a, b, c, d);
    int n2 = ClockNum(b, c, d, a);
    int n3 = ClockNum(c, d, a, b);
    int n4 = ClockNum(d, a, b, c);

    return min(min(n1, n2), min(n3, n4));
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cross = CalClockNum(a, b, c, d);

    set<int> board;
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            for (int k = 1; k <= 9; ++k)
                for (int z = 1; z <= 9; ++z)
                    board.insert(CalClockNum(i, j, k, z));

    int answer = distance(board.begin(), find(board.begin(), board.end(), cross));
    cout << answer + 1 << '\n';
    return 0;
}