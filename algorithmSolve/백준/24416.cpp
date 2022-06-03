#include <iostream>

using namespace std;

int FiboNum1 = 0;
int FiboNum2 = 0;
int f[40];

int fibo(int n)
{
    if (n == 1 || n == 2)
    {
        ++FiboNum1;
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int fibona(int n)
{
    f[1] = f[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        ++FiboNum2;
    }
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    fibo(n);
    fibona(n);
    cout << FiboNum1 << '\n';
    cout << FiboNum2 << '\n';
    return 0;
}