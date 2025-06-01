#include <iostream>

using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    int first = max(X, Y);
    int second = min(X, Y);
    for (int i = 0; i < first - second; ++i)
        cout << 1;
    for (int i = 0; i < second; ++i)
        cout << 2;
    cout << '\n';
    return 0;
}