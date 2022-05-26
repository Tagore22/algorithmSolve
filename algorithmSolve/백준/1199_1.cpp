#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> Edges;
vector<int> EdgeNums;
vector<vector<int>> board;
vector<int> answer;
int n;
int FinalSum = 0;

void DFS(int now)
{
    while (!board[now].empty())
    {
        int here = board[now].back();
        if (EdgeNums[here] > 0)
        {
            --EdgeNums[here];
            int a = Edges[here].first;
            int b = Edges[here].second;
            if (now == a)
                DFS(b);
            else
                DFS(a);
        }
        else
        {
            board[now].pop_back();
        }
    }
    answer.push_back(now);
}

void MakeAnswer()
{
    DFS(0);
    if (answer.size() != FinalSum + 1)
        cout << -1 << '\n';
    else
    {
        reverse(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] + 1 << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        int EdgeSum = 0;
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            EdgeSum += x;
            if (i >= j || x == 0)
                continue;
            Edges.push_back(make_pair(i, j));
            EdgeNums.push_back(x);
            board[i].push_back(Edges.size() - 1);
            board[j].push_back(Edges.size() - 1);
            FinalSum += x;
        }
        if (EdgeSum % 2 == 1)
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    MakeAnswer();
    return 0;
}