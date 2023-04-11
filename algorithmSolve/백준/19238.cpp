#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// �Ź� BFS�� ���� �ִܰŸ��� ���ϴ� ������.
// �ƹ����� �̰� �ƴѰ� ���⵵ �ѵ� ���߿� �ٽ� ���߰ڴ�.

int board[21][21];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
pair<int, int> start_pos[400], end_pos[400];
bool check[21][21];
bool visit[400];
int N, M, O, pass_num;
pair<int, int> cur_pos, min_cost;

// � ��ǥ�� y, x������ �ִܰŸ��� ���ϴ� �Լ�.
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

// ���� �մԵ��� �湮���� ���� �մԵ���� �ִܰŸ��� ���ϴ� �Լ�.
void CalDis()
{
    min_cost = make_pair(-1, 987654321); // ��ȣ, �Ÿ�
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
        // �ִܰŸ��� ������ ���߰�, ��� �մ��� �湮�ߴٸ� ���� �⸧�� ����Ѵ�.
        if (pass_num == 0 && min_cost == make_pair(-1, 987654321))
        {
            cout << O << '\n';
            return;
        }

        // ���� �մ��� ���� 0�� �ƴϸ鼭 �ִܰŸ��� ������ ���߰ų�, �ִܰŸ��� ���� �⸧���� ��ٸ� -1�� ����Ѵ�.
        else if ((pass_num != 0 && min_cost == make_pair(-1, 987654321)) || O < min_cost.second)
        {
            cout << -1 << '\n';
            return;
        }

        // ���� �ý��� ��ġ ���� �� �⸧�� ����. ���� �մ��� �湮 ���α��� �����Ѵ�.
        cur_pos = make_pair(start_pos[min_cost.first].first, start_pos[min_cost.first].second);
        O -= min_cost.second;
        visit[min_cost.first] = true;

        // ���� �մ��� ������������ �ִܰŸ��� ���Ѵ�.
        int next = BFS(end_pos[min_cost.first].first, end_pos[min_cost.first].second);
        // �������� ���Ѵٸ� -1 ���.
        if (O < next)
        {
            cout << -1 << '\n';
            return;
        }

        // �ý��� ��ġ�� �����ϰ� �⸧�� �����ϸ� ���� �մ��� �� ���� �����Ѵ�.
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