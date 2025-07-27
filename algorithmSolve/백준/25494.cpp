#include <iostream>
#include <algorithm>

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
        int a, b, c;
        cin >> a >> b >> c;

        int answer = min({ a, b, c });
        cout << answer << '\n';
    }
    return 0;
}