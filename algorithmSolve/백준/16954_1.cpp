#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 16954���� �� ������ �뷮�� ������ Ǯ��.
// dp�� �ش��� �ð��ʿ� �־���. �׷��ٸ� �ִ� �ʰ� ���������� �˾ƾ� �ϴµ�
// �װ��� ������ ���� ������ �����ϰ� ���Ҽ� �ִ�.

// 1. ���� ���� �����´�.
// 2. �̷δ� ���μ��� 8ĭ�̴�.
// 3. ���� 8�ʸ� ���� ������ ����ä�� ��ƾ�ٸ� �̷ο� ���� �������� �ʰ� �ǰ�
// �������� ������ �����Ҽ� �ְ� �ȴ�.
// 4. ���� �ʴ� �ִ� 8���̴�.

// �̷��� dp�� �̿��Ͽ� �� ������ ���Ҽ� �ִ�.

// �ڼ��� ������ �ּ����� �����.

char board[8][8];
int trans[9][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {0, 0} }; // ���ʺ��� �ð��������.

// ���� �̵��� �����ϴ� �Լ�.
void MoveWall()
{
    for (int i = 7; i > 0; --i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = board[i - 1][j];

    for (int i = 0; i < 8; ++i)
        board[0][i] = '.';
}

bool BFS()
{
    bool visit[8][8][9];
    memset(visit, false, sizeof(visit));
    visit[7][0][0] = true;
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(7, 0), 0));

    while (!que.empty())
    {
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int y = que.front().first.first;
            int x = que.front().first.second;
            int cost = que.front().second;
            que.pop();

            // 8�ʸ� ��Ƽ��´ٸ� ��� ���� ��������Ƿ� ������ �̵��� �����ϴ�.
            if (cost >= 8)
                return true;

            // ���� ������ ���� ������ �����ٸ� ���̻��� �̵��� �Ұ����ϴ�.
            if (board[y][x] == '#')
                continue;

            // �̵��Ҽ� �ִ� ���� ��� �õ��غ���.
            for (int i = 0; i < 9; ++i)
            {
                int dy = y + trans[i][0];
                int dx = x + trans[i][1];

                // ������ ������Ű�� �̵����� ������ ��������.
                if (dy < 0 || dy > 7 || dx < 0 || dx > 7 || board[dy][dx] == '#' || visit[dy][dx][cost + 1])
                    continue;

                // �������� 8�� ������ �����Ͽ��ٸ� true�� ��ȯ�ϸ� �Լ��� ������.
                if (dy == 0 && dx == 7)
                    return true;

                visit[dy][dx][cost + 1] = true;
                que.push(make_pair(make_pair(dy, dx), cost + 1));
            }
        }

        // ���⼭ ��ĭ�� ���� �̵�.
        MoveWall();
    }

    return false;
}

void MakeAnswer()
{
    bool answer = BFS();

    cout << (answer ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}