#include <iostream>

using namespace std;

int n, m, from, to;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int answer = m;
    bool iszero = false;
    for (int i = 0; i < n; ++i)
    {
        cin >> from >> to;
        m += from - to;
        answer = max(answer, m);
        if (m < 0)
            iszero = true;
    }
    cout << (iszero ? 0 : answer) << '\n';
    return 0;
}