#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 문제에서는 더 먼 길로 돌아갈지어도, 더 최소한의 여물(가중치)를 필요로 했으므로
// 다익스트라 알고리즘을 사용해야 했다. 금방 떠올라서 다행이었다.
// 문제 자체가 그냥 다익스트라를 거의 베끼기만 하면 되는 문제라 크게 어려울것이 없다.
// 다만 다익스트라 알고리즘에서 헷갈렸던 2가지를 잘 기억해두어야 한다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<pair<int, int>>> board;
int N, M;
const int MAX_NUM = 987654321;

// 다익스트라 순회 함수. 시작점에서 출발하여 도달하는 모든 정점들에서 다시 출발한다.
// 다만 순회전 최소 길이 배열을 만들어두고 최대값으로 초기화하여 매번 정점을 만날때마다
// 그 정점으로의 길이가 최소 길이보다 길거나 같다면 무시한다.
void DK()
{
    vector<int> dis(N + 1, MAX_NUM);
    // 시작점에서 시작점까지의 길이는 0.
    dis[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        // 현재 정점과 시작점으로부터의 길이를 큐에서 빼낸다.
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // 상술하였듯 기존의 최소길이보다 현재 얻어낸 길이가 길거나 같다면 무시한다.
        if (cost > dis[here])
            continue;

        // 현재 정점에서 도달할수 있는 다른 정점들을 모두 순회한다.
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            // 현재 길이 + 현재 정점에서 다른 정점 there까지의 길이가 시작점부터 there까지의 길이
            // dis[there]보다 짧다면 갱신한다. 여기서 <인지 <=인지 헷갈릴때가 있었는데 이럴땐
            // 가중치의 값이 0일때를 생각하면 된다. A -> B가 0이라면 B에 도달하였을때 A를 만나게 되는데
            // 가중치가 0이라서 cost + len과 dis[A]의 값이 같아지게 된다. 여기서 <가 아닌 <=를 사용하게 되면
            // 다시 A로 돌아가기 때문에 <=가 아닌 <를 사용하여야 한다.
            if (cost + len < dis[there])
            {
                dis[there] = cost + len;
                que.push(make_pair(-dis[there], there));
            }
        }
    }

    // 목적지까지의 최소길이를 출력한다.
    cout << dis[N] << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost));
        board[to].push_back(make_pair(from, cost));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}