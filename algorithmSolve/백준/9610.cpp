#include <iostream>

using namespace std;

int main()
{
    int N, Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        int x, y;
        cin >> x >> y;
        if (x > 0 && y > 0)
            ++Q1;
        else if (x < 0 && y > 0)
            ++Q2;
        else if (x < 0 && y < 0)
            ++Q3;
        else if (x > 0 && y < 0)
            ++Q4;
        else if (x == 0 || y == 0)
            ++AXIS;
    }
    cout << "Q1: " << Q1 << '\n';
    cout << "Q2: " << Q2 << '\n';
    cout << "Q3: " << Q3 << '\n';
    cout << "Q4: " << Q4 << '\n';
    cout << "AXIS: " << AXIS << '\n';
    return 0;
}