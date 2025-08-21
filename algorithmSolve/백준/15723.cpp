#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> board[26];
int N, M;

bool BFS(int from, int to)
{
    bool visit[26] = { false, };
    visit[from] = true;
    queue<int> que;
    que.push(from);

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        if (here == to)
            return true;

        for (auto& there : board[here])
        {
            if (!visit[there])
            {
                visit[there] = true;
                que.push(there);
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char from, to;
        string str;
        cin >> from >> str >> to;
        board[from - 'a'].push_back(to - 'a');
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        char from, to;
        string str;
        cin >> from >> str >> to;
        cout << (BFS(from - 'a', to - 'a') ? 'T' : 'F') << '\n';
    }
    return 0;
}