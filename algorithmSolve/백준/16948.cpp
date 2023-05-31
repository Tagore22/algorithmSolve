#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 평범한 그래프 완전 탐색 문제이다.
// 시작지점에서 출발하여 6가지 갈수 있는 방향으로 모두 나아가본다.
// 그후 도착지점에 도달하였다면 그 횟수를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N, r1, c1, r2, c2;
int rot[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };

int BFS()
{
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(r1, c1), 0));
    bool visit[200][200];
    memset(visit, false, sizeof(visit));
    visit[r1][c1] = true;

    while (!que.empty())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int cost = que.front().second;
        que.pop();

        if (y == r2 && x == c2)
            return cost;

        // 6가지 방향으로 모두 나아갈수 있나 확인하고 나아갈수 있다면 나아간다.
        for (int i = 0; i < 6; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 이미 방문한 곳이거나 범위값을 벗어난다면 무시한다.
            if (dy < 0 || dy >= N || dx < 0 || dx >= N || visit[dy][dx])
                continue;

            visit[dy][dx] = true;
            que.push(make_pair(make_pair(dy, dx), cost + 1));
        }
    }
    return 987654321;
}

void MakeAnswer()
{
    int answer = BFS();

    cout << (answer == 987654321 ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}