#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> first;
vector<pair<int, int>> second;
vector<vector<int>> cashe(1000, vector<int>(1000, -1));
int n, w;

int Calcul(int a, int b)
{
    if (a == w || b == w)
        return 0;

    int& ans = cashe[a][b];
    if (ans != -1)
        return ans;

    int now = max(a, b) + 1;

    int FirstWay = abs(first[now].first - first[a].first) + abs(first[now].second - first[a].second);
    int SecondWay = abs(second[now].first - second[b].first) + abs(second[now].second - second[b].second);

    int FirstGo = Calcul(now, b) + FirstWay;
    int SecondGo = Calcul(a, now) + SecondWay;
    return ans = min(FirstGo, SecondGo);
}

void FindAnswer(int a, int b)
{
    if (a == w || b == w)
        return;

    int now = max(a, b) + 1;

    int FirstWay = abs(first[now].first - first[a].first) + abs(first[now].second - first[a].second);
    int SecondWay = abs(second[now].first - second[b].first) + abs(second[now].second - second[b].second);

    int FirstGo = Calcul(now, b) + FirstWay;
    int SecondGo = Calcul(a, now) + SecondWay;

    if (FirstGo <= SecondGo)
    {
        cout << 1 << '\n';
        FindAnswer(now, b);
    }
    else
    {
        cout << 2 << '\n';
        FindAnswer(a, now);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> w;
    first.push_back(make_pair(1, 1));
    second.push_back(make_pair(n, n));
    for (int i = 0; i < w; ++i)
    {
        int a, b;
        cin >> a >> b;
        first.push_back(make_pair(a, b));
        second.push_back(make_pair(a, b));
    }
    cout << Calcul(0, 0) << '\n';
    FindAnswer(0, 0);
    return 0;
}