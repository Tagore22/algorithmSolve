#include <iostream>

using namespace std;

int main()
{
    int a3, a2, a1, b3, b2, b1;
    cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;

    int apple = a3 * 3 + a2 * 2 + a1;
    int banana = b3 * 3 + b2 * 2 + b1;

    if (apple > banana)
        cout << 'A' << '\n';
    else if (apple < banana)
        cout << 'B' << '\n';
    else
        cout << 'T' << '\n';
    return 0;
}