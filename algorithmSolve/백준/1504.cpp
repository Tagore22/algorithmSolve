#include <iostream>
#include <vector>
#include <queue> //1번에서 v1, v2에서 v2, v2에서 n번 혹은 1번에서 v2, v2에서 v1, v1에서 n번

using namespace std; //양방향,1번에서 시작, 정점의 번호는 1번부터 n, 주어진 두정점을 반드시 거칠것

vector<vector<pair<int, int>>> board;
vector<bool> check;
const int MAXNUM = 987654321;
int n, e, v1, v2;

int DK(int from, int to)
{
    vector<int> way(n + 1, MAXNUM);
    way[from] = 0;
    check.assign(n + 1, false);
    check[from] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, from));
    while (!que.empty())
    {
        auto now = que.top();
        que.pop();
        int cost = now.first;
        int here = now.second;

        if (cost > way[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            auto next = board[here][i];
            int there = next.first;
            int len = next.second;

            if (way[here] + len < way[there])
            {
                way[there] = way[here] + len;
                que.push(make_pair(way[there], there));
            }
        }
    }
    return way[to];
}

int FindAnswer(int first, int second)
{
    int answer = 0;
    int check = DK(1, first);
    if (check == MAXNUM)
        return -1;
    answer += check;
    check = DK(first, second);
    if (check == MAXNUM)
        return -1;
    answer += check;
    check = DK(second, n);
    if (check == MAXNUM)
        return -1;
    answer += check;
    return answer;
}

void ShowAnswer()
{
    int ans = FindAnswer(v1, v2);
    ans = min(ans, FindAnswer(v2, v1));
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;
    board.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
    ShowAnswer();
    return 0;
}