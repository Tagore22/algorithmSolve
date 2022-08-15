#include <iostream>
#include <vector>
#include <queue>

using namespace std; //양방향 그래프, 정점은 1번부터 N번까지.

vector<vector<pair<int, int>>> board;
int N, M;

//기존의 시간복잡도였던 V의제곱 + E로는 문제를 해결하지 못하여 우선순위 큐를 이용하는 다익스트라 형식의 프림을 구현
//하였다. 처음 해보는건데 생각할 거리도 더 적어서 더 쉽고 빠른것 같아 매우 만족스럽다.

void Prim()
{
    priority_queue<pair<int, int>> que;
    for (int i = 0; i < board[1].size(); ++i)
    {
        int there = board[1][i].first;
        int cost = board[1][i].second;
        que.push(make_pair(-cost, there));
    }
    vector<bool> check(N + 1, false);
    check[1] = true;
    int answer = 0;
    int max_cost = 0;
    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (check[here])
            continue;

        check[here] = true;
        answer += cost;
        max_cost = max(max_cost, cost);//프림을 구하는데에는 전혀 필요 없으나, 마을을 나눌 간선을 찾기 위해 추가됨.
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            if (!check[there])
                que.push(make_pair(-len, there));
        }
    }
    cout << answer - max_cost << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
}

int main()
{
    Input();
    Prim();
    return 0;
}