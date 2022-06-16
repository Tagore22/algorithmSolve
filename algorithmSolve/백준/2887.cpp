#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> board;
vector<pair<int, int>> Points[3];
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

void MakeGraph()
{
    for (int i = 0; i < 3; ++i)
    {
        sort(Points[i].begin(), Points[i].end());
        for (int j = 0; j < Points[i].size() - 1; ++j)
            board.push_back(make_pair(abs(Points[i][j].first - Points[i][j + 1].first), make_pair(Points[i][j].second, Points[i][j + 1].second)));
    }
    sort(board.begin(), board.end());
}

void ShowAnswer(UF& uni)
{
    MakeGraph();
    long long answer = 0;
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
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Points[0].push_back(make_pair(a, i));
        Points[1].push_back(make_pair(b, i));
        Points[2].push_back(make_pair(c, i));
    }
    UF uni(n);
    ShowAnswer(uni);
    return 0;
}