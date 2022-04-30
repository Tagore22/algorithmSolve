#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
int n, c, maxNum;

bool checkCal(int num)
{
    int answer = 0;
    int idx = board[0];
    for (int i = 1; i < n; ++i)
        if (board[i] - idx >= num)
        {
            idx = board[i];
            ++answer;
        }
    return answer >= c - 1;
}

int calcul()
{
    int lo = -1;
    int hi = maxNum + 1;
    for (int i = 0; i < 100; ++i)
    {
        int mid = (lo + hi) / 2;
        if (checkCal(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    board.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    sort(board.begin(), board.end());
    maxNum = board[n - 1] - board[0];
    cout << calcul() << '\n';
    return 0;
}