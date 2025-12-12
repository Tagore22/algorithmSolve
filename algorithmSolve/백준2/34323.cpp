#include <iostream>

using namespace std;

int main()
{
    long long N, M, S;
    cin >> N >> M >> S;
    long long first = M * S;
    long long second = (M + 1) * S * (100 - N) / 100;
    cout << (first < second ? first : second) << '\n';
    return 0;
}