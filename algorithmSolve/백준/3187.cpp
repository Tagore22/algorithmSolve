#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �׷��� Ž�� �� �̷� �����̴�.
// 2���� �迭 board�� ��ȸ�ϵ�, ���̳� ���밡 �߰ߵɽ� �ش� ��Ÿ�� ���� �ٽ� ��� ��ȸ�ϸ� ����� ���� ���� ����.
// ���밡 �� ũ�ų� ���ٸ� ���밡 ��Ƴ��⿡ ������� ���� ������Ű��,
// �׷��� �ʴٸ� ���� ���� ������Ų��.

// �ڼ��� ������ �ּ����� �����.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ��, ��, ��, ��.
int R, C, wolf = 0, sheep = 0;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    // ���������� ���� �̿��Ͽ� ����� ���� ���� �ʱ�ȭ��Ų��.
    int w = 0, s = 0;
    if (board[y][x] == 'v')
        ++w;
    else
        ++s;
    board[y][x] = 'o';

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // ���� ��ǥ�� �湮�Ͽ��ٸ� �迭���� ��ȭ���Ѽ� �ߺ� �湮 ���θ� üũ�ϴ� �迭�� ��ü�Ͽ���.
            // �׷��⿡ ���ǹ����� ���ο� ���ǽ��� �ϳ� �߰��Ǿ���.
            if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#' ||
                board[dy][dx] == 'o')
                continue;

            // ���� ��Ÿ���� ���� �� ���� ���� �����Ѵ�.
            if (board[dy][dx] == 'v')
                ++w;
            else if (board[dy][dx] == 'k')
                ++s;
            board[dy][dx] = 'o';
            que.push(make_pair(dy, dx));
        }
    }
    if (w >= s)
        wolf += w;
    else
        sheep += s;
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == 'v' || board[i][j] == 'k')
                BFS(i, j);

    cout << sheep << ' ' << wolf << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}