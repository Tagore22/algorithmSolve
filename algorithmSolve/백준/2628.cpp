#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cut;
vector<int> row, col;

void Solve()
{
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    int answer = 0, colprev = 0;
    for (auto& c : col)
    {
        int rowprev = 0;
        int colnum = c - colprev;
        for (auto& r : row)
        {
            int rownum = r - rowprev;
            answer = max(answer, colnum * rownum);
            rowprev = r;
        }
        colprev = c;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> cut;
    for (int i = 0; i < cut; ++i)
    {
        int num, idx;
        cin >> num >> idx;
        if (num == 0)
            col.push_back(idx);
        else
            row.push_back(idx);
    }
    col.push_back(M);
    row.push_back(N);
}

int main()
{
    Input();
    Solve();
    return 0;
}