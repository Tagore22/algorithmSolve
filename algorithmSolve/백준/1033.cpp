#include <iostream>
#include <vector>

using namespace std;

struct Ratio
{
    int a, b, Ra, Rb;
    Ratio(int a, int b, int Ra, int Rb) : a(a), b(b), Ra(Ra), Rb(Rb)
    {}
};

vector<long long> answer;
vector<vector<int>> link;
vector<Ratio> board;
vector<bool> check;
int N;

int gcd(int p, int q)
{
    if (q == 0)
        return p;
    return gcd(q, p % q);
}

void DFS(int here, int num)
{
    check[here] = true;
    answer[here] *= num;
    for (int i = 0; i < link[here].size(); ++i)
    {
        int there = link[here][i];
        if (!check[there])
            DFS(there, num);
    }
}

void ShowAnswer()
{
    answer.assign(N, 1);
    link.assign(N, vector<int>());
    for (int i = 0; i < board.size(); ++i)
    {
        int a = board[i].a;
        int b = board[i].b;
        int Ra = board[i].Ra;
        int Rb = board[i].Rb;

        int nowA = answer[a];
        int nowB = answer[b];

        if (answer[a] != answer[b])
        {
            check.assign(N, false);
            DFS(a, nowB);
            check.assign(N, false);
            DFS(b, nowA);
        }
        check.assign(N, false);
        DFS(a, Ra);
        check.assign(N, false);
        DFS(b, Rb);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    int GcdNum = answer[0];
    for (int i = 1; i < N; ++i)
        GcdNum = gcd(GcdNum, answer[i]);
    for (int i = 0; i < N; ++i)
    {
        answer[i] /= GcdNum;
        cout << answer[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        board.push_back(Ratio(a, b, c, d));
    }
    ShowAnswer();
    return 0;
}