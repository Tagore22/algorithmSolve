#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 그래프 탐색 문제이다. 1번부터 시작할때 가장 먼 위치의 길이와 가장 먼 위치들의 수와, 가장 먼 위치들중
// 수가 가장 작은 번호를 출력하여야 한다. 다익스트라 알고리즘으로 풀면 어렵지 않다.
// 문제의 큰 틀은 다음과 같다.

// 1. 다익스트라 알고리즘으로 각 위치별 길이를 갱신해나간다.
// 2. 순회 도중 가장 먼 위치값 max_num을 갱신해 나간다.
// 3. 순회가 끝나면 1번부터 N번까지 다시 순회를 하며 가장 첫번째로 max_num을 지니는 값 ans을 찾는다.
// 그 후 계속 N까지 순회하며 max_num의 값을 갖는 원소들의 수 num을 찾는다.
// 4. 순서대로 ans, max_num, num을 출력한다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> way;
int N, M;

// 다익스트라 알고리즘을 구현한 함수.
void DK()
{
    priority_queue<pair<int, int>> que; // 거리, 위치.
    que.push(make_pair(0, 1));
    vector<int> dis(N + 1, 987654321);
    dis[1] = 0;
    int max_num = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // 새로 찾은 길이가 기존의 길이보다 길다면 무시한다.
        if (cost > dis[here])
            continue;

        // 현재 위치에서 갈수 있는 모든곳을 가본다.
        for (int i = 0; i < way[here].size(); ++i)
        {
            int there = way[here][i];
            // 현재 길이가 기존의 길이보다 가깝다면 갱신한다.
            if (dis[there] > cost + 1)
            {
                dis[there] = cost + 1;
                // 상술한 2번. 최대길이 max_num을 갱신한다.
                max_num = max(max_num, dis[there]);
                que.push(make_pair(-dis[there], there));
            }
        }
    }

    bool isfind = false;
    int num = 0, ans;
    for (int i = 1; i <= N; ++i)
    {
        if (dis[i] == max_num)
        {
            // 상술한 3번중 max_num의 값을 가지는 값 num의 수를 갱신한다.
            ++num;
            if (!isfind)
            {
                // 상술한 3번중 가장 첫번째로 max_num을 가지는 값 ans을 찾는다.
                ans = i;
                isfind = true;
            }
        }
    }

    cout << ans << ' ' << max_num << ' ' << num << '\n';
}

void MakeAnswer()
{
    //여기서 bfs 시작.
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    way.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        way[from].push_back(to);
        way[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}