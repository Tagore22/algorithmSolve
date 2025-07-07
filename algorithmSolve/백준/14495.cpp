#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 3)
    {
        cout << 1 << '\n';
        return 0;
    }
    long long fibo[117];
    fibo[1] = fibo[2] = fibo[3] = 1;
    for (int i = 4; i <= n; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 3];
    cout << fibo[n] << '\n';
    return 0;
}