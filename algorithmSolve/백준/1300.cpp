#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;

long long checkCal(long long num)
{
    long long answer = 0;
    for (int i = 1; i <= n; ++i)
        answer += min(num / i, n);
    return answer;
}

long long calcul()
{
    long long lo = 0;
    long long hi = (n * n) + 1;
    for (int i = 0; i < 100; ++i)
    {
        long long mid = (lo + hi) / 2;
        if (checkCal(mid) >= k)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cout << calcul() << '\n';
    return 0;
}