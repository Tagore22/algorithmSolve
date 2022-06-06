#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<int> w;
vector<bool> check;
vector<vector<int>> cashe;
vector<int> answer;
int n;

void DFS(int here)//두번째 인덱스가 1이면 사용, 아니면 사용x
{
    check[here] = true;
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (check[there])
            continue;
        DFS(there);
        cashe[here][0] += max(cashe[there][1], cashe[there][0]);
        cashe[here][1] += cashe[there][0];
    }
    cashe[here][1] += w[here];
}

void FindNum(int prev, int here)
{
    if (cashe[here][1] > cashe[here][0] && !check[prev])
    {
        answer.push_back(here);
        check[here] = true;
    }

    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];
        if (prev == there)
            continue;
        FindNum(here, there);
    }
}

void ShowAnswer()
{
    check.assign(n + 1, false);
    FindNum(0, 1);
    sort(answer.begin(), answer.end());
    cout << (cashe[1][0] > cashe[1][1] ? cashe[1][0] : cashe[1][1]) << '\n';
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

int main()//정점의 수는 1번부터 n번까지, 트리이기에 양방향 그래프
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    w.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    board.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    check.assign(n + 1, false);
    cashe.assign(n + 1, vector<int>(2, 0));
    DFS(1);
    ShowAnswer();
    return 0;
}