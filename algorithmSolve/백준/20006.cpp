#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int>> room[300];
int p, m;

void Solve()
{
    for (int iter = 0; iter < p; ++iter)
    {
        int level;
        string name;
        cin >> level >> name;
        for (int i = 0; i < 300; ++i)
        {
            if (room[i].size() == 0 || room[i].size() < m &&
                abs(room[i][0].second - level) <= 10)
            {
                room[i].push_back({ name, level });
                break;
            }
        }
    }

    int cur = 0;
    while (room[cur].size() != 0)
    {
        int csize = room[cur].size();
        sort(room[cur].begin(), room[cur].end());
        if (csize == m)
            cout << "Started!" << '\n';
        else
            cout << "Waiting!" << '\n';
        for (int i = 0; i < csize; ++i)
            cout << room[cur][i].second << ' ' << room[cur][i].first << '\n';
        ++cur;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> m;
}

int main()
{
    Input();
    Solve();
    return 0;
}