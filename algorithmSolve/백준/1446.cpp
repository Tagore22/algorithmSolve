#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이
// BFS를 통해서 갈수 있는 모든 상황을 계산한다.

// 1. 지름길을 통해서 갈때.
// 2. 지름길을 통하지 않고 그냥 갈때.

// 주어진 지름길들을 2차원 배열에 저장해놓고 BFS를 0부터 순회하되, 현재 위치에서 지름길을 사용하지 않는 경우를 계산하여 que에 넣고
// 지름길이 존재한다면 모든 지름길을 사용하는 경우 역시 que에 넣어준다. 다만 주의해야할점은 지름길을 사용했을때 도착해야하는 D보다
// 더 갔을 경우는 무시해야한다는 점이다. 그렇기에 que에서 맨앞 원소를 꺼냈을때 현 위치가 D와 같다면 이동한 거리를 최종값 answer와
// 비교하여 최소값을 갱신하고, D보다 크다면 상술하였듯 무시해야한다.

// 분명 중간에 겹치는 부분도 있는데 통과된건 N과 D가 많이 짧아서 그런것 같다.

vector<vector<pair<int, int>>> board; // 도착지점, 거리
int N, D, answer;

void BFS()
{
    answer = D;
    queue<pair<int, int>> que; // 현재지점, 거리
    que.push(make_pair(0, 0));
    while (!que.empty())
    {
        int here = que.front().first;
        int cost = que.front().second;
        que.pop();

        if (here == D) // 도착지점에 도달하였을 경우.
        {
            answer = min(answer, cost);
            continue;
        }
        else if (here > D) // 도착지점보다 더 갔을 경우는 무시해야한다.
        {
            continue;
        }

        for (int i = 0; i < board[here].size(); ++i) // 지름길이 존재한다면 모든 지름길을 가본다.
        {
            int there = board[here][i].first;
            int len = board[here][i].second;
            que.push(make_pair(there, cost + len));
        }

        que.push(make_pair(here + 1, cost + 1)); // 지름길을 아예 쓰지 않았을때.
    }
}

void MakeAnswer()
{
    BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> D;
    board.resize(D, vector<pair<int, int>>());
    for (int i = 0; i < N; ++i)
    {
        int from, to, len;
        cin >> from >> to >> len;
        board[from].push_back(make_pair(to, len));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}