#include <iostream>

using namespace std;

int main()
{
    int r, f;
    cin >> r >> f;
    cout << (r <= f ? "high speed rail" : "flight") << '\n';
    return 0;
}