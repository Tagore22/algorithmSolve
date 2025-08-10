#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> maxnum;

void CalNums(int mid)
{
    vector<int> cur = { N, mid };
    int idx = 0;
    while (true)
    {
        int num = cur[idx] - cur[idx + 1];
        if (num < 0)
            break;
        cur.push_back(num);
        ++idx;
    }

    if (cur.size() > maxnum.size())
        maxnum = cur;
    return;
}

void Solve()
{
    int from = N / 2;
    for (int i = from; i <= N; ++i)
        CalNums(i);

    cout << maxnum.size() << '\n';
    for (auto& c : maxnum)
        cout << c << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}