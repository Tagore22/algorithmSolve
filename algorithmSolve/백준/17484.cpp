#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ó������ BFS�� ans �迭�� ������ �� �׳� 2�������� ��ǥ���� �����ߴµ�
// �Ȱ��� {y, x}�� �����߾ � ���⿡�� �����ߴ����� ������ �ǰ����߱⿡
// 2������ �ƴ� 3�������� �����Ͽ� ������ ������� �迭ȭ�ؾ��ߴ�.

struct pos
{
    int y;
    int x;
    int dir;
};

int N, M;
int board[6][6], rot[3][2] = { {1, -1}, {1, 0}, {1, 1} };

void BFS()
{
    queue<pos> que;
    int ans[6][6][3];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < 3; ++k)
                ans[i][j][k] = 601;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            que.push({ 0, i, j });
            ans[0][i][j] = board[0][i];
        }
    }

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int dir = que.front().dir;
        que.pop();

        if (y == N - 1)
            continue;

        for (int i = 0; i < 3; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || dir == i)
                continue;
            int cost = ans[y][x][dir] + board[ny][nx];
            if (cost > ans[ny][nx][i])
                continue;
            que.push({ ny, nx, i });
            ans[ny][nx][i] = cost;
        }
    }
    int answer = 601;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < 3; ++j)
            answer = min(answer, ans[N - 1][i][j]);
    cout << answer << '\n';
}

void Solve()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}