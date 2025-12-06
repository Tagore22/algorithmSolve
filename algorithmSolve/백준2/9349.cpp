#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int N, K;
        cin >> N >> K;
        cout << (N - K) / (K - 1) << '\n';
    }
    return 0;
}