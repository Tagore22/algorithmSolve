#include <iostream>
#include <vector>

using namespace std;

vector<int> board;
int k, n;
long long maxNum;

bool checkCal(long long num)
{
    long long answer = 0;
    for (int i = 0; i < k; ++i)
        answer += board[i] / num;
    return answer >= n;
}

long long calcul()
{
    long long lo = 0;
    long long hi = maxNum + 1;
    for (int i = 0; i < 100; ++i)
    {
        long long mid = (lo + hi) / 2;
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

    cin >> k >> n;
    board.assign(k, 0);
    maxNum = 0;
    for (int i = 0; i < k; ++i)
    {
        cin >> board[i];
        if (maxNum < board[i])
            maxNum = board[i];
    }
    cout << calcul() << '\n';
    return 0;
}