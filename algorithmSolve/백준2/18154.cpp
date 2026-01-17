#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    pair<int, int> prev = make_pair(0, 0);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int t, d;
        cin >> t >> d;
        if (d == 0)
            continue;
        int cur = (d - prev.second) / (t - prev.first);
        answer = max(answer, cur);
        prev = make_pair(t, d);
    }
    cout << answer << '\n';
    return 0;
}