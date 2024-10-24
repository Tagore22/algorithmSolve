#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 어려운 문제였다. 난이도도 골2고 정답율도 25퍼가 안되었다. 결국 힌트를 살짝 봐야풀수 있었다. 거의 다 왔는데
// 아쉽다. 요약하자면 다익스트라를 이용해서 각 정점에서 각 면접장까지의 최단거리중 가장 큰 것을 찾아야 한다.
// 하지만 실제로 각 정점에서 모두 다익스트라를 사용하면 당연히 시간초과가 난다. 그래서 머리를 써야 하는데
// 이부분이 꽤나 어렵다. 결과적으로 모든 정점에서 면접장으로 도달해야하는데 역발상을 쓰면 면접장에서 모든
// 정점으로 도달한다면 연산을 훨씬 줄일수 있다. 허나 간선이 단방향이기 때문에 면접장에서 출발점까지의 거리는
// 출발점에서 면접장까지의 거리와 다르다. 나는 이부분에서 막혔다. 이때 상술한대로 역발상을 해서 간선의 방향을
// 반대로 바꾸어야한다. 이러면 면접장에서 각 정점으로 가는 방향이 된다. 이것이 첫번째 역발상이다. 
// 두번째는 다익스트라에서 발생하는데 나는 늘 출발점이 하나인 문제만 풀었기 때문에 이번에도 그리 풀었었다.
// 하지만 면접장이 여러개인만큼 출발점을 여러개로 할수도 있다. 이 근거 역시 충분한데 dist는 최단거리를 가지고 있는
// 벡터이며, 단순히 최단거리만을 가지고 있다. 즉, 어떤 면접장에서 출발하던지 어떤 정점까지의 최단거리만을 가지고 있다는
// 것이다. 문제에서 찾고자 하는 어떤 정점에서 가장 가까운 면접장까지의 최단거리와 일맥상통한다. 이것이 두번째 역발상이다.
// 이 2가지를 다익스트라에 대입하여 풀면 된다.

// 자세한 설명은 주석으로 남긴다.

// 각 위치와 거리.
vector<pair<int, int>> board[100001];
// 면접장을 저장하는 배열.
int froms[100000];
int N, M, K;
// 초기화에 사용되는 최대거리.
const long long MAXLONG = 9223372036854775807;

// 각 면접장에서 각 정점까지의 최단거리를 구하는 다익스트라 함수.
void DK()
{
    vector<long long> dist(N + 1, MAXLONG);
    priority_queue<pair<long long, int>> que;
    // 상술한 두번째 역발상. 시작점이 여러개일지라도 각 정점과의 최단거리가 중요하기에
    // 상관없다.
    for (int i = 0; i < K; ++i)
    {
        que.push(make_pair(0, froms[i]));
        dist[froms[i]] = 0;
    }

    // 평범한 다익스트라 알고리즘. 우선순위 큐를 사용하기에 기준이 되는 값이 음수처리 되는 부분을
    // 주의할것.
    while (!que.empty())
    {
        long long cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (dist[here] < cost)
            continue;

        for (auto& next : board[here])
        {
            int there = next.first;
            long long nextcost = cost + next.second;
            if (nextcost < dist[there])
            {
                dist[there] = nextcost;
                que.push(make_pair(-nextcost, there));
            }
        }
    }
    // dist에는 어떤 면접장에서 출발했는지와는 상관없이 각 정점까지의 최단거리가 저장되어 있으므로
    // 이들중 가장 큰값을 출력하면 된다.
    pair<int, long long> answer = make_pair(-1, -1);
    for (int i = 1; i <= N; ++i)
        if (answer.second < dist[i])
            answer = make_pair(i, dist[i]);
    cout << answer.first << '\n';
    cout << answer.second << '\n';
}

void MakeAnswer()
{
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    int from, to, dis;
    for (int i = 0; i < M; ++i)
    {
        // 상술한 첫번째 역발상. 각 도시에서의 출발이 아닌 각 면접장에서의 출발로 연산량을 줄이고
        // 그를 위한 간선의 방향을 반전시킨다.
        cin >> from >> to >> dis;
        board[to].push_back(make_pair(from, dis));
    }
    for (int i = 0; i < K; ++i)
        cin >> froms[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}