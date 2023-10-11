#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// 16947번의 더 나은 풀이.
// 우선 첫째로 실수했던것은 사이클의 개수를 파악하지 못한것이다.
// 주어지는 문제에서 사이클은 1개뿐이다. 이전에 풀때에는 사이클이 몇개인지 몰라서
// DFS를 1 ~ N개까지 모두 순회했었다.

// 두번째로 실수한것은 BFS탐색의 시작점이다.
// 사이클이 아닌곳에서 사이클까지의 이동은 시작점을 알아야만 한다.
// 하지만 사이클인 곳에서 사이클이 아닌곳까지의 이동은 시작점을 몰라도 된다.

// 이 2가지가 아주 큰 성능저하를 일으켰다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
bool isCircle[3001], visit[3001];
int parent[3001], answer[3001];
int N, start;
bool isfind = false;

// 순환을 찾는 함수.
void FindCircle(int here, int prev)
{
    visit[here] = true;

    for (int there : board[here])
    {
        // 사이클은 1개뿐이기에 이미 찾았다면 모든 DFS를 무시한다.
        if (isfind)
            return;

        if (visit[there])
        {
            // 다음 정점이 이미 방문한 곳이라면 현재 사이클을 이룬다.
            if (prev != there)
            {
                // 현재부터 다음 정점(시작점)까지 모두 사이클임을 갱신하고 탈출한다.
                int p = here;
                while (p != there)
                {
                    isCircle[p] = true;
                    p = parent[p];
                }
                isCircle[p] = true;
                isfind = true;
                return;
            }
        }
        // 그렇지 않을 경우 방문 순서를 갱신하고 재귀를 호출한다.
        else
        {
            parent[there] = here;
            FindCircle(there, here);
        }
    }
}

// 각 사이클인 정점에서 사이클이 아닌 정점까지의 거리를 계산하는 함수.
void Findlen()
{
    queue<pair<int, int>> que; // 위치, 거리.
    // 위 상술하였듯 사이클인 정점에서 사이클이 아닌 곳까지의 거리를 계산하는 것이 더 편한다.
    for (int i = 1; i <= N; ++i)
    {
        if (isCircle[i])
        {
            que.push(make_pair(i, 0));
            visit[i] = true;
        }
    }

    while (!que.empty())
    {
        int here = que.front().first;
        int cost = que.front().second;
        que.pop();

        for (int there : board[here])
        {
            // 현재 방문한 정점은 사이클인 정점이거나 혹은 이미 거리를 계산한 정점이기에 무시한다.
            if (visit[there])
                continue;

            // 거리를 계산해주고 방문 여부(계산 여부)를 갱신하고 다음 정점을 위에 큐에 넣는다.
            answer[there] = cost + 1;
            visit[there] = true;
            que.push(make_pair(there, answer[there]));
        }
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    FindCircle(1, -1);

    memset(visit, false, sizeof(visit));
    Findlen();
    for (int i = 1; i <= N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    memset(isCircle, false, sizeof(isCircle));
    int from, to;
    for (int i = 0; i < N; ++i)
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