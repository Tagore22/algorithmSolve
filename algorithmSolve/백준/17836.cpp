#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ������ BFS��������. �ٸ� �̻��ϸ���ġ �������� ����. 25�۰� �ȵǴµ� �Ƹ�
// ���� ������ �������� �׷��� �������� �ٸ� ������� �������ϴ°ǰ� �;���.
// ��·�� �����ϰ� ����غ��ڸ� BFS�� ��ȸ�� �ϵ�, ���� �ִ��� ���������� �ؼ� 3���� �迭��
// ����Ͽ��� �Ѵ�. �̵� ���ǹ����� ���� ���������� ���� �հԲ��ϸ� �ȴ�. �ѹ� Ʋ�ȴµ�
// T�ð��ȿ� �����Ҽ� ���ٸ� Fail�� ����ؾ� �ϴµ� �̰��� �����ߴ�. Ǯ�̸� �ٽ� ���°͵� �߿�������
// ������ �� �о��!

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    int y;
    int x;
    int sword; // ������ 0, ������ 1;
};

int board[101][101];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, T;

void BFS()
{
    queue<pos> que;
    que.push(pos{ 1, 1, 0 });
    bool visit[101][101][2] = { false, };
    visit[1][1][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        // ����� �Ǽ�. T�ð����� ������ ���Ѵٸ� while���� Ż���Ͽ� �ٷ� Fail�� ����Ѵ�.
        if (answer > T)
            break;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int sword = que.front().sword;
            que.pop();

            if (y == N && x == M)
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ��ǥ���� ����ų�, �ߺ��湮�̰ų�, ���� ������ ���� �����ٸ� �ش� ��ġ�� �̵����� ���Ѵ�.
                if (ny <= 0 || ny > N || nx <= 0 || nx > M || (sword == 0 && board[ny][nx] == 1) ||
                    visit[ny][nx][sword])
                    continue;

                // �̹� ���� ������ �ְų� ���� �̵����� ���� ã�´ٸ� ���� ���� ���°� �ȴ�.
                int next = (board[ny][nx] == 2 || sword == 1) ? 1 : 0;
                que.push(pos{ ny, nx, next });
                visit[ny][nx][next] = true;
            }
        }
    }
    cout << "Fail" << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
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