#include <iostream>

using namespace std;

int N;
bool visit[6][6] = { false, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    if (N != 3)
    {
        cout << "Woof-meow-tweet-squeek" << '\n';
        return 0;
    }
    for (int i = 0; i < N; ++i)
    {
        int from, to;
        cin >> from >> to;
        visit[from][to] = true;
        visit[to][from] = true;
    }
    if (visit[1][3] && visit[1][4] && visit[3][4])
        cout << "Wa-pa-pa-pa-pa-pa-pow!" << '\n';
    else
        cout << "Woof-meow-tweet-squeek" << '\n';
    return 0;
}