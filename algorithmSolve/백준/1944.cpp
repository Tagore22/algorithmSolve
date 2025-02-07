#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 정답율이 보여주듯 어려운 문제였다. 우선 복제라는 단어가 나왔는데 사실 이건 의미가 없었다. 어차피 BFS 알고리즘의
// 구현 자체가 4방향으로 이동했을 경우를 간주하여 que에 집어넣기 때문이다. 문제에서 원하는 답은 S에서 K까지의 
// 거리들의 총합이다. 다만 S에서 K를 지나 또다른 K에 도달할때 S에서 두번째 K의 거리는 사실상 첫번째 K에서
// 두번째 K의 거리임을 잊으면 안된다. 결과적으로 이 문제는 S 및 K들을 정점으로 두었을때 BFS를 통해서
// 각 정점들의 거리를 구한후, MST를 이용하여 총 거리값의 최소값을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

char board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }, idx[50][50], dist[251][251];
int N, M;
pair<int, int> from;
vector<pair<int, int>> pos;

// y, x에서 다른 S 혹은 K까지의 모든 거리들을 구한다.
void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    bool visit[50][50] = { false, };
    visit[y][x] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int cy = que.front().first;
            int cx = que.front().second;
            que.pop();

            // 또다른 K 혹은 S를 발견했을때 거리를 저장한다.
            if (board[cy][cx] == 'K' || board[cy][cx] == 'S')
            {
                int from = idx[y][x];
                int to = idx[cy][cx];
                dist[from][to] = min(dist[from][to], answer);
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = cy + rot[i][0];
                int nx = cx + rot[i][1];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == '1' || visit[ny][nx])
                    continue;
                que.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }
}

// 모든 거리 총합의 최소값을 구한다.
void Prim()
{
    bool visit[251] = { false, };
    int mindist[251];
    for (int i = 0; i <= M; ++i)
        mindist[i] = 2501;
    // 어느 정점에서 시작하든 상관이 없기에 0번 위치에서 시작한다.
    mindist[0] = 0;
    int answer = 0;

    // K가 최대 250개고 S까지 더해야함으로 M - 1까지가 아닌 M개까지 순회해야한다.
    for (int iter = 0; iter <= M; ++iter)
    {
        int u = -1;
        for (int i = 0; i <= M; ++i)
            if (!visit[i] && (u == -1 || mindist[i] < mindist[u]))
                u = i;

        answer += mindist[u];
        visit[u] = true;

        // 다른 정점들을 순회하며 아직 방문하지 않은 정점들의 최소값들을 갱신한다.
        for (int i = 0; i <= M; ++i)
            if (!visit[i] && mindist[i] > dist[u][i])
                mindist[i] = dist[u][i];
    }
    // answer가 2501을 넘었다는 것은 어떤 두 정점들끼리 도달할수 없다는 것을 의미하기에
    // -1을 출력한다.
    cout << (answer >= 2501 ? -1 : answer) << '\n';
}

void MakeAnswer()
{
    for (int i = 0; i <= M; ++i)
        for (int j = 0; j <= M; ++j)
            dist[i][j] = 2501;
    for (auto& here : pos)
    {
        int y = here.first;
        int x = here.second;
        BFS(y, x);
    }
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int num = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S' || board[i][j] == 'K')
            {
                pos.push_back(make_pair(i, j));
                idx[i][j] = num++;
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