#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w[10], k[10];
    for (int i = 0; i < 10; ++i)
        cin >> w[i];
    for (int i = 0; i < 10; ++i)
        cin >> k[i];
    sort(w, w + 10, greater<>());
    sort(k, k + 10, greater<>());
    int sum_w = w[0] + w[1] + w[2];
    int sum_k = k[0] + k[1] + k[2];
    cout << sum_w << ' ' << sum_k << '\n';
    return 0;
}