#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (true)
    {
        int cur;
        cin >> cur;
        if (cur == 0)
            break;
        if (cur % n == 0)
            cout << cur << " is a multiple of " << n << '.' << '\n';
        else
            cout << cur << " is NOT a multiple of " << n << '.' << '\n';
    }
    return 0;
}