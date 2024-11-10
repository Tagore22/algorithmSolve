#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (620 <= n && n <= 780)
        cout << "Red" << '\n';
    else if (590 <= n && n < 620)
        cout << "Orange" << '\n';
    else if (570 <= n && n < 590)
        cout << "Yellow" << '\n';
    else if (495 <= n && n < 570)
        cout << "Green" << '\n';
    else if (450 <= n && n < 495)
        cout << "Blue" << '\n';
    else if (425 <= n && n < 450)
        cout << "Indigo" << '\n';
    else
        cout << "Violet" << '\n';
    return 0;
}