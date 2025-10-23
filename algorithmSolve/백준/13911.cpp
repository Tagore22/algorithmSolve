#include <iostream>
#include <queue>
#include <vector>

// 풀이.
// 어려운 문제였다. 요약하자면 여러 쌍의 최단거리를 이용해야하기에 처음에는 플로이드 워셜
// 알고리즘을 떠올렸으나, 정점의 최대 개수가 만개였다. 플로이드 워셜은 정점 개수의
// 3중 for문을 이용하기 때문에 시간내에 답을 계산하지 못할게 뻔했다. 그래서 멀티 다익스트라를
// 사용해야했다. 기존의 다익스트라와의 차이점은 dist 배열인데 원래는 한개의 시작점으로부터
// 각 정점의 최단거리를 저장한다면, 멀티 다익스트라에서는 어떤 시작점인지는 알 수 없으나
// 어쨌든 어떤 시작점으로부터의 최단거리를 저장하는 차이점이 있다. 이것만 알면 충분히
// 풀 수 있는 문제였다.

// 자세한 설명은 주석으로 남긴다.

using namespace std;

int V, E, M, S, x, y;
// 각 정점들간의 연결을 벡터로 구현.
vector<pair<int, int>> dist[10001];
vector<int> mac, star, macdist, stardist;

// 멀티 다익스트라 구현 함수.
void Dijkstra(const vector<int>& srt, bool ismac)
{
    priority_queue<pair<int, int>> que;
    // 각 정점은 1번부터 V번까지 존재하기에 벡터를 V + 1개로 구현해야한다.
    vector<int> mindist(V + 1, 100000001);
    // 시작값들을 큐에 넣는다.
    for (const auto& n : srt)
    {
        que.push(make_pair(0, n));
        mindist[n] = 0;
    }

    // 상술하였듯 dist 배열이 기존과는 다른 값들을 가진다는 점을 제외하고는
    // 일반적인 다익스트라와 다를 게 없다.
    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > mindist[here])
            continue;

        for (int i = 0; i < dist[here].size(); ++i)
        {
            int there = dist[here][i].first;
            int len = dist[here][i].second;
            if (len + cost < mindist[there])
            {
                mindist[there] = len + cost;
                que.push(make_pair(-mindist[there], there));
            }
        }
    }
    // 스타벅스용과 맥도날드용을 따로 구현하지 않기 위해
    // 2개의 매개변수를 이용하였고 dist 배열도 범용적으로 구현했기에
    // 따로 저장을 해야한다.
    if (ismac)
        macdist = mindist;
    else
        stardist = mindist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from].push_back(make_pair(to, cost));
        dist[to].push_back(make_pair(from, cost));
    }
    cin >> M >> x;
    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        mac.push_back(num);
    }
    cin >> S >> y;
    for (int i = 0; i < S; ++i)
    {
        int num;
        cin >> num;
        star.push_back(num);
    }
    Dijkstra(mac, true);
    Dijkstra(star, false);
    int answer = 200000001;
    for (int i = 1; i <= V; ++i)
    {
        // 각 dist[i]가 0이라면 i에서 i로 이동한 경우인데 이는 무시되어야 하는 상황이기에
        // 따로 if문에서 걸러야했다.
        if (macdist[i] == 0 || stardist[i] == 0 || macdist[i] > x || stardist[i] > y)
            continue;
        answer = min(answer, macdist[i] + stardist[i]);
    }
    cout << (answer != 200000001 ? answer : -1) << '\n';
    return 0;
}