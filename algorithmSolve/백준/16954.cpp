#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// BFS�� �̿��� �׷��� ������.
// ģ���ϰԵ� ����� ���� �̵��ϴ��� ���� ���� �̵��ϴ��������� �˷��־���.
// Ǯ�̴� �����ϰ� ūƲ�� ���ڸ� ������ ����.

// 1. ����� ���� �����ϼ� �ִ� ������ �����ϴ� �̵��� �Ѵ�. �̶� �������� �����ߴٸ� true�� ��ȯ��ä �Լ��� ������.
// 2. ���� �̵��Ѵ�.
// 3. �ݺ��Ѵ�.

// �ٸ� �Ѱ��� ������ �־��µ� ó������ �� ��ǥ�� dp�� �����߾���. ������
// ������ �ִ´ٴ��� �ϴ� ������ ���� �������� �ʾұ⿡ dp�� ���ݴ�.
// �� ��� que���� ������ ������ �Ͼ �ӵ��� �������� �뷮�� ��������.
// �� �ذ� ����� ���� Ǯ�̿� �ִ�.

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
    queue<pair<int, int>> que;
    que.push(make_pair(7, 0));

    while (!que.empty())
    {
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // ���� ������ ���� ������ �����ٸ� ���̻��� �̵��� �Ұ����ϴ�.
            if (board[y][x] == '#')
                continue;

            // �̵��Ҽ� �ִ� ���� ��� �õ��غ���.
            for (int i = 0; i < 9; ++i)
            {
                int dy = y + trans[i][0];
                int dx = x + trans[i][1];

                // ������ ������Ű�� �̵����� ������ ��������.
                if (dy < 0 || dy > 7 || dx < 0 || dx > 7 || board[dy][dx] == '#')
                    continue;

                // �������� �����Ͽ��ٸ� true�� ��ȯ�ϸ� �Լ��� ������.
                if (dy == 0 && dx == 7)
                    return true;

                que.push(make_pair(dy, dx));
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