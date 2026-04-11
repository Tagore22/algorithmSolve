#include <iostream>

using namespace std;

int T, N, minnum, maxnum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        minnum = 1000001, maxnum = -1000001;
        for (int i = 0; i < N; ++i)
        {
            int num;
            cin >> num;
            minnum = min(minnum, num);
            maxnum = max(maxnum, num);
        }
        cout << minnum << ' ' << maxnum << '\n';
    }
    return 0;
}