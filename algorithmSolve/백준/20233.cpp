#include <iostream>

using namespace std;

int main()
{
    int a, x, b, y, T;
    cin >> a >> x >> b >> y >> T;
    int atime = max(0, T - 30);
    int btime = max(0, T - 45);
    cout << atime * x * 21 + a << ' ' << btime * y * 21 + b << '\n';
    return 0;
}