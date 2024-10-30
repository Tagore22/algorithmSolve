#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;
    int x = p * a;
    int y = p > c ? b + (p - c) * d : b;
    int answer = min(x, y);
    cout << answer << '\n';
    return 0;
}