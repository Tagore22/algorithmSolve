#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int HH, MM;
    cin >> HH >> MM;
    cout << (HH - 9) * 60 + MM << '\n';
    return 0;
}