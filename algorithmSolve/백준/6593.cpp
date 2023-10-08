#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ������ BFS������. ���������� ���������� BFS��ȸ�� �Ͽ� �����Ҽ� �ִٸ� �ִܰŸ���,
// �����Ҽ� ���ٸ� Trapped!�� ����ϸ� �ȴ�.
// �ٸ� 3���� �迭�� ����߱⿡ ��Һ��� �����ߴ�.

// �ڼ��� ������ �ּ����� �����.

char board[30][30][30];
int rot[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} }; // ��, ��, ��, ��, ��, ��.
int L, R, C;

struct point
{
    int l;
    int r;
    int c;
};

point from, to;

// ���������� ��� ��ȸ�� �ϴ� �Լ�.
int BFS()
{
    queue<point> que;
    que.push(from);
    bool visit[30][30][30];
    memset(visit, false, sizeof(visit));
    visit[from.l][from.r][from.c] = true;
    int ans = -1;

    // ������������ �̵��Ÿ��� 1�� �÷����� ��ȸ�� �Ѵ�.
    // �ٸ� �Ѱ��� �����ؾ��ϴ� ���� ���� ť�ȿ� ����ִ� ���ҵ鸸�� ��ȸ�ϰ� �������� �Ѿ �ݺ��ؾ��Ѵٴ� ���̴�.
    while (!que.empty())
    {
        // {0, 0, 0}���� �̵��� �Ѵٰ� �Ͽ����� ���� �ִ� ������ �� 6�����̴�.(������ '#'�� ���ٰ� ����)
        // ��� �̵��� ���� �Ÿ��� 1���ε� ���� ť�ȿ� �ִ� �͸��� ��ȸ�Ҷ� 1�� �÷��� �Ѵ�.
        // �׷��� ������ �� �̵��� �����Ͽ����� 1�� 6���� �̵��� �ƴ� 1 ~ 6�� �̵��� �ȴ�.
        int qsize = que.size();
        ++ans;
        for (int iter = 0; iter < qsize; ++iter)
        {
            point here = que.front();
            que.pop();

            // �������� �����Ͽ��ٸ� �Ÿ��� ����Ѵ�.
            if (here.l == to.l && here.r == to.r && here.c == to.c)
                return ans;

            // �� 6������ �̵������� ��� �������� �̵��غ���.
            for (int i = 0; i < 6; ++i)
            {
                int dz = here.l + rot[i][0];
                int dy = here.r + rot[i][1];
                int dx = here.c + rot[i][2];

                // �������� ����ų�, �̹� ������ �����̰ų�, �����ִٸ� �̵����� ���Ѵ�.
                if (0 > dz || L <= dz || 0 > dy || R <= dy || 0 > dx || C <= dx ||
                    visit[dz][dy][dx] || board[dz][dy][dx] == '#')
                    continue;

                // �湮���θ� �����ϰ� ť�� �ִ´�.
                visit[dz][dy][dx] = true;
                que.push(point{ dz, dy, dx });
            }
        }
    }
    // �������� ���Ѵٸ� -1�� ����Ͽ� ���� üũ�Ѵ�.
    return -1;
}

void MakeAnswer()
{
    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            return;

        for (int i = 0; i < L; ++i)
            for (int j = 0; j < R; ++j)
                for (int k = 0; k < C; ++k)
                {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S')
                        from = point{ i, j, k };
                    else if (board[i][j][k] == 'E')
                        to = point{ i, j, k };
                }
        int answer = BFS();
        if (answer == -1)
            cout << "Trapped!" << '\n';
        else
            cout << "Escaped in " << answer << " minute(s)." << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}