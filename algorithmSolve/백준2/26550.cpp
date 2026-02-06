#include <iostream>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        long long cur = 0, answer = 0;
        for (int i = 1; i <= N; ++i)
        {
            cur += i;
            answer += cur;
        }
        cout << answer << '\n';
    }
    return 0;
}