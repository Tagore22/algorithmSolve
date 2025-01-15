#include <iostream>

using namespace std;

int main()
{
    int p, q, a, b;
    cin >> p >> q >> a >> b;
    int first = min(p, q);
    int second = q > p ? q - p : 0;
    cout << (first * a + second * b) << '\n';
    return 0;
}