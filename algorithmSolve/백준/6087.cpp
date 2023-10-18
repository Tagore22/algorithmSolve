#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 정답율을 보면 알겠지만 꽤나 어려웠던 문제다.
// C에서 C로 이동하는 최단거리중 방향이 바뀌는 최소 횟수를 출력하는 문제다.
// 단순히 BFS로 구현하면 방문 순서에 따라 답이 달라지게 되어 제대로 풀수가 없다.
// 따라서 다익스트라를 이용해서 현재 횟수를 기준으로 큐를 순회해야 한다.
// 또한 어떤 정점 i, j를 똑같이 방문해도 어떤 방향에서 방문했는지에 따라 그 횟수가 달라지므로
// 이것 또한 DP를 이용해야 했다. 어려운 문제였으나 결국 풀어서 다행이다.

// 자세한 설명은 주석으로 남긴다.

char board[100][100];
int rot[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 동, 남, 서, 북
pair<int, int> point[2];
int W, H;

void BFS()
{
    // 다익스트라 알고리즘을 위한 우선순위 큐. 정렬을 해야해서 구조체를 따로 쓰지 않았기에
    // 타입명이 개박살났다.
    priority_queue<pair<int, pair<pair<int, int>, int>>> que;
    // 시작점은 방향이 바뀌어도 거울을 쓰지 않기에 방향을 -1로 처리한다.
    que.push(make_pair(0, make_pair(make_pair(point[0].first, point[0].second), -1)));
    // 각 정점 및 방향에 따른 DP처리.
    int dist[100][100][4];
    // 모든 값을 최대값으로 초기화시켜준다.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                dist[i][j][k] = 987654321;
            }
        }
    }
    // 모든 시작점은 0으로 바꾼다.
    for (int i = 0; i < 4; ++i)
        dist[point[0].first][point[0].second][i] = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int y = que.top().second.first.first;
        int x = que.top().second.first.second;
        int dir = que.top().second.second;
        que.pop();

        // 최초로 도착했을때 가장 작은 횟수를 지닌 상태이므로 최종답에 해당한다.
        // 출력후 탈출한다.
        if (y == point[1].first && x == point[1].second)
        {
            cout << cost << '\n';
            return;
        }

        // 4방향 모두 이동할수 있는지 확인한다.
        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 범위값을 벗어나거나 벽으로 막힌곳이라면 무시한다.
            if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '*')
                continue;

            int next_cost = cost;
            // 방향이 -1(시작점)이 아니고, 기존 방향과 현재 방향이 다르다면 횟수를 1 증가시킨다.
            if (dir != -1 && dir != i)
                next_cost = cost + 1;

            // 횟수가 기존 횟수보다 같거나 크다면 무시한다.
            if (dist[dy][dx][i] <= next_cost)
                continue;

            // 기존 횟수를 갱신하고 큐에 넣는다.
            dist[dy][dx][i] = next_cost;
            que.push(make_pair(-next_cost, make_pair(make_pair(dy, dx), i)));
        }
    }
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> H;
    int p = 0;
    string str;
    for (int i = 0; i < H; ++i)
    {
        cin >> str;
        for (int j = 0; j < W; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'C')
            {
                point[p] = make_pair(i, j);
                ++p;
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}