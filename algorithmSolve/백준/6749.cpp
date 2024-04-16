#include <iostream>

using namespace std;

int main()
{
    int m, y;
    cin >> m >> y;
    if (m < y)
        swap(m, y);
    cout << m + m - y << '\n';
    return 0;
}