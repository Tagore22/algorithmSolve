#include <iostream>

using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        sum += i;
    cout << sum << '\n';
    cout << sum * sum << '\n';
    cout << sum * sum << '\n';
    return 0;
}