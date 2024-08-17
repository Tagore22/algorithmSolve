#include <iostream>

using namespace std;

int main()
{
    int t, s;
    cin >> t >> s;
    if (s == 1 || t < 12 || t > 16)
        cout << 280 << '\n';
    else
        cout << 320 << '\n';
    return 0;
}