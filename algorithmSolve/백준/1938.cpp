#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ������ �� �������ϰ� �������� �پ���. ���� �����������.
// �������� �־����� Ǯ���� ūƲ�� ������ ����.

// 1. ���� Ȥ�� ���η� ���� 3�� �볪���� �־�����.
// 2. �� �Ʒ� ���� ���������� �����ϼ� �ְ� ȸ���Ҽ��� �ִ�.
// �ٸ� �����̴� ���� 1�̸� �ȵȴ�.
// 3. �����ϼ� �ִ� �ּ� ������ ���� ����Ѵ�.

// ũ�� ���� ����� ������ �۰� ���� ������ �����ϱ� ������ ������.
// ������ �����ؼ� Ǯ�� �ѹ��� Ǯ�� �ִ�.
// �볪���� ��ġ�� �ľ��Ҷ� 3���� ������ �ʿ��ѵ�

// 1. y��(����)
// 2. x��(����)
// 3. bool��(�����ΰ�?)

// �� 3�����̴�. �߿������� �볪���� �߽����� ��ġ�� ��ƾ��Ѵٴ� ���̴�.
// �׷��� ȸ���� ���ʿ��ϰ� ������ ����� ���� �ʾƵ� �Ǳ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

struct tree
{
    int y;
    int x;
    bool isvert;
};

char board[50][50];
pair<int, int> from, to; // �볪���� ù��° ��ġ. ���ζ�� ���� �����̸� ���ζ�� ���� ����. (�߽ɰ�)
bool f_vert, t_vert; // �볪���� ���η� �����ִ°�?
queue<tree> que;
bool visit[50][50][2];
int N;

// �볪���� �̵��� ȸ���� �������� ��� ��츦 �����ϴ� �Լ�.
void MoveAndRotate(int y, int x, bool isvert)
{
    if (isvert)
    {
        // ���� �̵�.
        if (y - 2 >= 0 && !visit[y - 1][x][isvert] && board[y - 2][x] != '1')
        {
            visit[y - 1][x][isvert] = true;
            que.push(tree{ y - 1, x, isvert });
        }
        // �Ʒ��� �̵�.
        if (y + 2 < N && !visit[y + 1][x][isvert] && board[y + 2][x] != '1')
        {
            visit[y + 1][x][isvert] = true;
            que.push(tree{ y + 1, x, isvert });
        }
        // �������� �̵�.
        if (board[y][x - 1] != '1' && board[y + 1][x - 1] != '1' && board[y - 1][x - 1] != '1'
            && !visit[y][x - 1][isvert] && x - 1 >= 0)
        {
            visit[y][x - 1][isvert] = true;
            que.push(tree{ y, x - 1, isvert });
        }
        // ���������� �̵�.
        if (board[y][x + 1] != '1' && board[y + 1][x + 1] != '1' && board[y - 1][x + 1] != '1'
            && !visit[y][x + 1][isvert] && x + 1 < N)
        {
            visit[y][x + 1][isvert] = true;
            que.push(tree{ y, x + 1, isvert });
        }
        // ȸ��. isvert ������ �����ȴ�.
        if (x - 1 >= 0 && x + 1 < N && board[y][x - 1] != '1' && board[y + 1][x - 1] != '1'
            && board[y - 1][x - 1] != '1' && board[y][x + 1] != '1' && board[y + 1][x + 1] != '1'
            && board[y - 1][x + 1] != '1' && !visit[y][x][!isvert])
        {
            visit[y][x][!isvert] = true;
            que.push(tree{ y, x, !isvert });
        }
    }
    else
    {
        // ���� �̵�.
        if (board[y - 1][x] != '1' && board[y - 1][x + 1] != '1' && board[y - 1][x - 1] != '1'
            && !visit[y - 1][x][isvert] && y - 1 >= 0)
        {
            visit[y - 1][x][isvert] = true;
            que.push(tree{ y - 1, x, isvert });
        }
        // �Ʒ��� �̵�.
        if (board[y + 1][x] != '1' && board[y + 1][x + 1] != '1' && board[y + 1][x - 1] != '1'
            && !visit[y + 1][x][isvert] && y + 1 < N)
        {
            visit[y + 1][x][isvert] = true;
            que.push(tree{ y + 1, x, isvert });
        }
        // �������� �̵�.
        if (x - 2 >= 0 && !visit[y][x - 1][isvert] && board[y][x - 2] != '1')
        {
            visit[y][x - 1][isvert] = true;
            que.push(tree{ y, x - 1, isvert });
        }
        // ���������� �̵�.
        if (x + 2 < N && !visit[y][x + 1][isvert] && board[y][x + 2] != '1')
        {
            visit[y][x + 1][isvert] = true;
            que.push(tree{ y, x + 1, isvert });
        }
        // ȸ��. isvert ������ �����ȴ�.
        if (y - 1 >= 0 && y + 1 < N && board[y - 1][x] != '1' && board[y - 1][x - 1] != '1'
            && board[y - 1][x + 1] != '1' && board[y + 1][x] != '1' && board[y + 1][x - 1] != '1'
            && board[y + 1][x + 1] != '1' && !visit[y][x][!isvert])
        {
            visit[y][x][!isvert] = true;
            que.push(tree{ y, x, !isvert });
        }
    }
}

