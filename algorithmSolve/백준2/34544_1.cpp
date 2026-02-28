#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int answer = 1;
    for (int iter = 0; iter < N; ++iter)
    {
        int first, second;
        cin >> first >> second;

        int plus = second - first;
        if (first* second < 0)
            plus = plus > 0 ? plus - 1 : plus + 1;
        answer += plus;
    }
    if (answer <= 0)
        answer -= 1;

    cout << answer << '\n';
    return 0;
}