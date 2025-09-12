#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// 풀이.
// 처음에는 DFS를 통해서 가능한 모든 경로를 순회하며 가중치를 모아 내림차순으로 정렬을 한후에
// N번째 값들의 최소값을 출력하는 식으로 구현을 하였다. 하지만 큰 실수였는데 DFS의 시간복잡도는
// E + V고 주어지는 E는 1만, V는 1000이기 때문에 너무 간단한거 아닌가 하는 의문도 들었다.
// 실제로는 기본 DFS나 BFS는 단순 순회용도이기 때문에 똑같은 정점을 방문할 일이 없다.
// 하지만 이번 경우에는 모든 경우의 수를 탐색해야 하기에 어떠한 경로에서 방문한 정점을
// 다른 경로에서 다시 방문할 경우가 생긴다. 따라서 DFS의 시간복잡도인 E + V는 이 경우에
// 전혀 성립되지 않고 어마무시한 연산량으로 인해 시간초과가 났다. 진짜 풀이는 이분 탐색 +
// 0-1 BFS를 통한 것인데 이분 탐색으로 BFS 순회의 횟수를 최소한으로 하고, BFS는 이분 탐색에서
// 얻은 중간값보다 큰 가중치들을 만나는 지를 확인하여 이분 탐색의 중간값을 계산해나가는 것이다.

// 자세한 설명은 주석으로 남긴다.

int N, P, K;
vector<pair<int, int>> board[1001];

// maxcost보다 큰 가중치를 만나는 횟수를 반환하는 함수.
bool BFS(int maxcost)
{
    // 0-1 BFS를 구현하기 위해 deque를 활용.
    deque<int> que;
    que.push_back(1);
    // 최소값들의 배열 dist는 maxcost보다 큰 가중치들의 최소값이다.
    vector<int> dist(N + 1, 1e9);
    dist[1] = 0;

    while (!que.empty())
    {
        int here = que.front();
        que.pop_front();

        for (auto next : board[here])
        {
            int there = next.first;
            int cost = next.second;
            int add = cost > maxcost ? 1 : 0;
            if (dist[there] > dist[here] + add)
            {
                dist[there] = dist[here] + add;
                // 0-1 BFS의 구현. 비용이 0이라면 앞에서 빠르게 처리하고
                // 비용이 1이라면 뒤에서 나중에 처리한다.
                if (add)
                    que.push_back(there);
                else
                    que.push_front(there);
            }
        }
    }
    return dist[N] <= K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> P >> K;
    for (int i = 0; i < P; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
    // 범위값도 주의해야한다. while(from <= to)를 이용한 구현에서는
    // 끄트머리값에 대응하기 위해 실제 최소값 - 1 ~ 최대값 + 1을 범위로 한다.
    int from = 0, to = 1000001, answer = -1;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (BFS(mid))
        {
            answer = mid;
            to = mid - 1;
        }
        else
        {
            from = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}