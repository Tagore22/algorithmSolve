#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 처음에는 BFS와 DFS로 풀려고 했었다. 입력받을 때 '+'인 좌표들을
// 미리 큐에 넣어 BFS를 순회해서 각 좌표의 최소값을 얻을 수 있다.
// 그 이후 DFS로 순회를 하려고 했으나 가능성이 4의 지수값으로 상승하기 때문에
// 무조건 불가능했다. 정답은 우선순위 큐를 이용해 불가능 한 경우를 미리 쳐내는
// 다익스트라였다. 다만 최단거리를 계산하는 기존과 달리 최대거리를 구하기 때문에
// 약간의 응용력이 필요했다.

// 자세한 설명은 주석으로 남긴다.

int N, M;
char board[500][500];
queue<pair<int, int>> que;
pair<int, int> from, to;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }, minboard[500][500], dist[500][500];

void BFS()
{
    int num = 0;
    while (!que.empty())
    {
        ++num;
        int qsize = que.size();
        for (int i = 0; i < qsize; ++i)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || minboard[ny][nx] <= num)
                    continue;

                minboard[ny][nx] = num;
                que.push(make_pair(ny, nx));
            }
        }
    }
}

void DK()
{
    priority_queue<pair<int, pair<int, int>>> que;
    que.push(make_pair(minboard[from.first][from.second], make_pair(from.first, from.second)));
    dist[from.first][from.second] = minboard[from.first][from.second];

    while (!que.empty())
    {
        // 기존에는 비교하는 값에 -을 붙여 작은 값부터 정렬되게 하였으나
        // 상술한대로 최단이 아닌 최대를 구하기에 그럴 필요가 없다.
        int cost = que.top().first;
        int y = que.top().second.first;
        int x = que.top().second.second;
        que.pop();

        if (cost < dist[y][x])
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            int curmin = min(cost, minboard[ny][nx]);

            // 이 부분에서 살짝 헷갈렸는데 보통은 여기서 if문이 true가 될때
            // 큐에 넣는다. 하지만 지금은 continue이기에 if문이 false가 되어야 해서
            // 기존에 >가 아니라 그 반대인 <=가 되어야 했다.
            if (curmin <= dist[ny][nx])
                continue;

            dist[ny][nx] = curmin;
            que.push(make_pair(curmin, make_pair(ny, nx)));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            minboard[i][j] = 30000;
            dist[i][j] = -30000;
            if (board[i][j] == '+')
            {
                que.push(make_pair(i, j));
                minboard[i][j] = 0;
            }
            else if (board[i][j] == 'V')
            {
                from = make_pair(i, j);
            }
            else if (board[i][j] == 'J')
            {
                to = make_pair(i, j);
            }
        }
    }

    BFS();
    DK();
    cout << dist[to.first][to.second] << '\n';
    return 0;
}