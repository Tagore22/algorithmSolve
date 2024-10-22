#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 설명이 많고 복잡한데 결과적으로 시작점에서 끝점까지 이동하는 거리의 총합중에서 가장 긴거리를 뺀값을 출력하면 된다.
// 그러기 위해서는 que에 현재 위치와 총합 이외의 현재까지 이동중 가장 긴거리까지 가지고 있어야했으므로 새로운 구조체를
// 구현했다. 나머지는 그리 어려울게 없다.

// 자세한 설명은 주석으로 남긴다.

struct ver
{
    // 각각 현위치, 가장 길었던 거리값, 총 이동값.
    int where;
    int maxway;
    int sum;
};

vector<pair<int, int>> board[100001];
int N;
pair<int, int> pos;

void BFS()
{
    queue<ver> que;
    // 이부분에서 실수를 했는데 기존에는 가장 길었던 이동값을 -1로 초기화했었다. 하지만
    // N이 1이거나 시작점 == 끝점인 경우를 대입하면 바로 0 - (-1)이 되어 0이 아닌 1이 되어버린다.
    // 따라서 0으로 초기화해야만 한다.
    que.push(ver{ pos.first, 0, 0 });
    bool visit[100001] = { false, };
    visit[pos.first] = true;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int where = que.front().where;
            int maxway = que.front().maxway;
            int sum = que.front().sum;
            que.pop();

            // 만약 끝점에 도달했다면 총 이동값 - 가장 길었던 거리값을 출력하고 탈출한다.
            if (where == pos.second)
            {
                cout << sum - maxway << '\n';
                return;
            }

            for (auto& cur : board[where])
            {
                int next = cur.first;
                // 이번 정점이 도달하지 않았다면 이동거리를 가장 길었던 이동값과 비교하여 갱신하고
                // 총합에 이번 이동거리를 더하여 큐에 넣는다. 또한 방문여부 역시 갱신한다.
                if (!visit[next])
                {
                    int cost = cur.second;
                    int nextmax = max(maxway, cost);
                    que.push(ver{ next, nextmax, sum + cost });
                    visit[next] = true;
                }
            }
        }
    }
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> pos.first >> pos.second;
    int from, to, dis;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to >> dis;
        board[from].push_back(make_pair(to, dis));
        board[to].push_back(make_pair(from, dis));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}