#include <iostream>

using namespace std;

int main()
{
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    int tired = 0, work = 0;
    for (int iter = 0; iter < 24; ++iter)
    {
        if (tired + A > M)
        {
            tired = tired - C >= 0 ? tired - C : 0;
        }
        else
        {
            tired += A;
            work += B;
        }
    }
    cout << work << '\n';
    return 0;
}