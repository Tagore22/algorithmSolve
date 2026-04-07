#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        if (c - b == b - a)
            cout << "AP " << c + b - a << '\n';
        else
            cout << "GP " << c * b / a << '\n';
    }
    return 0;
}