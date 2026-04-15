#include <iostream>

using namespace std;

int main()
{
    long long K, N;
    cin >> K >> N;

    if (N == 1)
    {
        cout << -1 << '\n';
        return 0;
    }

    long long div = K / (N - 1);
    div = K % (N - 1) != 0 ? div + 1 : div;
    long long from = div * N;
    for (long long i = from; i > 0; --i)
    {
        long long cur = (i - K) * N;
        if (cur < i)
        {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}