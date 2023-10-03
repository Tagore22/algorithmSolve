#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// 풀이.
// 사이클 순환을 찾는 문제다.
// 문제의 큰틀은 다음과 같다.

// 1. DFS를 이용하여 모든 정점들중 사이클을 가지는 정점을 찾는다.
// 2. 사이클을 갖지 않는 정점은 BFS를 이용하여 가장 가까운 사이클을 갖는 정점과의 위치를 찾는다.

// 단지 이뿐이다. 다만 나머지 세세한 부분을 처리하는게 번거로웠던 문제같다.
// 훨씬 더 빠른 풀이가 있는 것 같은데 지금 상태로는 무리같아 다음으로 남긴다.

// 자세한 설명은 주석으로 남긴다.

struct point
{
    // 시작 위치, 현재 위치, 이전 위치, 거리.
    int s;
    int h;
    int p;
    int l;
};

vector<vector<int>> board;
bool isCircle[3001], visit[3001];
int parent[3001], answer[3001];
int N, start;

// 사이클을 갖는 정점인지 확인하는 함수.
void FindCircle(int here, int prev)
{
    visit[here] = true;

    // 현재 정점 here에서 이동할수 있는 모든 정점을 순회한다.
    for (int there : board[here])
    {
        // 이전에 왔던 정점이 아니며 다음 정점이 시작점이라면 here은 사이클을 갖는다.
        if (prev != there && there == start)
        {
            // 여태까지 지나왔던 모든 정점들 역시 사이클을 갖는다.
            while (parent[here] != -1)
            {
                isCircle[here] = true;
                here = parent[here];
                answer[here] = 0;
            }
            isCircle[here] = true;
            answer[here] = 0;
            return;
        }
        // 그렇지 않고 이미 방문한 곳이라면 무시한다.
        if (visit[there])
            continue;

        // 지나왔던 정점들을 갱신하고 재귀호출을 한다.
        parent[there] = here;
        FindCircle(there, here);
    }
}

// 사이클을 가지지 않는 정점들중 사이클을 갖는 가장 가까운 정점을 찾는 함수.
void Findlen()
{
    queue<point> que; // 시작 위치, 현재 위치, 이전 위치, 거리.
    for (int i = 1; i <= N; ++i)
    {
        if (!isCircle[i])
        {
            que.push(point{ i, i, -1, 1 });
        }
    }

    while (!que.empty())
    {
        int s = que.front().s;
        int here = que.front().h;
        int prev = que.front().p;
        int len = que.front().l;
        que.pop();

        // 현재 정점 here에서 이동할수 있는 모든 정점을 순회한다.
        for (int there : board[here])
        {
            // 다음 정점이 사이클을 갖는다면 거리를 갱신하고 탈출한다.
            if (isCircle[there])
            {
                answer[s] = len;
                break;
            }
            if (there == prev)
                continue;

            que.push(point{ s, there, here, len + 1 });
        }
    }
}

void MakeAnswer()
{
    // 여기 이부분이 속도를 느리게 하는 부분같다. 굳이 N번의 DFS를 순회하지 않아도 되는듯.
    for (int i = 1; i <= N; ++i)
    {
        if (isCircle[i])
            continue;

        memset(visit, false, sizeof(visit));
        parent[i] = -1;
        start = i;
        FindCircle(i, -1);
    }

    // 사이클을 가지지 않는 모든 정점들의 거리를 찾는다.
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