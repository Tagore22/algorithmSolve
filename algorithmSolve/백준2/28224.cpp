#include <iostream>

using namespace std;

int main()
{
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int cur;
        cin >> cur;
        ans += cur;
    }
    cout << ans << '\n';
    return 0;
}