#include <iostream>

using namespace std;

int main()
{
    int n, h, v;
    cin >> n >> h >> v;
    int col = max(h, n - h);
    int row = max(v, n - v);
    cout << col * row * 4 << '\n';
    return 0;
}