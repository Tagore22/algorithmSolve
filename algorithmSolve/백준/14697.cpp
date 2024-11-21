#include <iostream>

using namespace std;

int main()
{
    int a, b, c, N;
    cin >> a >> b >> c >> N;
    for (int i = 0; i <= N / a; ++i)
    {
        int cur = N - i * a;
        int remainA = cur;
        for (int j = 0; j <= remainA / b; ++j)
        {
            cur = remainA - j * b;
            int remainB = cur;
            for (int z = 0; z <= remainB / c; ++z)
            {
                cur = remainB - z * c;
                if (cur == 0)
                {
                    cout << 1 << '\n';
                    exit(0);
                }
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}