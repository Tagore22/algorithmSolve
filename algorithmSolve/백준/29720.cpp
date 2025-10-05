#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    int minnum = max(0, N - M * K);
    int maxnum = max(0, N - M * (K - 1) - 1);

    cout << minnum << ' ' << maxnum << '\n';
    return 0;
}