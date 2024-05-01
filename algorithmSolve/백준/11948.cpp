#include <iostream>

using namespace std;

int main()
{
    int point[4];
    int sum = 0, minus = 101;
    for (int i = 0; i < 4; ++i)
    {
        cin >> point[i];
        sum += point[i];
        minus = min(minus, point[i]);
    }
    sum -= minus, minus = 101;
    for (int i = 0; i < 2; ++i)
    {
        cin >> point[i];
        sum += point[i];
        minus = min(minus, point[i]);
    }
    sum -= minus;
    cout << sum << '\n';
    return 0;
}