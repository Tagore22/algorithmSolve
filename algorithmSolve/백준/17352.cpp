#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 두군데로 나누어진 정점들중에서 하나씩 출력하면 되는 문제다. 예전에 종만북에서 DFS 할때 이와 비슷한걸
// 공부했던다. BFS로도 똑같이 가능하기 때문에 1번에서 BFS를 시작하고 N번까지 순회를 돌며 아직 방문하지
// 않은 첫번째 정점을 찾으면 되었다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board[300001];
bool visit[300001] = { false, };
int N;

void BFS(int from)
{
    queue<int> que;
    que.push(from);
    visit[from] = true;

    // 정점 from에서 방문할수 있는 모든 정점들을 찾는다.
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto& there : board[here])
        {
            if (visit[there])
                continue;

            visit[there] = true;
            que.push(there);
        }
    }
}

void MakeAnswer()
{
    BFS(1);
    for (int i = 1; i <= N; ++i)
    {
        // 1번 정점에서 도달할수 없었던 첫번째 정점을 찾아 출력한다.
        if (!visit[i])
        {
            cout << 1 << ' ' << i << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int from, to;
    for (int i = 0; i < N - 2; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}