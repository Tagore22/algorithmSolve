#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 정점 v에서 시작하여 유사도가 K이상의 해당하는 영상의 개수를 출력하는 문제다. 유사도는
// 기존의 유사도와 새로운 영상의 유사도중 더 적은 수로 계산할 수 있다. BFS를 이용하여
// 어렵지 않게 계산할수 있다. 예전에 떠오르지 않아서 넘겼던 문제인데 잘 풀어낸듯 하다.

// 자세한 설명은 주석으로 남긴다.

int N, Q;
const int MAXNUM = 1000000001;
vector<pair<int, int>> board[5001];

void BFS(int limit, int from)
{
    queue<pair<int, int>> que;
    // 유사도의 초기값은 매우 큰값으로 해야한다. 그래야 min()에 의해 현재 유사도가
    // 문제없이 계산될수 있기 때문이다.
    que.push(make_pair(from, MAXNUM));
    bool visit[5001] = { false, };
    visit[from] = true;
    int answer = 0;

    while (!que.empty())
    {
        int here = que.front().first;
        int l = que.front().second;
        que.pop();

        // 현재 영상과 연결된 모든 정점들을 순회하며 유사도가 K보다 크거나 같은
        // 정점들을 큐에 넣으며 이때 출력값 answer을 1씩 증가시키고 방문 여부를
        // 수정한다.
        for (auto& next : board[here])
        {
            int there = next.first;
            int usa = next.second;
            int nextl = min(usa, l);
            // 재방문이거나, 유사도가 K보다 작을때에는 무시한다.
            if (visit[there] || nextl < limit)
                continue;
            ++answer;
            que.push(make_pair(there, nextl));
            visit[there] = true;
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    int limit, from;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> limit >> from;
        BFS(limit, from);
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    int from, to, u;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to >> u;
        board[from].push_back(make_pair(to, u));
        board[to].push_back(make_pair(from, u));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}