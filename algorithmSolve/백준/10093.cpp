#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;
    if (A > B)
        swap(A, B);
    if (A == B)
        cout << 0 << '\n';
    else
        cout << B - A - 1 << '\n';
    for (long long i = A + 1; i < B; ++i)
        cout << i << ' ';
    cout << '\n';
    return 0;
}