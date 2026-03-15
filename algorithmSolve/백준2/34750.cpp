#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int div;
    if (1000000 <= N)
        div = 20;
    else if (500000 <= N && N < 1000000)
        div = 15;
    else if (100000 <= N && N < 500000)
        div = 10;
    else
        div = 5;

    int p = N / 100 * div;
    cout << p << ' ' << N - p << '\n';
    return 0;
}