#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// ����� BFS��������, ��Ʈ����ũ�� �߰��Ǿ���. ���� ���� ��湮�� ���� ������ ���� ���¿����� ��湮��
// ������� �ʴ´�. �� ���°� �ٷ� ���� ������ ĭ�� �����̸� �̰��� ����� ��Ʈ����ũ�� ó���Ѵ�. ������ ĭ��
// �ִ� 10���̱⿡ int ���� �ϳ��ε� ����ߴ�. vector�� ����ؼ� ������ ĭ�� �� ������ ��ǥ�� ������ ��
// �Ź� �̵� �� ������ ĭ�� ���� ������ ����� �ڷḦ �̿��ؼ� ��Ʈ����ũ�� �����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

// que�� �� ����ü. ���� ��ǥ�� ��Ʈ����ũ�� ������.
struct pos
{
    int y;
    int x;
    int mask;
};

char board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int w, h;
// ���� ����.
pair<int, int> from;
// ������ ĭ�� ��ǥ��.
vector<pair<int, int>> d;

void BFS()
{
    queue<pos> que;
    // ó���� ������ ĭ�� ������ 0�ϼ��ۿ� ������ ���� 1���� �÷�������.
    que.push(pos{ from.first, from.second, 0 });
    // ����Ѵ�� ��ǥ�Ӹ� �ƴ϶� ��Ʈ����ũ���� ����Ͽ� ��湮�� ���´�.
    bool visit[20][20][(1 << 10)] = { false, };
    visit[from.first][from.second][0] = true;
    int answer = -1, vsize = d.size();

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

            // ��� ������ĭ�� �湮�Ͽ�����
            if (mask == ((1 << vsize) - 1))
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ������ �̰����� ��� ������ �ɾ�������� 'x'ĭ�� �湮�Ҷ����� �̰����� ��� ó���Ҽ� ���⿡
                // if���� �ѷ� ����������. ��Ʈ����ũ ó���� ���� ���ڴ� ��ǥ�� �迭���� ��������� ó���ϱ�
                // ����ϱ� �����̴�.
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || board[ny][nx] == 'x')
                    continue;
                int nmask = mask;
                if (board[ny][nx] == '*')
                {
                    int idx = -1;
                    // vector�� ��ȸ�ϸ� ���� ������ĭ�� �ε������� ���Ѵ�.
                    for (int j = 0; j < d.size(); ++j)
                    {
                        if (d[j].first == ny && d[j].second == nx)
                        {
                            idx = j;
                            break;
                        }
                    }
                    // ��Ʈ����ũ ����.
                    nmask |= (1 << idx);
                }
                // ���� ���·� �̹� �湮�� ��ǥ�� ��湮�ߴٸ� �����Ѵ�.
                if (visit[ny][nx][nmask])
                    continue;
                visit[ny][nx][nmask] = true;
                que.push(pos{ ny, nx, nmask });
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        d.clear();
        string str;
        for (int i = 0; i < h; ++i)
        {
            cin >> str;
            for (int j = 0; j < w; ++j)
            {
                board[i][j] = str[j];
                if (board[i][j] == 'o')
                    from = make_pair(i, j);
                else if (board[i][j] == '*')
                    d.push_back(make_pair(i, j));
            }
        }
        BFS();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}