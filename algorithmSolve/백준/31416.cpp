#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;
    for (int iter = 0; iter < Q; ++iter)
    {
        int t1, t2, v1, v2;
        cin >> t1 >> t2 >> v1 >> v2;
        int answer = 30000, plus = t2 * v2;
        for (int i = 0; i <= v1; ++i)
            answer = min(answer, max((t1 * i), (t1 * (v1 - i)) + plus));
        cout << answer << '\n';
    }
    return 0;
}