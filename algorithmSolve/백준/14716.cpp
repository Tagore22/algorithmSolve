#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ����� BFS�����̴�. �ٸ� ��ҿ��� �׷����� �湮 ���θ� ����ϴ� bool Ÿ�� �迭��
// ���� board���� �����Ű�Ƿν� ��ü�Ҽ� �ִ�.
// ���� �� 8ms�� ���Դµ� 4ms �ڵ��� ���ص� ���� ���̰� ���µ� ���� ���̳������� �𸣰ڴ�.
// ����� ���̿��� ��ԵȰͰ���. �׸� ���̰� ũ�� ������ ��������.

// �ڼ��� ������ �ּ����� �����.

bool board[250][250];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} }; // �º��� �ð����.
int M, N;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    board[y][x] = false;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // �̹��� �� �� �� �� 4������ �ƴ� �밢������ 8�����̴�.
        for (int i = 0; i < 8; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= M || dx < 0 || dx >= N || !board[dy][dx])
                continue;

            // ����Ͽ��� ���� ���� �����Ű�Ƿν� ���� �ߺ� �湮 ���θ� üũ�Ҽ� �ִ�.
            board[dy][dx] = false;
            que.push(make_pair(dy, dx));
        }
    }
}

void MakeAnswer()
{
    int answer = 0;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j])
            {
                ++answer;
                BFS(i, j);
            }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}