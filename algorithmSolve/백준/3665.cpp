#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> board;
vector<int> team, answer, link;
int n, m;

void MakeGraph()
{
    board.assign(n, vector<bool>(n, false));
    link.assign(n, 0);
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            board[team[i] - 1][team[j] - 1] = true;
            ++link[team[j] - 1];
        }
}

void ShowAnswer()
{
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (link[i] == 0)
            que.push(i);

    answer.clear();
    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        answer.push_back(here + 1);

        for (int there = 0; there < n; ++there)
            if (board[here][there])
            {
                --link[there];
                if (link[there] == 0)
                    que.push(there);
            }
    }
    if (answer.size() != n)
        cout << "IMPOSSIBLE";
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << ' ';
    cout << '\n';
}

int main() //방향 그래프, 정점의 번호는 1번부터 n-1, 위상정렬이 제대로 되지 않을 경우도 있음
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i)
    {
        cin >> n;
        team.assign(n, 0);
        for (int j = 0; j < n; ++j) // 여기서 미리 그래프를 만들어 놓는다.
            cin >> team[j];
        MakeGraph();
        cin >> m;
        for (int j = 0; j < m; ++j) // 여기서 그래프를 수정한다.
        {
            int a, b;
            cin >> a >> b;
            if (board[a - 1][b - 1])//a가 우위였다면
            {
                board[a - 1][b - 1] = false;
                board[b - 1][a - 1] = true;
                ++link[a - 1];
                --link[b - 1];
            }
            else
            {
                board[b - 1][a - 1] = false;
                board[a - 1][b - 1] = true;
                ++link[b - 1];
                --link[a - 1];
            }
        }
        ShowAnswer();
    }
    return 0;
}