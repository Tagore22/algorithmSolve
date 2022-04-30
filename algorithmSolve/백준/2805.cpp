#include <iostream>
#include <vector>

using namespace std;

vector<int> board;
int n, m, maxNum;

bool checkCal(int num)
{
    long long answer = 0;
    for (int i = 0; i < n; ++i)
    {
        int cut = num >= board[i] ? 0 : board[i] - num;
        answer += cut;
    }
    return answer >= m;
}

long long calcul()
{
    int lo = 0;
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

    cin >> n >> m;
    board.assign(n, 0);
    maxNum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        maxNum = maxNum < board[i] ? board[i] : maxNum;
    }
    cout << calcul() << '\n';
    return 0;
}