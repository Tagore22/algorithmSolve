#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 처음에 읽었을 땐 잘 이해가 가지 않았으나 결과적으로 a에서 b로 가는
// 최단거리를 구하는 문제다.

int a, b, N, M;
vector<int> board[1001];
bool visit[1001] = { false, };

void BFS()
{
    queue<int> que;
    que.push(a);
    visit[a] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            if (here == b)
            {
                cout << answer << '\n';
                return;
            }

            for (auto& there : board[here])
            {
                if (visit[there])
                    continue;

                que.push(there);
                visit[there] = true;
            }
        }
    }
    cout << -1 << '\n';
}

void Solve()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}