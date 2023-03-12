#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 특별할것 없는 다익스트라 문제이다.
// 우선순위큐를 이용하여 현재 최소값보다 크다면 무시하고 그렇지 않다면 갈수 있는 모든곳을 통해
// 다른곳의 최소값을 구해나간다.

vector<vector<pair<int, int>>> board;
const int MAX_NUM = 987654321;
int N, M, from, to;

void DK()
{
    vector<int> answer(N + 1, MAX_NUM);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que; // 거리, 위치.
    que.push(make_pair(0, from));

    while (!que.empty())
    {
        int cost = que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > answer[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            if (cost + len < answer[there])
            {
                answer[there] = cost + len;
                que.push(make_pair(answer[there], there));
            }
        }
    }

    cout << answer[to] << '\n';
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
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
    }
    cin >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}