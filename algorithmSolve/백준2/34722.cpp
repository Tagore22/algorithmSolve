#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int answer = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a >= 1000 || b >= 1600 || c >= 1500 || (1 <= d && d <= 30))
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}