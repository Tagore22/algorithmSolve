#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 난이도가 골1인만큼 쉽지 않은 문제였다. 여러가지 경우를 모두 생각해야했기 때문이다.
// 문제 자체는 그리 어렵지 않다. 주어진 칸들중 값이 2인 칸들중에서 임의의 시작점을 만들고
// 그 시작점에서 BFS순회를 시작하여 만들수 있는 가장 큰 꽃의 수를 출력하면 된다.
// 구현 자체는 어렵지 않았으나 1000가지중 1가지 경우를 찾지 못해서 오랜시간 헤맸다.
// 그것은 후술하겠다.

// 자세한 설명은 주석으로 남긴다.

int board[50][50], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
vector<pair<int, int>> land;
deque<pair<int, int>> g_que, r_que;
int N, M, G, R, answer = 0;

// 1. 땅인 지역에서 뿌릴수 있는 땅들중 초록색과 빨간색을 주어진 수만큼 임의로 지정한다.
// 2. BFS 순회를 하여 꽃의 개수를 구한다.
// 3. BFS 순회는 각각 빨간색과 초록색이 모두 같은 시간에 나아가는데 
// 이미 빨간색인 곳에 초록색이 도달할수 없고 초록색인 곳에 빨간색이 도달할수 없다.
// 다만, 같은 시간대에 만났을 경우에만 꽃이 된다. 꽃이 된곳은 que에 집어넣지 않고 그자리에
// 머문다.

// 임의의 시작점들이 주어졌을때 만들수 있는 꽃의 수를 계산하는 BFS 순회함수.
void BFS()
{
    int temp[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            temp[i][j] = board[i][j];
    int time[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            time[i][j] = -1;
    queue<pair<int, int>> que;
    // 3은 현재 초록색임을 뜻하고 4는 빨간색, 5는 꽃이 핀 칸임을 뜻한다.
    for (auto& a : g_que)
    {
        que.push(a);
        temp[a.first][a.second] = 3;
    }
    for (auto& a : r_que)
    {
        que.push(a);
        temp[a.first][a.second] = 4;
    }
    int now = 0, ans = 0;

    while (!que.empty())
    {
        ++now;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 이 부분에서 한참 헤맸다. 이 것이 상술한 1000가지중 1가지 실타래였는데
            // 만약 어떤 칸이 빨간색으로 변경된 후에 초록색이 다시 도달한다면 그 곳은 꽃이 피고 끝나야 한다.
            // 하지만 실제 구현에서는 그렇지 않았다. 빨간색이 도달한 순간 그 칸은 빨간색으로 변하며 큐에
            // 좌표값이 이미 포함되기 때문이다. 그 후에 초록색이 도달하여 꽃이 핀후에도 큐에 들어간 좌표값은
            // 사라지지 않고 그대로 순회에 포함된다. 그래서 아이러니 하게도 꽃이 순회하게 되며 꽃의 수가 
            // 이상하리만치 늘어나게 되었던 것이다. 따라서 현재 좌표가 꽃으로 바뀌었다면 무시해주어야 한다.
            if (temp[y][x] == 5)
                continue;

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 배열값을 벗어나거나 꽃이 되었거나, 나와 같은 값(같은 색)이라면 무시한다.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || temp[ny][nx] == 0 ||
                    temp[ny][nx] == temp[y][x] || temp[ny][nx] == 5)
                    continue;

                // 그 이후는 배열값이 1, 2, 나와 다른 3 혹은 4가 될수밖에 없으며
                // 이중 1, 2인 경우에만 새로운 색으로 물들고 나머지는 꽃이 된다.

                // 배열값이 1이나 2인 경우. 새로운 값으로 물든다.
                if (temp[ny][nx] == 1 || temp[ny][nx] == 2)
                {
                    // 나와 같은 색으로 바뀌며 시간값을 바꾸고 큐에 집어넣는다.
                    temp[ny][nx] = temp[y][x];
                    time[ny][nx] = now;
                    que.push(make_pair(ny, nx));
                }
                // 1, 2도 아니며 나와 다른색이 존재하는 경우. 즉 꽃이 된다.
                // 다만 같은 시간대에 만나야만 한다.
                else if (time[ny][nx] == now)
                {
                    // 꽃이 하나 증가하며 값을 갱신한다.
                    ++ans;
                    temp[ny][nx] = 5;
                }
            }
        }
    }
    answer = max(answer, ans);
}

// 배양액을 뿌릴수 있는 땅들중 G, R개를 고르는 함수.
void ChooseLand(int idx, int green, int red)
{
    // 각각 G와 R개를 구했다면 BFS순회를 시작한다.
    if (green == G && red == R)
    {
        BFS();
        return;
    }

    // 마지막까지 G와 R개를 고르지 못했다면 탈출한다.
    if (idx == land.size())
        return;

    int y = land[idx].first;
    int x = land[idx].second;
    // 초록색.
    g_que.push_back(make_pair(y, x));
    ChooseLand(idx + 1, green + 1, red);
    g_que.pop_back();
    // 빨간색
    r_que.push_back(make_pair(y, x));
    ChooseLand(idx + 1, green, red + 1);
    r_que.pop_back();
    // 무시하고 넘어감.
    ChooseLand(idx + 1, green, red);
}

void MakeAnswer()
{
    ChooseLand(0, 0, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> G >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                land.push_back(make_pair(i, j));
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}