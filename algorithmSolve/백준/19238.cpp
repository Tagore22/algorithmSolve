#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 매번 BFS를 통해 최단거리를 구하는 문제다.
// 아무래도 이게 아닌거 같기도 한데 나중에 다시 봐야겠다.

int board[21][21];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
pair<int, int> start_pos[400], end_pos[400];
bool check[21][21];
bool visit[400];
int N, M, O, pass_num;
pair<int, int> cur_pos, min_cost;

// 어떤 좌표값 y, x까지의 최단거리를 구하는 함수.
int BFS(int y, int x)
{
    memset(check, false, sizeof(check));
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(cur_pos.first, cur_pos.second), 0));

    while (!que.empty())
    {
        int now_y = que.front().first.first;
        int now_x = que.front().first.second;
        int dis = que.front().second;
        que.pop();

        if (now_y == y && now_x == x)
            return dis;

        for (int i = 0; i < 4; ++i)
        {
            int dy = now_y + rot[i][0];
            int dx = now_x + rot[i][1];

            if (dy <= 0 || dy > N || dx <= 0 || dx > N || check[dy][dx] || board[dy][dx] == 1)
                continue;

            que.push(make_pair(make_pair(dy, dx), dis + 1));
            check[dy][dx] = true;
        }
    }
    return 987654321;
}

// 현재 손님들중 방문하지 않은 손님들과의 최단거리를 구하는 함수.
void CalDis()
{
    min_cost = make_pair(-1, 987654321); // 번호, 거리
    for (int i = 0; i < M; ++i)
        if (!visit[i])
        {
            int cur_cost = BFS(start_pos[i].first, start_pos[i].second);
            if (cur_cost < min_cost.second || (cur_cost == min_cost.second && start_pos[i].first < start_pos[min_cost.first].first)
                || (cur_cost == min_cost.second && start_pos[i].first == start_pos[min_cost.first].first && start_pos[i].second < start_pos[min_cost.first].second))
                min_cost = make_pair(i, cur_cost);
        }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));

    while (true)
    {
        CalDis();
        // 최단거리를 구하지 못했고, 모든 손님을 방문했다면 남은 기름을 출력한다.
        if (pass_num == 0 && min_cost == make_pair(-1, 987654321))
        {
            cout << O << '\n';
            return;
        }

        // 남은 손님의 수가 0이 아니면서 최단거리를 구하지 못했거나, 최단거리가 남은 기름보다 길다면 -1을 출력한다.
        else if ((pass_num != 0 && min_cost == make_pair(-1, 987654321)) || O < min_cost.second)
        {
            cout << -1 << '\n';
            return;
        }

        // 현재 택시의 위치 갱신 및 기름의 갱신. 또한 손님의 방문 여부까지 갱신한다.
        cur_pos = make_pair(start_pos[min_cost.first].first, start_pos[min_cost.first].second);
        O -= min_cost.second;
        visit[min_cost.first] = true;

        // 현재 손님의 목적지까지의 최단거리를 구한다.
        int next = BFS(end_pos[min_cost.first].first, end_pos[min_cost.first].second);
        // 도달하지 못한다면 -1 출력.
        if (O < next)
        {
            cout << -1 << '\n';
            return;
        }

        // 택시의 위치를 갱신하고 기름을 갱신하며 남은 손님의 수 역시 갱신한다.
        cur_pos = make_pair(end_pos[min_cost.first].first, end_pos[min_cost.first].second);
        O += next;
        --pass_num;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> O;
    pass_num = M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
    cin >> cur_pos.first >> cur_pos.second;
    for (int i = 0; i < M; ++i)
        cin >> start_pos[i].first >> start_pos[i].second >> end_pos[i].first >> end_pos[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}