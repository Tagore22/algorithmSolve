#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// '�̰� 40�۸� �Ѵ´ٰ�?' ��� ������������ ����� ��������. ���� ������ ����� ������������ �ִٸ�.
// �ּҰ��� �׷����� ���� ������� BFS�������� �˼� �ִ�. �ٸ� ����� BFS�ʹ� Ȯ���� �ٸ���
// �湮�ߴ� ���� �� �湮�ؾ��Ѵٴ���, �ߺ� �湮�� ���� 'X'�� �̰��� �ι� ������ �ʾƾ� �Ѵٴ��� ���� �ֱ� 
// �����̴�. ���� �ΰ��� ������ �ذ��ذ��� �������� �����ϴ� �ּҰ��� ����ϸ� �ȴ�. �ļ��ϰ�����
// ġ������ �Ǽ� �ΰ����� 10������ �ظ̴�. �׷��� Ȧ�� �� �ذ������� �����̴�.

// �ڼ��� ������ �ּ����� �����.
// P.S �������� �湮���θ� Ȯ���ϴ� visit �迭�� 2������ �ƴ� 3�����ε�
// 3��° ��Ʈ����ũ �����̴�. �Ȱ��� 'X' 2���� �湮�� ��� ������ �����Ѵٰ� ������
// �湮�ߴ� 'X' 2���� ���ٸ� ��������� �ٸ����� �ִ�. �׷��� ������ �ܼ� �湮�� ���� �ƴ�
// ��Ʈ����ũ�� �̿��Ͽ� ������� ��� �湮�ߴ������� ����ؾ� �Ѵ�.

struct pos
{
    int y;
    int x;
    int mask; // ��Ʈ����ũ.
};

char board[50][50];
bool visit[50][50][35] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
pair<int, int> from, to;
pair<int, int> es[5];
int N, M, num = 0;

// ��� 'X'�� �湮�Ͽ����� Ȯ���ϴ� �Լ�. ��Ʈ����ũ�� �̿��Ѵ�.
// �ִ� 50, 50ũ�⸦ ��� ��Ʈ����ũȭ �ϴ��� �ָ��ߴµ� ��� ��ǥ���� �ƴ�
// 'X'�� �����鸸�� �ľ��ϸ� �ȴ�.
bool CheckMask(int mask)
{
    // �ִ� 5���� ��ȸ�ϸ� �� 'X'�� �湮�Ǿ�����, �� ��Ʈ����ũ�� ��� ��Ʈ�� 1����
    // Ȯ���Ѵ�.
    for (int i = 0; i < num; ++i)
        // ���� ��Ʈ�� 1�� �ƴ϶�� �����Ѵ�.
        if ((mask & (1 << i)) == 0)
            return false;
    return true;
}

void BFS()
{
    queue<pos> que;
    // ó������ �� � 'X'�� �湮���� �������Ƿ� ��Ʈ����ũ�� 0���� �ʱ�ȭ�ȴ�.
    que.push(pos{ from.first, from.second, 0 });
    visit[from.first][from.second][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int mask = que.front().mask;
            que.pop();

            // �������� ���������� ��� 'X'�� �湮�ߴٸ� �̵� Ƚ���� ����ϰ� Ż���Ѵ�.
            if (y == to.first && x == to.second && CheckMask(mask))
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ġ������ �Ǽ� ù��°�̴�. �̵��ϴ� ���� ���̶�� �����ؾ��Ѵ�. �̰� �����߾���.
                // �ٸ� ��ǥ���� ������� �������� ���ߴµ� ��� ������ �ѷ��׿��ִٰ� �����߱� �����̴�.
                // ������ �����δ� �׷��� �ʾҴµ� �������� ���� �ٱ��ʿ� �����ϴ� ��� �� �ʸӷ� �̵��ϴ�
                // ��찡 ����⿡ �ݵ�� ��ǥ�� Ȯ���� �ؾ��Ѵ�.
                if (board[ny][nx] == '#' || ny < 0 || ny >= M || nx < 0 || nx >= N)
                {

                }
                // �̵��ϴ� ���� 'X'�϶�.
                else if (board[ny][nx] == 'X')
                {
                    int idx;
                    // �ִ� 5�� ��ȸ�ϸ� ���� 'X'�� ������ ã�´�.
                    for (int j = 0; j < num; ++j)
                    {
                        if (es[j].first == ny && es[j].second == nx)
                        {
                            idx = j;
                            break;
                        }
                    }
                    // ġ������ �Ǽ� �ι�°. ���ο� nmask�� ���� �ʰ� ������ mask�� ���� ������׾���.
                    // ���� ��� 0��° �����̵����� mask�� �����Ų�� 1��° �����̵��Ҷ� �̹� mask�� �̻��ϰ�
                    // �����⿡ ����� �� ������ ��µ��� �ʴ´�. ���� �Ʒ� Ǯ��ó�� ���ο� ���� ����
                    // ���� mask�� �����Ȱ��� �Ҵ����� �̿��ؾ��Ѵ�.
                    int nmask = (mask & (1 << idx)) == 0 ? (mask | (1 << idx)) : mask;

                    // �湮���� ���� ���¶�� ť�� �߰��ϰ� �湮���θ� �����Ѵ�.
                    if (!visit[ny][nx][nmask])
                    {
                        visit[ny][nx][nmask] = true;
                        que.push(pos{ ny, nx, nmask });
                    }
                }
                // 'S' Ȥ�� '.'�϶�.
                else
                {
                    // �湮���� ���� ���¶�� ť�� �߰��ϰ� �湮���θ� �����Ѵ�.
                    if (!visit[ny][nx][mask])
                    {
                        visit[ny][nx][mask] = true;
                        que.push(pos{ ny, nx, mask });
                    }
                }
            }
        }
    }
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
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
            {
                from = make_pair(i, j);
            }
            else if (board[i][j] == 'E')
            {
                to = make_pair(i, j);
            }
            else if (board[i][j] == 'X')
            {
                es[num] = make_pair(i, j);
                ++num;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}