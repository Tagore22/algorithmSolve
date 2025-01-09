#include <iostream>

using namespace std;

int main()
{
    int r, f = 0;
    cin >> r;
    int num;
    for (int i = 0; i < 3; ++i)
    {
        cin >> num;
        f += num;
    }
    if (r <= f || r <= 240)
        cout << "high speed rail" << '\n';
    else
        cout << "flight" << '\n';
    return 0;
}