#include <iostream>

using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    cout << N / 2 * M + N % 2 * M / 2 << '\n';
    return 0;
}