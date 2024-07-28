#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 2 * c)
        cout << a + b - (2 * c) << '\n';
    else
        cout << a + b << '\n';
    return 0;
}