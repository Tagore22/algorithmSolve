#include <iostream>
#include <cstring>

using namespace std;

pair<int, int> WayA[1001];
pair<int, int> WayB[1001];
int cashe[1000][1000];
int n, w;

int Calcul(int a, int b) //��� ��ο� ���� �Ÿ��� ��ó���Ѵ�.
{
    if (a == w || b == w)
        return 0;

    int& ans = cashe[a][b];
    if (ans != -1)
        return ans;

    int now = max(a, b) + 1;
    int FirstWay = abs(WayA[now].first - WayA[a].first) + abs(WayA[now].second - WayA[a].second);
    int SecondWay = abs(WayB[now].first - WayB[b].first) + abs(WayB[now].second - WayB[b].second);

    return ans = min(Calcul(now, b) + FirstWay, Calcul(a, now) + SecondWay);
}

void FindAnswer(int a, int b) // �� ��θ� �̸� ���찡�� �� ª�� ��η� �ϳ��� ���ư�.
{
    if (a == w || b == w)
        return;

    int now = max(a, b) + 1;
    int FirstWay = abs(WayA[now].first - WayA[a].first) + abs(WayA[now].second - WayA[a].second);
    int SecondWay = abs(WayB[now].first - WayB[b].first) + abs(WayB[now].second - WayB[b].second);

    int FirstAns = Calcul(now, b) + FirstWay;
    int SecondAns = Calcul(a, now) + SecondWay;

    if (FirstAns <= SecondAns) // ù��° ��ΰ� �� ª����
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
    cin >> n >> w;
    WayA[0] = make_pair(1, 1);
    WayB[0] = make_pair(n, n);
    for (int i = 1; i <= w; ++i)
    {
        int a, b;
        cin >> a >> b;
        WayA[i] = make_pair(a, b);
        WayB[i] = make_pair(a, b);
    }
    memset(cashe, -1, sizeof(cashe));
    cout << Calcul(0, 0) << '\n';
    FindAnswer(0, 0);
    return 0;
}