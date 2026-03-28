#include <iostream>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        int idx = 1;
        while (idx <= N)
        {
            idx *= 10;
        }
        int square = N * N;
        if (square % idx == N)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}