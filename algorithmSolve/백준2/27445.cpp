#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int cur;
    pair<int, int> mini = make_pair(-1, 51);
    for (int i = 1; i <= N; ++i)
    {
        cin >> cur;
        if (cur < mini.second)
            mini = make_pair(i, cur);
    }
    pair<int, int> answer;
    answer.first = mini.first;
    mini = make_pair(1, cur);
    for (int i = 2; i <= M; ++i)
    {
        cin >> cur;
        if (cur < mini.second)
            mini = make_pair(i, cur);
    }
    answer.second = mini.first;
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}