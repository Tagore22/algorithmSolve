#include <iostream>

using namespace std;

int T, N, M;

int main()
{
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> M;
        int b = N - M;
        int a = M - b;
        cout << a << ' ' << b << '\n';
    }
    return 0;
}