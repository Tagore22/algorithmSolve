#include <iostream>

using namespace std;

// Ç®ÀÌ.
//

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int gap, prev, cur;
    cin >> prev;
    gap = prev * 2;
    for (int i = 1; i < M; ++i)
    {
        cin >> cur;
        gap = max(gap, cur - prev);
        prev = cur;
    }
    gap = max(gap, (N - prev) * 2);
    gap = gap % 2 != 0 ? gap + 1 : gap;
    cout << gap / 2 << '\n';
    return 0;
}