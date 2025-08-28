#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int answer = 987654321;
    pair<int, int> pos = make_pair(0, 0);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            int num;
            cin >> num;
            if (num == 0)
            {
                int cur = i + abs((M / 2 + 1) - j);
                if (cur < answer)
                {
                    answer = cur;
                    pos = make_pair(i, j);
                }
            }
        }
    }
    if (answer == 987654321)
        cout << -1 << '\n';
    else
        cout << pos.first << ' ' << pos.second << '\n';
    return 0;
}