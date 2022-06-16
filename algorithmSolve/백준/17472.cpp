#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> Lands;
vector<pair<int, pair<int, int>>> board;
vector<vector<int>> LandSee;
vector<vector<bool>> Check;
int CY[4] = { -1,0,1,0 };
int CX[4] = { 0,-1,0,1 };
int n, m;
int LandNum = -1;

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

void DFS(int y, int x, int LandNum)
{
    if (Lands.size() == LandNum)
    {
        vector<pair<int, int>> vec;
        Lands.push_back(vec);
    }
    Lands[LandNum].push_back(make_pair(y, x));
    Check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int DY = y + CY[i];
        int DX = x + CX[i];
        if (DY < 0 || DY >= n || DX < 0 || DX >= m || LandSee[DY][DX] == 0 || Check[DY][DX])
            continue;
        DFS(DY, DX, LandNum);
    }
}

void FindLand()
{
    Check.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (LandSee[i][j] == 1 && !Check[i][j])
            {
                ++LandNum;
                DFS(i, j, LandNum);
            }
}

bool CheckSeeY(int y, int x1, int x2)
{
    int from = x1 < x2 ? x1 : x2;
    int to = x1 < x2 ? x2 : x1;
    for (int i = from + 1; i < to; ++i)
        if (LandSee[y][i] == 1)
            return false;
    return true;
}

bool CheckSeeX(int x, int y1, int y2)
{
    int from = y1 < y2 ? y1 : y2;
    int to = y1 < y2 ? y2 : y1;
    for (int i = from + 1; i < to; ++i)
        if (LandSee[i][x] == 1)
            return false;
    return true;
}

void CalculDist() // 다리의 길이는 2이상이여야 하며 바다위에만 지을수 있다.
{
    FindLand();
    for (int i = 0; i < Lands.size() - 1; ++i)
        for (int j = i + 1; j < Lands.size(); ++j)
            for (int a = 0; a < Lands[i].size(); ++a)
                for (int b = 0; b < Lands[j].size(); ++b)
                {
                    if (Lands[i][a].first == Lands[j][b].first && abs(Lands[i][a].second - Lands[j][b].second) >= 3 && CheckSeeY(Lands[i][a].first, Lands[i][a].second, Lands[j][b].second)) // 두 좌표의 y값이 같을때
                        board.push_back(make_pair(abs(Lands[i][a].second - Lands[j][b].second) - 1, make_pair(i, j)));
                    if (Lands[i][a].second == Lands[j][b].second && abs(Lands[i][a].first - Lands[j][b].first) >= 3 && CheckSeeX(Lands[i][a].second, Lands[i][a].first, Lands[j][b].first)) // 두 좌표의 x값이 같을때
                        board.push_back(make_pair(abs(Lands[i][a].first - Lands[j][b].first) - 1, make_pair(i, j)));
                }
    sort(board.begin(), board.end());
}

void ShowAnswer()
{
    CalculDist();
    UF uni(LandNum + 1);
    int answer = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        int first = board[i].second.first;
        int second = board[i].second.second;
        int len = board[i].first;

        if (uni.FindParent(first) == uni.FindParent(second))
            continue;

        uni.Fusion(first, second);
        answer += len;
    }
    for (int i = 0; i < LandNum; ++i)
        for (int j = i + 1; j < LandNum + 1; ++j)
            if (uni.FindParent(i) != uni.FindParent(j))
            {
                cout << -1 << '\n';
                return;
            }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    LandSee.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> LandSee[i][j];
    ShowAnswer();
    return 0;
}