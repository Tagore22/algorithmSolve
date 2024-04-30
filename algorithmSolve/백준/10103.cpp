#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, c, s, score_c = 100, score_s = 100;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> c >> s;
        if (c > s)
            score_s -= c;
        else if (c < s)
            score_c -= s;
    }
    cout << score_c << '\n';
    cout << score_s << '\n';
    return 0;
}