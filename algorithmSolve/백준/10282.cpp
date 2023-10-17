#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 주어지는 시작점부터 접근 가능한 정점들의 최단 거리증 가장 큰값을 구하는 문제다.
// 다익스트라를 이용하면 되는데 후술할 한가지 실수 때문에 조금 헤맸다.
// 구현 자체는 어렵지 않기에 문제될것은 딱히 없다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<pair<int, int>>> board;
int T, N, D, C;

// 다익스트라 알고리즘 구현 함수.
void DK()
{
    // 거리가 짧은 것들을 먼저 탐색하기 위한 우선순위 큐.
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, C));
    vector<int> dis(N + 1, 987654321);
    dis[C] = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // 만약 here까지의 거리 cost가 기존 최단거리보다 길다면 무시한다.
        if (cost > dis[here])
            continue;

        // here에서 도달할수 있는 모든 정점을 순회한다.
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            // 여기가 바로 그 실수한 부분이다. 
            // 새로 구한값이 기존값보다 같거나 짧다면 실행하는 줄 알았는데 짧아야지만 실행하는 것이었다.
            // 따라서 기존값보다 크거나 같다면 무시해야한다.
            if (cost + len >= dis[there])
                continue;

            // 기존값을 현재값으로 갱신하고 거리와 정점을 큐에 넣는다.
            dis[there] = cost + len;
            que.push(make_pair(-dis[there], there));
        }
    }

    // 모든 정점을 순회하며 거리가 987654321이라면 무시하고
    // 그렇지 않다면 정점의 수를 1 증가시키며 그 거리값들을 비교한다.
    // 여기서 987654321로 해도 되는 이유는 최대 컴퓨터의 개수가 10000이고 최대 거리가
    // 1000 이기에 모든 정점을 거쳐 맨 마지막 정점에 도달해도 그 거리가 1000만이기 때문이다.
    // 따라서 1000만을 넘는 수로 체크한다면 문제 없다.(확인해봄)
    pair<int, int> answer = make_pair(0, 0);
    for (int i = 1; i <= N; ++i)
    {
        // 도달하지 못한다면 무시한다.
        if (dis[i] == 987654321)
            continue;

        // 그렇지 않다면 감염된 컴퓨터의 개수를 1 증가시키고
        // 가장 큰 시간을 구한다.(모두 감염되야 하므로 그들중 가장 오래걸리는 시간을 알아야한다).
        ++answer.first;
        answer.second = max(answer.second, dis[i]);
    }

    cout << answer.first << ' ' << answer.second << '\n';
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> D >> C;
        board.resize(N + 1, vector<pair<int, int>>());
        int a, b, s;
        for (int i = 0; i < D; ++i)
        {
            cin >> a >> b >> s;
            board[b].push_back(make_pair(a, s));
        }
        DK();

        for (int i = 0; i <= N; ++i)
            board[i].clear();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}