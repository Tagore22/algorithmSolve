#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int low = 101, sum = 0;
        for (int i = 0; i < 7; ++i)
        {
            int num;
            cin >> num;
            if (num % 2 == 0)
            {
                sum += num;
                low = min(low, num);
            }
        }
        cout << sum << ' ' << low << '\n';
    }
    return 0;
}