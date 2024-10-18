#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ���� �����ϸ� �ϳ� ����, �׷��� ������ ������ ����� ��������. �� �������� �� �ϳ��� ���ڸ� ���ؼ�
// ��ư� Ǯ����. ��� ��ǥ�� ��ȸ�ϵ�, �װ����� ������ ã�Ҵٸ� �� ������ ���̸� ��ȯ�ϴ� BFS��
// �ٽ� �ѹ� ��ȸ�� �ϸ� �� ���̰����� �����ϰ�, �̹� ������ �������� �����ϴ� BFS�� ���ؼ� �����Ͽ���.
// �߰��� ���ǹ��� ��ٷӰ� �׷��� ������. �ټ��� ������� �ʹ� ��ư� Ǭ ��� ����. �ϳ� �����ߴ� ������.

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    int y;
    int x;
    int h;
};

int board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool point[50][50] = { false, };
int N, M, answer = 0;

// y, x���� �����Ͽ� �����Ҽ� �ִ� ��� ��ǥ�� ���̸� len���� �����ϴ� �Լ�.
void BFS_Plus(int y, int x, int len)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    bool visit[50][50] = { false, };
    visit[y][x] = true;
    // �Ź� �߰��Ǵ� ���� ���Ѵ�.
    int ans = len - board[y][x];
    // �� ��ǥ���� �̹� ������ ������� �����Ѵ�.
    point[y][x] = true;
    // ��ǥ���� ���̸� �����Ѵ�.
    board[y][x] = len;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 4���� ��� ��ȸ�Ѵ�.
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ��ǥ���� ����ų�, �̹� ��ȸ���� �ߺ��湮�̰ų�, ��ǥ���� ���̰��� len���� ũ�ų� ���ٸ� �����Ѵ�.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] ||
                    board[ny][nx] >= len)
                    continue;

                // �湮�� ������ ������ �����Ѵ�.
                visit[ny][nx] = true;
                point[ny][nx] = true;
                // ť�� ����ְ� ���̰��� �����ϸ�, �߰��Ǵ� ���� ����Ѵ�.
                que.push(make_pair(ny, nx));
                ans += len - board[ny][nx];
                board[ny][nx] = len;
            }
        }
    }
    // ��� �߰������� ������ answer�� ���Ѵ�.
    answer += ans;
}

// y, x���� ����� �ִ� ������ ���ϴ� �Լ�. �̰��� �ſ� ������µ�
// ���� 4���� �� ������. ���� ��� 3, 5���� BFS�� �����Ѵٸ� �ᱹ 9���� ū���� ���⿡
// ���õǾ�� �Ѵ�. ������ �������� 1���� 5�� �ٲ�� ���� �� Ŀ���� ������ �ߺ��Ǵ� ���ο� ������
// ����� �Ǿ�����. �̰��� �����ϱ� ���� ���ο� ��ǥ�� ���������� ���̰��� ���Ͽ� �� ū ���̰���
// ������ �������.
int BFS(int y, int x, int h)
{
    queue<pos> que;
    // �ʱ� ��ǥ���� ���̰�. ����Ѵ�� ���̰��� ���� �� ū������ ���ŵǾ��.
    que.push(pos{ y, x, h });
    bool visit[50][50] = { false, };
    visit[y][x] = true;
    // ������ ���̰�. ����Ǵ� ���� ���� ���̿����ϱ⿡ �ʱ�ȭ���� ������ ���� ����ū 10�̴�.
    int len = 10;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int h = que.front().h;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ��ǥ���� ����ٸ� ������ ����� ����. ���� -1�� ��ȯ�Ѵ�.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    return -1;
                // �ߺ��湮�� �����Ѵ�.
                if (visit[ny][nx])
                    continue;
                // ���� �ִ� ���̺��� �� ���� ���� �����ٸ� ���Ⱑ ������ ��輱�̹Ƿ�
                // ���̰��� �����Ѵ�.
                if (board[ny][nx] > h)
                {
                    len = min(len, board[ny][nx]);
                }
                // �� ���� ���̶�� ������ ���ԵǴ� ��ǥ�� ������ ���̰��� �� ���������� �����ϰ�
                // ť�� �ִ´�.
                else
                {
                    visit[ny][nx] = true;
                    que.push(pos{ ny, nx, h });
                }
            }
        }
    }
    return len;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!point[i][j])
            {
                int len = BFS(i, j, board[i][j]);
                if (len != -1)
                    BFS_Plus(i, j, len);
            }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - 48;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}