#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    bool isdiv = N % 7 == 0 ? true : false;
    bool hasseven = false;
    while (N > 0)
    {
        if (N % 10 == 7)
        {
            hasseven = true;
            break;
        }
        N /= 10;
    }

    if (!hasseven)
    {
        if (!isdiv)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }
    else
    {
        if (!isdiv)
            cout << 2 << '\n';
        else
            cout << 3 << '\n';
    }
    return 0;
}