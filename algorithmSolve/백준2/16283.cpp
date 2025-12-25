#include <iostream>

using namespace std;

int main()
{
    int a, b, n, w;
    cin >> a >> b >> n >> w;
    pair<int, int> answer = make_pair(-1, -1);
    for (int i = 1; i < n; ++i)
    {
        if (a * i + b * (n - i) == w)
        {
            if (answer.first == -1)
            {
                answer = make_pair(i, (n - i));
            }
            else
            {
                answer = make_pair(-1, -1);
                break;
            }
        }
    }
    if (answer.first == -1)
        cout << -1 << '\n';
    else
        cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}