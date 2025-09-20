#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int first, second;
    cin >> first >> second;
    int a = 100 - first, b = 100 - second;
    int c = 100 - a - b, d = a * b;
    int q = d / 100, r = d % 100;
    int f_ans = c + q;
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';
    cout << f_ans << ' ' << r << '\n';
    return 0;
}