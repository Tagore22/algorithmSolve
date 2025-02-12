#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �Ѱ��� �Ǽ��� �ð��� �ϳ� ��Ƹ��� ������. �־��� �迭�� ũ�Ⱑ �ִ� 1000 x 1000�̱� ������ �׿� �ش��ϴ�
// bool Ÿ�� �迭�� �ߺ��湮�� ���ƾ��ϴµ� ���� �迭�δ� �Ұ����ϴ�. �̰��� �޸� ������ ������ �ִµ�
// ���� ������ stack����, ���� ������ data���� �����Ѵ�. �ü���� ���� stack�� �޸� ������ �ɷ� �ֱ�
// ������ �ִ� 100���� �ش��ϴ� �迭�� �����Ҽ� ���� ������ vs���� ����� �� ���� ������� ���ߴ�.
// ���� ���� �迭�� �����ؾ� ����� �� ����� ������ �־���. ������ BOJ���� ���� �޸� ������ ��������
// �ʱ� ������ �׳� ���� �迭�� �����ص� ������ ����� �־���. ����� ���� �迭�� �뷫 �ִ� 25�������� �����Ҽ�
// �ִ�.

// �ڼ��� ������ �ּ����� �����.

// ��ǥ�� �������� ��� ����.
struct pos
{
    int y;
    int x;
    bool canuse;
};

int board[1001][1001], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> from, to;
bool visit[1001][1001][2] = { false, }; // ����Ѵ�� vs������ �����迭�� �ؾ������� BOJ������ ����� ����.

void BFS()
{
    queue<pos> que;
    que.push(pos{ from.first, from.second, true });
    visit[from.first][from.second][1] = true;
    int answer = -1;

    while (!que.empty())
    {
        // ���� ť�� ���ִ� ������ ���鸸 �̸� ���Ͽ� ��ȸ�� �����ν�
        // ť�� �̵�Ƚ���� ���� ���� �ʾƵ� �ȴ�.
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            bool canuse = que.front().canuse;
            que.pop();

            // �������� �����Ͽ��°�.
            if (y == to.first && x == to.second)
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ��ǥ���� ����ų� �������� ������� ���ϴ� ���¿��� ���� �����ٸ� �����Ѵ�.
                if (ny <= 0 || ny > N || nx <= 0 || nx > M ||
                    (!canuse && board[ny][nx] == 1))
                    continue;

                // �������� ��������� ���� ��Ȳ�� ������ ��ġ�Ƿ� �̸� �����ؾ��Ѵ�.
                bool ncanuse = (board[ny][nx] == 1 || !canuse) ? false : true;
                if (visit[ny][nx][ncanuse])
                    continue;
                que.push(pos{ ny, nx, ncanuse });
                visit[ny][nx][ncanuse] = true;
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> from.first >> from.second >> to.first >> to.second;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}