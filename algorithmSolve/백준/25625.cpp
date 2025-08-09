#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    int div = y / x;
    int mul = y % x;
    cout << (div % 2 == 0 ? x + mul : mul) << '\n';
    return 0;
}