#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A > B)
        cout << B + B + 1 << '\n';
    else
        cout << A + A - 1 << '\n';
    return 0;
}