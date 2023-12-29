#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// ó���� ������ ���ظ��ؼ� ���� ��̴�. ���� ������ �����Ÿ��� ���ϴ��� �˾Ҵµ�
// ��ĭ���� ���� ����� ������ �Ÿ��� �����Ÿ���� �Ҷ� ���� ū �����Ÿ��� ������ ĭ��
// �����Ÿ��� ���ϴ� ���̾���. �� ������ ��ġ�� ���Ͽ� ��� BFS��ȸ�� �ϵ� �� ĭ��
// �Ź� �ּҰ����� �����Ͽ���. �׷��� ���� �̷� �ʿ䰡 ������.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> board;
vector<pair<int, int>> shark;
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int N, M;

// BFS��ȸ�� �ϴ� �Լ�.
void BFS(int y, int x)
{
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    visit[y][x] = true;
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(y, x), 0));

    while (!que.empty())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int cost = que.front().second;
        que.pop();

        // 8�������� ��� �̵��غ���.
        for (int i = 0; i < 8; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // �̵��� ��ġ�� �迭���� ����ų� �̹� �湮�� ��ġ��� �����Ѵ�.
            if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx])
                continue;

            // �湮 ���θ� �����ϰ� �� ĭ�� �ּ� �����Ÿ��� �����Ѵ�.
            visit[dy][dx] = true;
            board[dy][dx] = min(board[dy][dx], cost + 1);
            // ť�� ���� ����ִ´�.
            que.push(make_pair(make_pair(dy, dx), cost + 1));
        }
    }
}

void MakeAnswer()
{
    // ��� ������ŭ BFS��ȸ�� �Ѵ�.
    for (auto p : shark)
        BFS(p.first, p.second);

    // �� ������ ��ġ�� ĭ�� ���ܽ�Ų��.
    for (auto p : shark)
        board[p.first][p.second] = -1;

    // ��� ĭ�� ��ȸ�ϸ� ���� ū ���� ã�´�.
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            answer = max(answer, board[i][j]);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(M, 987654321));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int point;
            cin >> point;
            if (point == 1)
                shark.push_back(make_pair(i, j));
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}