#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 어렵기도 했지만 내가 잘못생각해서 한참 헤맨 문제다. 18시까지 풀었다. T^T.
// 우선순위 큐를 이용해서 문제를 푸는것 맞았다. 다만 2가지 조건을 하나의 큐에서 풀려고 했는데
// 그건 불가능한 일이었고 큐도 2개로 나누어야했다. 풀이가 길어서 주석으로 나누어쓰겠다.
// 또한, 이것저것 되짚어볼점이 많았던 문제였다.

// 자세한 설명은 주석으로 남긴다.

struct pos
{
    // 각각 id, 걸리는 시간(물건의 수), 계산대의 위치.
    int id;
    long long num;
    int w;
};

// 계산대에서 나갈때의 정렬. 우선순위 큐에서 사용되기 때문에 통상 정렬의
// 정반대로 되어야 한다.
struct out_cmp
{
    bool operator()(const pos& a, const pos& b)
    {
        // 시간이 다르다면 시간이 큰것을 앞에 둔다. 상술했듯 우선순위큐라서 정반대다.
        if (a.num != b.num)
            return a.num > b.num;
        // 시간이 같다면 계산대가 작은것을 앞에 둔다. 마찬가지로 정반대다.
        else
            return a.w < b.w;
    }
};

// 계산대로 들어갈때의 정렬. 우선순위 큐에서 사용되기 때문에 통상 정렬의
// 정반대로 되어야 한다.
struct in_cmp
{
    bool operator()(const pos& a, const pos& b)
    {
        // 시간이 다르다면 시간이 큰것을 앞에 둔다. 상술했듯 우선순위큐라서 정반대다.
        if (a.num != b.num)
            return a.num > b.num;
        // 시간이 같다면 계산대가 큰것을 앞에 둔다. 마찬가지로 정반대다.
        else
            return a.w > b.w;
    }
};

int N, K, id, num;

void MakeAnswer()
{
    // 각각 들어갈때의 큐와 나갈때의 큐.
    priority_queue<pos, vector<pos>, in_cmp> in_que;
    priority_queue<pos, vector<pos>, out_cmp> out_que;

    // 안의 큐에 시간과 id는 0으로, 계산대의 값만 넣어놓는다.
    // 원래 계산후의 시간은 빠져나간 값 이외의 값들을 모두 제거해야하나 그러면 일일이 큐를 순회시켜야한다.
    // 그렇지 않고 새로 들어올 값에 기존값을 더해 순회를 막는다. 다만 기존 값을 0으로 했기에 추가적으로 더해지지는
    // 않으며 계산대값만 수정된다.
    // 여기서 치명적인 실수를 하나 했는데 K까지 순회를 N으로 잘못 구현했었다. 후....
    for (int i = 0; i < K; ++i)
        in_que.push(pos{ 0, 0, i });

    for (int i = 0; i < N; ++i)
    {
        cin >> id >> num;
        pos prev = in_que.top();
        in_que.pop();

        // id는 변함이 없으며, 상술한대로 추가되는 값의 시간에 기존의 값의 시간을 추가해서 시간의 경과를 갱신한다.
        // 마찬가지로 계산대 역시 변화는 없다.
        in_que.push(pos{ id, num + prev.num, prev.w });
        out_que.push(pos{ id, num + prev.num, prev.w });
    }

    long long answer = 0, idx = 1;
    // 나가는 큐에 담긴것들을 순차적으로 계산하여 출력한다.
    while (!out_que.empty())
    {
        answer += out_que.top().id * idx;
        ++idx;
        out_que.pop();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}