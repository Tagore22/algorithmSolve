#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, answer = 0, cur = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int l, r;
        cin >> l >> r;
        if (l == 1 || r == 1)
        {
            answer = max(answer, cur);
            cur = 0;
        }
        else
        {
            cur += 2;
        }
    }
    answer = max(answer, cur);
    cout << answer << '\n';
    return 0;
}