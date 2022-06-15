#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;//크루스칼로 풀것(이미 연결된 정점들)

vector<pair<double, pair<int, int>>> board;
vector<pair<double, double>> points;
int n, m;

class UF
{
private:
    vector<int> Parent;
    vector<int> Size;

public:
    UF(int n);
    int GetSize(int now) const;
    void SetSize(int now, int next);
    int FindParent(int now);
    void Fusion(int a, int b);
};

UF::UF(int n) : Parent(n, 0), Size(n, 0)
{
    for (int i = 0; i < n; ++i)
        Parent[i] = i;
}

int UF::GetSize(int now) const
{
    return Size[now];
}

void UF::SetSize(int now, int next)
{
    Size[now] = next;
}

int UF::FindParent(int now)
{
    if (Parent[now] == now)
        return now;
    return Parent[now] = FindParent(Parent[now]);
}

void UF::Fusion(int a, int b)//a가 b의 부모가 된다.
{
    a = FindParent(a);
    b = FindParent(b);

    if (a == b)
        return;

    if (GetSize(a) < GetSize(b))
        swap(a, b);

    Parent[b] = a;
    if (GetSize(a) == GetSize(b))
        SetSize(a, GetSize(a) + 1);
}

double CalculDist(int a, int b)
{
    double x1 = points[a].first;
    double y1 = points[a].second;
    double x2 = points[b].first;
    double y2 = points[b].second;

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void MakeGraph()
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            double dist = CalculDist(i, j);
            board.push_back(make_pair(dist, make_pair(i, j)));
        }
    sort(board.begin(), board.end());
}

void ShowAnswer(UF& uni)
{
    MakeGraph();
    double answer = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        int first = board[i].second.first;
        int second = board[i].second.second;
        double len = board[i].first;

        if (uni.FindParent(first) == uni.FindParent(second))
            continue;

        uni.Fusion(first, second);
        answer += len;
    }
    cout << fixed;
    cout.precision(2);
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    points.assign(n, make_pair(0.0, 0.0));
    for (int i = 0; i < n; ++i)
    {
        double a, b;
        cin >> a >> b;
        points[i] = make_pair(a, b);
    }
    UF uni(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        uni.Fusion(a - 1, b - 1);
    }
    ShowAnswer(uni);
    return 0;
}