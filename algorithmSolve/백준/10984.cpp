#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    std::fixed;
    std::cout.precision(2);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int N, c_sum = 0;
        float g_sum = 0;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            int C;
            float G;
            cin >> C >> G;
            c_sum += C;
            g_sum += C * G;
        }
        cout << c_sum << ' ' << g_sum / c_sum << '\n';
    }
    return 0;
}