// ���������� �̵� �� ȸ���Ҽ� �ִ� ��� ��츦 �����Ͽ� �������� �����ϴ�
// �ּ� �������� ��ȯ�Ѵ�. �����Ҽ� ������ 0�� ��ȯ.
int BFS()
{
    que.push(tree{ from.first, from.second, f_vert });
    memset(visit, false, sizeof(visit));
    visit[from.first][from.second][f_vert] = true;

    int ans = -1;
    while (!que.empty())
    {
        ++ans;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            bool isvert = que.front().isvert;
            que.pop();

            if (y == to.first && x == to.second && isvert == t_vert)
                return ans;

            // ���⼭ �����¿� 4������ �̵��� ȸ���� �غ���.
            MoveAndRotate(y, x, isvert);
        }
    }
    // ��� ��츦 ������������ �����Ҽ� ����.
    return 0;
}

void MakeAnswer()
{
    // �������� �������� ���ο��� �� �߽����� ���Ѵ�.
    // �ֽô��� �������� �������� �� �� Ȥ�� �� ���� ��ġ�� ������ �����̱� ������
    // y + 1�� ���� ���Ͽ� �߽����� ���Ҽ� �ִ�.
    int y = from.first;
    int x = from.second;
    // �ٷ� �Ʒ��� 'B'��� ���� �볪���� ���� ���´�.
    if (board[y + 1][x] == 'B')
    {
        f_vert = true;
        ++from.first;
    }
    // �׷��� �ʴٸ� ���� �볪���� ���� ���´�.
    else
    {
        f_vert = false;
        ++from.second;
    }

    y = to.first;
    x = to.second;
    // �ٷ� �Ʒ��� 'E'��� ���� �볪���� ���� ���´�.
    if (board[y + 1][x] == 'E')
    {
        t_vert = true;
        ++to.first;
    }
    // �׷��� �ʴٸ� ���� �볪���� ���� ���´�.
    else
    {
        t_vert = false;
        ++to.second;
    }

    int answer = BFS();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    bool isfrom = false;
    bool isto = false;
    // N x N ũ���� ������ �Է¹޵�, ���� ù��°�� 'B'�� ���� 'E'�� ����
    // ��ǥ���� �����Ѵ�.(�� �� Ȥ�� �� ����)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (!isfrom && board[i][j] == 'B')
            {
                isfrom = true;
                from = make_pair(i, j);
            }
            else if (!isto && board[i][j] == 'E')
            {
                isto = true;
                to = make_pair(i, j);
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}