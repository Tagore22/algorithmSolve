#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 어려운 문제였다. 문제조차 제대로 이해가 가질 않았는데 지문을 보면
// i, M + i, 2M + 1 ~ 라고 나와있다. 이 부분을 처음에는 첫번째 신호가 0에
// 켜지고 1분 후에 꺼진후 M분이 지난 후에 두번째 신호가 켜지는 방식인 줄 알았으나
// 그냥 0분에 켜지고 1분후에 꺼진후 곧바로 다음 신호가 켜지고 다시 1분후에 꺼지는
// 방식이었다. 말 그대로 0번 신호가 0, M + 0, 2M + 0인 방식이다. 
// 그 후에는 1번부터 시작할때 N번의 최단 거리를 구해야했는데 기존의 방식처럼 단순히 거리와
// 위치만 필요한게 아니라 주기와 이전 신호까지 알아야했다. 이번에 건너려는 신호가
// 이전에 건넜던 신호보다 작다면 주기가 증가하여 그만큼 시간이 증가하기 때문이다.
// 따라서 구조체를 사용하여 상술한 4가지 변수를 구현하였고, 우선순위 큐를 이용하여야했기에
// 연산자 오버로딩까지 구현했다.
// 또한, N과 M의 최대값이 각각 10만, 70만이기에 최대값은 99999 * 70만 + 699999으로 int값을
// 벗어나기에 long long을 이용했다.

// 자세한 설명은 주석으로 남긴다.

// 총 시간, 현 위치, 몇번째 주기인가, 이전에 건넌 길의 번호
struct pos
{
    // time은 최대값이 int값을 벗어나고 num은 후에 time을 이용하는 곱셈에 사용되기에
    // long long으로 구현하였다.
    long long time;
    int here;
    long long num;
    int prev;

    bool operator<(const pos& lhs) const
    {
        return time < lhs.time;
    }
};

int N, M;
vector<pair<int, int>> board[100001];

void DK()
{
    vector<long long> dist(N + 1, 9223372036854775806);
    dist[1] = 0;
    priority_queue<pos> que;
    que.push(pos{ 0, 1, 0, -1 });

    while (!que.empty())
    {
        long long time = -que.top().time;
        int here = que.top().here;
        int num = que.top().num;
        int prev = que.top().prev;
        que.pop();

        if (time > dist[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int next = board[here][i].second;
            // 상술한대로 현재 신호가 이전 신호보다 작다면 주기를 증가시켜야 한다.
            long long newnum = prev > next ? num + 1 : num;
            // 주기 * M + 현재 신호값이 점화식이 된다.
            long long cost = newnum * M + next;
            if (cost < dist[there])
            {
                dist[there] = cost;
                que.push(pos{ -dist[there], there, newnum, next });
            }
        }
    }
    // 마지막에 건너는 시간 1분을 추가해주어야 한다.
    cout << dist[N] + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        board[from].push_back(make_pair(to, i));
        board[to].push_back(make_pair(from, i));
    }
    DK();
    return 0;
}