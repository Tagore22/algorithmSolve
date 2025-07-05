#include <iostream>

using namespace std;

int T, a, b;
int p1[100] = { 1, 2, 3, 4, 5, 6 }, p2[64] = { 1, 2, 4, 8, 16 };
int m1[6] = { 500, 300, 200, 50, 30, 10 }, m2[5] = { 512, 256, 128, 64, 32 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> a >> b;
        int answer = 0;
        if (a != 0)
        {
            for (int i = 0; i < 6; ++i)
            {
                if (a <= p1[i])
                {
                    answer += m1[i];
                    break;
                }
                a -= p1[i];
            }
        }
        if (b != 0)
        {
            for (int i = 0; i < 5; ++i)
            {
                if (b <= p2[i])
                {
                    answer += m2[i];
                    break;
                }
                b -= p2[i];
            }
        }
        cout << answer * 10000 << '\n';
    }
    return 0;
}