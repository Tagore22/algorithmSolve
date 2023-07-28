#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 다익스트라를 이용한 연쇄문제로 종만북에서 풀어본것 같은데 자세히는 기억이 나질 않았다.
// 다익스트라 자체는 명확했으나 출력해야할 연결들을 어떻게 구현해야할지 애매했다.
// 정답은 간단한데 그 어떤 연결이든 시작과 끝이 있다는 것이다.
// 문제의 큰틀은 다음과 같다.

// 1. 새로운 연결망을 구축해야하는데 슈퍼컴퓨터(1번 컴퓨터)와 모든 컴퓨터는 직, 간접적으로 연결되어 있어야 한다.
// 2. 다만 새로운 연결망이 기존의 연결속도보다 느리면 안되므로 최소 가중치를 선택하여 가장 빠르게 연결되어있어야한다.
// 3. 모든 컴퓨터들은 서로 연결되어 있어야 하는데 1번에서 슈퍼컴퓨터가 모든 컴퓨터들과 연결되어 있으므로
// 이미 모든 컴퓨터들은 연결되어 있다.
// 4. 이러한 상태를 가능하게 하는 최소한의 연결들을 출력해야 한다.

// 슈퍼 컴퓨터가 다른 모든 컴퓨터들과 연결되는 최소 연결 개수는 당연히 N - 1이다.
// 각각 하나의 연결씩으로 연결되어 있으면 되기 때문이다.
// 또한 위 상술했던 연결들은 시작과 끝을 저장해 놓았다가 한번에 모든 연결들을 출력해주면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[1001];
int ans[1001];
int N, M;

// 다익스트라 알고리즘 구현 함수.
void DK()
{
    vector<int> dist(N + 1, 987654321);
    dist[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // cost가 현재 here까지의 최소길이보다 길다면 무시한다.
        if (dist[here] < cost)
            continue;

        // here에서 갈수 있는 모든 곳을 가본다.
        for (auto& next : board[here])
        {
            int there = next.first;
            int len = next.second;

            // cost + len이 기존의 there까지의 최소길이보다 짧다면 갱신한다.
            if (cost + len < dist[there])
            {
                dist[there] = cost + len;
                que.push(make_pair(-dist[there], there));
                // 슈퍼컴퓨터에서 there까지의 연결은 here을 거쳐서 연결된다.
                ans[there] = here;
            }
        }
    }
}

void MakeAnswer()
{
    DK();
    // 위 상술하였듯 모든 최소 연결은 N - 1이다.
    cout << N - 1 << '\n';
    // 모든 연결들을 순회하며 시작과 끝을 출력한다.
    for (int i = 2; i <= N; ++i)
        cout << i << ' ' << ans[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}