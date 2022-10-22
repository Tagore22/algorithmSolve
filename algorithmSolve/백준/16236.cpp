#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

//꽤나 많이 애먹었던 문제이다. 방법은 단순히 매번 상어가 먹을수 있는 물고기들중 가장 가깝고, 그중 가장 좌상단에 있는 위치의 물고기를
//골라야한다. 그래서 더이상 먹을수 있는 물고기가 없어질때까지 이동하는 칸수를 출력하면 된다.
//처음에는 각 물고기들의 좌표를 map에 기억해뒀다가 매번 순회해가며 원소값이 먹을수 있는 물고기라면 최소값을 구해가며 풀이를 했었는데
//그렇게 하면 DFS * map 순회 * 최대 물고기들의 수가 되어 시간을 가볍게 초과하게 된다. 답은 그냥 간단하게 매 상어 위치에서 먹을수 있는
//가장 가까운 물고기를 찾아서 먹어가면서 움직이는 칸수를 더하면 되었다.
//시간 복잡도는 N이 최대 20이기에 400칸이므로 BFS에서 O(V+E)(400 + (400 * 4))에 모든칸에 물고기가 있고 먹을수 있다는 가정하에
//400마리의 물고기를 먹으므로 2000 * 400으로 80만이되며, 빅오로는 n의 4제곱이 된다.

using namespace std;

const int MAX_NUM = 20;
int board[MAX_NUM][MAX_NUM];
int N, shark_power = 2;
vector<pair<int, pair<int, int>>> point;
pair<int, int> shark;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
bool check[MAX_NUM][MAX_NUM];

void BFS(int y, int x)
{
    queue<pair<int, pair<int, int>>> que;
    que.push(make_pair(0, make_pair(y, x)));
    check[y][x] = false;

    while (!que.empty())
    {
        int cost = que.front().first;
        int y = que.front().second.first;
        int x = que.front().second.second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (cy < 0 || cy >= N || cx < 0 || cx >= N || !check[cy][cx] || board[cy][cx] > shark_power)
                continue;
            if (board[cy][cx] < shark_power && board[cy][cx] != 0)
                point.push_back(make_pair(cost + 1, make_pair(cy, cx)));
            que.push(make_pair(cost + 1, make_pair(cy, cx)));
            check[cy][cx] = false;
        }
    }
}

void MakeAnswer()
{
    int answer = 0, eaten = 0;
    while (true)
    {
        point.clear();
        memset(check, true, sizeof(check));
        BFS(shark.first, shark.second);
        if (point.size() == 0)
        {
            cout << answer << '\n';
            return;
        }
        sort(point.begin(), point.end());
        answer += point[0].first;
        board[point[0].second.first][point[0].second.second] = 0;
        shark = make_pair(point[0].second.first, point[0].second.second);
        ++eaten;
        if (eaten == shark_power)
        {
            ++shark_power;
            eaten = 0;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                shark = make_pair(i, j);
                board[i][j] = 0;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}