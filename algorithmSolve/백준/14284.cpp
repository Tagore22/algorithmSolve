#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 간선 없이 정점만 있는 그래프와 간선 리스트가 주어질때 간선을 한개씩 추가하여 S와 T가 이어지는
// 가중치 합의 최소값을 구해야하는 문제다. 즉 S에서 T의 최소 경로를 구하면 된다. 가중치들의 최소값이
// 1이므로 음수는 없기에 다익스트라로 구현하였다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[5001];
int N, M, from, to;
const int MAXNUM = 987654321;

// 다익스트라 알고리즘을 구현하는 함수
void DK()
{
    vector<int> dist(N + 1, MAXNUM);
    dist[from] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, from));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > dist[here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int next = cost + p.second;

            if (dist[there] > next)
            {
                dist[there] = next;
                que.push(make_pair(-next, there));
            }
        }
    }
    cout << dist[to] << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}