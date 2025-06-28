#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, s, n;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> s >> n;
        for (int i = 0; i < n; ++i)
        {
            int q, p;
            cin >> q >> p;
            s += q * p;
        }
        cout << s << '\n';
    }
    return 0;
}