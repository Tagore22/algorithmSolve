#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ������ ���� �˰�����, ����ġ�� ���� ���� ���ÿ� �������� �ϱ⿡ DFS�� �ƴ� BFS�� Ǯ��� �ϴ� �����̴�.
// �׷��� BFS�� �����Ͽ� Ǯ������ �̻��ϰ� �޸� �ʰ��� ���Դ�. �ʱ⿡ �ִ� ���� ��ġ�� �ľ��ϴ� ���͵鵵
// ��� ������ ��ä�� �����Ͽ��µ��� �޸� �ʰ��� ��� ���ͼ� ���� �߸��Ǿ����� �ڼ��� �ôµ�, BFS����
// 4�������� �̵��� �Դ� �������� �ٽ� ���ư��°� �����ϴ� �ڵ尡 ������. �׷��� �������� ���Ұ�,
// �׷� ���� �޸� �ʰ��� ������.

struct pos
{
    int y;
    int x;
    int cost;
};

char board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int R, C;
pair<int, int> S, D;

// �� ���� ����ġ�� ���� �̵��ϴ°� �����ϴ� �Լ�.
int BFS()
{
    queue<pos> que;

    // ���� ���� ��ġ�� ��� ť�� ���� �ִ´�.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == '*')
                que.push(pos{ i, j, -1 });

    // �� �ϳ�����, ����ġ�� ��ġ�� �ִ´�. �߿��� ���� ���� ����ġ�� �̵��Ҽ� �ִ� ������
    // �ٸ��� ������ �� ���� �����ؾ��Ѵٴ� ���̴�. ������ ť���� 3����(y��ǥ, x��ǥ, �ɸ� �ð�)�� �ʿ��ϰ�,
    // ���� �ð��� �ʿ����� �ʱ⿡ �̰��� ������ -1�� �ξ� ���� ����ġ�� �����Ͽ���.
    que.push(pos{ S.first, S.second, 0 });

    while (!que.empty())
    {
        int cur_y = que.front().y;
        int cur_x = que.front().x;
        int cur_cost = que.front().cost;
        que.pop();

        // ���� �����ߴٸ� ����� �ɷȴ��� ��ȯ�Ѵ�.
        if (cur_y == D.first && cur_x == D.second)
            return cur_cost;

        // ����ġ�� ���� �̵� ������ �ٸ��� ������ ��¿�� ���� �����ؾ��Ѵ�.
        // ���� ����ġ���.
        if (cur_cost != -1)
        {
            for (int i = 0; i < 4; ++i)
            {
                int dy = cur_y + rot[i][0];
                int dx = cur_x + rot[i][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == 'X' ||
                    board[dy][dx] == '*' || board[dy][dx] == 'S')
                    continue;

                board[dy][dx] = 'S';
                que.push(pos{ dy, dx, cur_cost + 1 });
            }
        }

        // ���̶��.
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                int dy = cur_y + rot[i][0];
                int dx = cur_x + rot[i][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == 'X' ||
                    board[dy][dx] == 'D' || board[dy][dx] == '*')
                    continue;

                board[dy][dx] = '*';
                que.push(pos{ dy, dx, cur_cost });
            }
        }
    }

    // ���� �������� ���� ��� -1�� ��ȯ�Ͽ� �������� �д�.
    return -1;
}

void MakeAnswer()
{
    int answer = BFS();

    if (answer != -1)
        cout << answer << '\n';
    else
        cout << "KAKTUS" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
                S = make_pair(i, j);
            else if (board[i][j] == 'D')
                D = make_pair(i, j);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}