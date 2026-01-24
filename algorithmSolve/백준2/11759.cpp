#include <iostream>

using namespace std;

int main()
{
    int s, v1, v2;
    cin >> s >> v1 >> v2;

    int to = s / v1;
    pair<int, int> answer = make_pair(-1, -1);
    for (int i = to; i >= 0; --i)
    {
        int cur = s - (v1 * i);
        if (cur % v2 == 0)
        {
            answer = make_pair(i, cur / v2);
            break;
        }
    }
    if (answer.first != -1)
        cout << answer.first << ' ' << answer.second;
    else
        cout << "Impossible" << '\n';
    return 0;
}