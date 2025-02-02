#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, X, N;
    cin >> T >> X >> N;

    int K, num, answer = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> K;
        for (int i = 0; i < K; ++i)
        {
            cin >> num;
            if (num == X)
                ++answer;
        }
    }
    cout << (answer == N ? "YES" : "NO") << '\n';
    return 0;
}