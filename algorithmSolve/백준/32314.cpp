#include <iostream>

using namespace std;

int main()
{
    int a, w, v;
    cin >> a >> w >> v;
    if (w / v >= a)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}