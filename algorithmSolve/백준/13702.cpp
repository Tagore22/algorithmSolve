#include <iostream>

using namespace std;

int N, K;
int board[10000];

bool IsCanDivide(long long mid)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans += board[i] / mid;
    return ans >= K;
}

void Solve()
{
    long long low = 0, high = (1 << 31) - 1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (IsCanDivide(mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << low - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}