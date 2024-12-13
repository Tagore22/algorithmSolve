#include <iostream>
#include <queue>

struct state
{
    int y;
    int x;
    int mask;
};

using namespace std;

// Ǯ��.
// �׷��� Ž�� ������ �̰����� �������� ��������. ������ �����ϱ⿡ �������� ��Ǯ������
// �׷��� ������ ������ �� Ǯ��´�. Ǯ�̴� ������ ����.

// 1. '0'���� �»���Ϸ� �̵��Ѵ�. �̶� �����̷��� ĭ�� '#'�̰ų� ���谡 ���� ���¶�� �̵��Ұ���.
// 2. ������ ������ ���� �ߺ� �湮�� ������ �ȴ�. A ~ F���� �ִ� 6�����ε� �̰��� ��Ÿ���� ���ؼ� ��Ʈ����ũ�� ����Ѵ�.
// 3. �湮�� ��Ʈ����ũ�� �̿��Ͽ� �ߺ� �湮�� ���ϱ� ������ �湮 ������ ���踦 ��Բ� �����ؾ� �Ѵ�.

// BFS�� �� ���ǵ��� �����ϸ� �ȴ�. ����Ѵ�� �����غ��̱� ������ ����� ���̶�� ���԰��� ������ �־��µ�
// �����ؼ� �׷��� �ǿܷ� ���� Ǯ�ȴ�. � ��Ȳ���� ���� ����.

// �ڼ��� ������ �ּ����� �����.

char board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> from;

// � ��ǥ y, x�� �湮�Ҽ� �ִ��� Ȯ���ϴ� �Լ�.
bool CanGo(int y, int x, int mask)
{
    // ���� A ~ F�϶��� ���踦 Ȯ���ϰ� �׷��� �ʴٸ� 
    // �湮�Ҽ� �ִ�. �����δ� '#'���� ���� �Ұ���������
    // �Լ� ȣ�� ���� if������ ��� �Ÿ��� ������ �Ű澲�� �ʴ´�.
    if ('A' <= board[y][x] && board[y][x] <= 'F')
    {
        int idx = board[y][x] - 'A';
        // �� �κп��� ��¦ �Ǽ��� �־���. mask�� (1 << idx)�� ���Ҷ�
        // ���ϴ� �κ��� �Ѵ� 1�̶�� �� ������� 1�� �ƴ� ��� ������.
        // �׷��� �񱳰��� 1���� Ȯ���ϰ� �־���. ��������.
        // �̹� ���踦 ������ �ִٸ� �湮�� �����ϴ�.
        if (mask & (1 << idx))
            return true;
        else
            return false;
    }
    return true;
}

void BFS()
{
    queue<state> que;
    que.push(state{ from.first, from.second, 0 });
    // ������ �ٸ����� Ǯ�̸� ���� ����� ��Ʈ����ũ�� �̿��� �迭�� ����. ������ �Ẹ�� ������ �����ߴ�.
    bool visit[50][50][1 << 6] = { false, };
    visit[from.first][from.second][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        // ������� ť�� ũ�⸦ ����ϴ� �Ʒ� ����� �������µ� ���̷��� �ߴ��� �����غ���
        // �̷��� ���� ������ �̵��� ���� ���� ť�ȿ� �����صξ�� �ߴ�. �׷��� ť�� ũ�⵵ Ŀ����
        // �ְ� ���µ� ���������� �̷��� ����������.
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int mask = que.front().mask;
            que.pop();

            // �� �κп��� ��¦ �Ǽ��� �־��µ� ó������ �Է¹����� '0'�� ������ from���� �����ѵ�
            // '1'�� ������ to�� �����߾���. ������ '1'�� ������ ������ �����Ҽ��� �־��⿡ 
            // �̷��� �ٲپ���ߴ�.
            if (board[y][x] == '1')
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ����Ѵ�� �湮�� ��Ʈ����ũ�� ���ϴµ� ���� �̵��� ��ǥ��
                // ������ �̸� ���踦 ���������� �����ؾ��Ѵ�.
                int nmask = mask;
                if ('a' <= board[ny][nx] && board[ny][nx] <= 'f')
                {
                    int idx = board[ny][nx] - 'a';
                    nmask |= (1 << idx);
                }
                // ��ǥ���� ����ų�, �ߺ� �湮�̰ų�, ���̰ų�, ���谡 �������� ������
                // �湮�Ҽ� ����.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx][nmask] ||
                    board[ny][nx] == '#' || !CanGo(ny, nx, nmask))
                    continue;
                que.push(state{ ny, nx, nmask });
                visit[ny][nx][nmask] = true;
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

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == '0')
                from = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}