#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 처음에는 편의점들을 골에서 가까운 순서대로 정렬해서
// 현재 지점에서 도달할수 있는 가장 골에 가까운 편의점에 도달하는 방식으로 하였으나,
// 현재 지점에서 골쪽으로 더 가까운 곳으로 갈수 없어 돌아가야 하는 경우도 있었다.

// 1
// 4
// 2000 0
// 1000 0
// 0 0
// 0 1000
// 0 2000
// 1000 2000

// 이런 경우가 그러했다. 즉 그리디로는 풀수 없고 그래프를 사용하여 풀어야했다.
// 그래서 바뀐 로직은 현재 지점에서 주어진 편의점들중 도달할수 있는 편의점에 도달하여
// 그 편의점에서 골에 도달할수 있는지 확인하고 도달한다면 happy를 출력하고
// 그럴수 없다면 또다시 도달할수 있는 편의점들에 도달하는 것을 반복하는 BFS방식이다.

// 자세한 내용은 주석을 첨부함.

// 편의점들의 좌표와 시작점, 도착점.
pair<int, int> board[100];
pair<int, int> cur, goal;
int T, N;
const int DIST = 1000;

// 두 좌표의 거리를 반환하는 함수.
int CalDist(pair<int, int> lhs, pair<int, int> rhs)
{
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

// 현재 지점에서 골까지 도달할수 있는가를 반환하는 함수.
bool BFS()
{
    queue<pair<int, int>> que;
    que.push(cur);
    bool visit[100];
    memset(visit, false, sizeof(visit));

    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();

        // 현재지점에서 골까지 도달할수 있다면 true를 출력한다.
        if (CalDist(now, goal) <= DIST)
            return true;

        // 모든 편의점들중 아직 방문하지 않았으며 도달할수 있는 편의점에 도달한다.
        for (int i = 0; i < N; ++i)
            if (!visit[i] && CalDist(now, board[i]) <= DIST)
            {
                visit[i] = true;
                que.push(board[i]);
            }
    }

    // 결국 골에 도달하지 못했다면 false를 반환한다.
    return false;
}

void MakeAnswer() // 골쪽으로 더 갈수 없어서 더 멀어지는 쪽으로 돌아가야할수도 있다.
{
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cin >> cur.first >> cur.second;
        for (int j = 0; j < N; ++j)
            cin >> board[j].first >> board[j].second;
        cin >> goal.first >> goal.second;

        bool answer = BFS();

        cout << (answer ? "happy" : "sad") << '\n';
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