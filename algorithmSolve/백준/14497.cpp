#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// Ǯ�鼭 '���� ���ٸ� BFS��.'��� �����µ� �˰��� ���ͽ�Ʈ�� ��������. �� ��·�� �� Ǯ������ �����̴�.
// ���� BFS�� ������ �ϴ� �������� Ǯ����. �ֳ��ϸ� ������ �ణ �������Ҵµ�, ���� �Ͽ� ������ 1�� �� �ѹ���
// ������� �����̴�. ���� �湮�� ���ϴ� visit �迭�� ������ bool Ÿ���� �ƴ� int Ÿ������ �Ͽ�
// ������ ���� ���� ����ϰԲ� �Ͽ���. �׷��� �ʰ� bool Ÿ������ �ϸ� �����Ƿ� �ڵ尡 ���������� �����̴�.

// �ڼ��� ������ �ּ����� �����.

char board[301][301];
int visit[301][301];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> from, to;

// num��° �Ͽ� �����Ҽ� �ִ� ��� ���� ������ BFS �Լ�.
void BFS(int num)
{
    queue<pair<int, int>> que;
    que.push(from);
    // ����Ѵ�� visit �迭�� bool�� �ƴ� int��. �ߺ� �湮�� �� ��ġ�� ������ ���� �ֱ� ���� �ξ
    // ���ϱ� ����.
    visit[from.first][from.second] = num;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();


        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // ��ǥ���� ����ų�, �̹� �Ͽ� �ش� ��ǥ�� �湮�ߴ����� �ִٸ� �����Ѵ�.
            if (ny <= 0 || ny > N || nx <= 0 || nx > M || visit[ny][nx] == num)
                continue;

            // ������ 0�̾��ٸ� ��� ť�� �ְ� ��ȸ�Ѵ�.
            if (board[ny][nx] == '0')
            {
                que.push(make_pair(ny, nx));
                visit[ny][nx] = num;
            }
            // 1�̾��ٸ� ��������̹Ƿ� ���� 0���� �ٲٰ� ����.
            else if (board[ny][nx] == '1')
            {
                board[ny][nx] = '0';
                visit[ny][nx] = num;
            }
            // �������� '#'���̹Ƿ� ���� ã�� ����. ����ϰ� exit�� �ƿ� �ݺ��� �����ϸ�
            // ���α׷��� �����Ѵ�.
            else
            {
                cout << num << '\n';
                exit(0);
            }
        }
    }
}

void MakeAnswer()
{
    int num = 1;
    while (true)
    {
        BFS(num);
        ++num;
    }
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