#include <iostream>

using namespace std;

int c;

long long calcul(int a, int b)
{
    if (b == 1)
        return a % c;
    if (b % 2 == 1)
        return ((a % c) * (calcul(a, b - 1) % c)) % c;
    else
        return ((calcul(a, b / 2) % c) * (calcul(a, b / 2) % c)) % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b >> c;
    cout << calcul(a, b) << '\n';
    return 0;
}