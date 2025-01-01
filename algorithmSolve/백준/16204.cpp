#include <iostream>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    int o = min(M, K);
    int x = min(N - M, N - K);
    cout << o + x << '\n';
    return 0;
}