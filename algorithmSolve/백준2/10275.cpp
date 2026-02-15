#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        long long cur = pow(2, n);
        int answer = -1;
        while (b > 0)
        {
            ++answer;
            if (b >= cur)
                b -= cur;
            cur /= 2;
        }
        cout << answer << '\n';
    }
    return 0;
}