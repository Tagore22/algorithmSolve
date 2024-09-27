#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ����� ������ �ƴ����� ����� �����ִ� �Ｚ���� ���� �����̾���. ��û �����ɷȴ�;
// �ѹ� ���踦 �߸��ϸ� ��û ��Ŵ� �׷� ��������. ���� ��ü�� ����. ��Ģ�� �������ڸ� ������ ����.

// 1. ������ �����δ�. ���� �����ϰų� �Ǵٸ� ������ �����Ҷ����� ������ �����δ�.
// 2. ���� �̹� �����ӿ��� �Ķ��� ������ �������� ������ �ȴٸ� ������ �����Ѵ�. ���� ���� �������� �������Ѵ�.

// Ư���� �����ߴ� �κ��� �� ������ ���� ���ο� �����Ҷ��̴�. ���� ��� �Ķ� ������ 3, 3�̰�, ���� ������ 3, 2�϶�
// ���������� �����δٸ� ������ �Ķ������� ���� �����̰� �ȴ�. ���� ������ ���� �����̰� �ȴٸ� �ٷ� �����ʿ� �Ķ�������
// �ֱ⿡ �� �����ϼ� ���� �����̴�. �̷��� �κ��� �ϳ� �����ϰ� �ٰ��Դ�. ���� Ǭ Ǯ�̸� �������ڸ� ������ ����.

// 1. ����Ѵ�� �� ������ ��ġ�� ���� ��� ���⿡���� ���� ������, ������� �Ķ� ������ ���� �����δ�.
// 2. ������ �����ؾ��ϱ� ������ ��ĭ�� ���̻� �����ϼ� ������ ���� �̵��Ѵ�.
// 3. ��� �̵��� �����Ŀ� �� ������ ���ۿ� �������� Ȯ���Ѵ�.
// 3-1. �Ķ��� ������ �����ų� �� ������ ��ġ�� �̹� �湮�ߴ� ��ġ��� ������ ��ġ�� ���� �ǵ�����.
// 3-2. ������ �������� �����ٸ� �����̹Ƿ� ���±��� ������ Ƚ���� ����ϰ� Ż���Ѵ�.
// 3-3. ��� �ƴ϶�� ���ο� ��ġ���� que�� �ְ� ������ ��ġ�� ���� �ǵ�����.

// �����Ƿ� ������ ��������. �ļ��ϰ����� �Ѱ����� ���߷��� ��û ��̴�. �׷��� Ǯ� �����̴�.
// �ڼ��� ������ �ּ����� �����.

// �� ������ ��ġ��. que�� �־�� �ϱ⿡ ���ο� ����ü�� �������ߴ�.
struct bead
{
    int by;
    int bx;
    int ry;
    int rx;
};

char board[10][10];
bool visit[10][10][10][10] = { false, };
bead from;
int N, M;

// ��� �̵��� ����Ͽ� �ּҰ��� ����ϴ� �Լ�.
void BFS()
{
    queue<bead> que;
    // �ʱ� ��ġ�� que�� ����ְ� �湮 ���θ� �ʱ�ȭ�Ѵ�.
    que.push(from);
    visit[from.by][from.bx][from.ry][from.rx] = true;
    int answer = 0;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int by = que.front().by;
            int bx = que.front().bx;
            int ry = que.front().ry;
            int rx = que.front().rx;
            que.pop();
            // ���� �������� ��ġ�� ���� B�� R�� �����Ѵ�.
            board[by][bx] = 'B';
            board[ry][rx] = 'R';
            // by ~ rx�� ���� ���ϱ⿡ ���� �����صд�.
            from = bead{ by, bx, ry, rx };

            // ��, ��, ��, �ϼ����� �̵�.
            // ��.
            // �� ������ ���ۿ� �������� üũ�ϴ� bool ����.
            bool isROut = false;
            bool isBOut = false;
            // �������� �����϶� �Ķ������� �� ���ʿ� �����Ѵٸ� ������ �Ķ������� ���� �������� �Ѵ�.
            // �Ʒ��� �����ϴ�.
            if (bx < rx)
            {
                // �Ķ� ������ ������ ���� �ƴ϶�� ��� �̵��Ѵ�.
                while (board[by][bx - 1] != '#')
                {
                    // ���� ������ ���� ��ĭ���� �����ϰ� ��ǥ���� �ٲ۴�.
                    board[by][bx] = '.';
                    --bx;
                    // �̵��� ���� �����̶�� ���̻� �����ϼ� �����Ƿ� bool ������ �������� Ż���Ѵ�.
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    // �׷��� �ʴٸ� ��� �̵��Ѵ�.
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
                // �ι�°�� �����̴� ������ �Ѱ��� ������ �� �ٴµ� ���Ӹ� �ƴ϶� ���� �̵��� ������
                // �����̷��� ���⿡ �����Ѵٸ� �����ϼ� ����. �� ������ ���� ���ο� �����Ѵٴ� ��������
                // ����ȴ�.
                while (board[ry][rx - 1] != '#' && board[ry][rx - 1] != 'B')
                {
                    board[ry][rx] = '.';
                    --rx;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
            }
            else
            {
                while (board[ry][rx - 1] != '#')
                {
                    board[ry][rx] = '.';
                    --rx;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
                while (board[by][bx - 1] != '#' && board[by][bx - 1] != 'R')
                {
                    board[by][bx] = '.';
                    --bx;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
            }
            // �Ķ������� �����ų� �̹� �湮�� ���̶�� ���� ������ ��ġ���� ���游 �Ѵ�.
            if (isBOut || visit[by][bx][ry][rx])
            {
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            // �Ķ������� ������ �ʾҰ� �湮�� ���� �ƴϸ� ���������� �����ٸ� ���� ã�����Ƿ�
            // ������ Ƚ���� ����ϰ� Ż���Ѵ�.
            else if (isROut)
            {
                cout << answer << '\n';
                return;
            }
            // �Ѵ� �ƴ϶�� �׳� ���ο� ��ġ�� �湮�Ѱ��̹Ƿ� ��ġ���� que�� �ְ�
            // �湮 ���θ� �����ϸ� ������ ��ġ���� �����Ѵ�.
            else
            {
                visit[by][bx][ry][rx] = true;
                que.push(bead{ by, bx, ry, rx });
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            // ��.
            by = from.by;
            bx = from.bx;
            ry = from.ry;
            rx = from.rx;
            isROut = false;
            isBOut = false;
            board[by][bx] = 'B';
            board[ry][rx] = 'R';
            if (by < ry)
            {
                while (board[by - 1][bx] != '#')
                {
                    board[by][bx] = '.';
                    --by;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
                while (board[ry - 1][rx] != '#' && board[ry - 1][rx] != 'B')
                {
                    board[ry][rx] = '.';
                    --ry;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
            }
            else
            {
                while (board[ry - 1][rx] != '#')
                {
                    board[ry][rx] = '.';
                    --ry;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
                while (board[by - 1][bx] != '#' && board[by - 1][bx] != 'R')
                {
                    board[by][bx] = '.';
                    --by;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
            }
            if (isBOut || visit[by][bx][ry][rx])
            {
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            else if (isROut)
            {
                cout << answer << '\n';
                return;
            }
            else
            {
                visit[by][bx][ry][rx] = true;
                que.push(bead{ by, bx, ry, rx });
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            // ��.
            by = from.by;
            bx = from.bx;
            ry = from.ry;
            rx = from.rx;
            isROut = false;
            isBOut = false;
            board[by][bx] = 'B';
            board[ry][rx] = 'R';
            if (bx > rx)
            {
                while (board[by][bx + 1] != '#')
                {
                    board[by][bx] = '.';
                    ++bx;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
                while (board[ry][rx + 1] != '#' && board[ry][rx + 1] != 'B')
                {
                    board[ry][rx] = '.';
                    ++rx;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
            }
            else
            {
                while (board[ry][rx + 1] != '#')
                {
                    board[ry][rx] = '.';
                    ++rx;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
                while (board[by][bx + 1] != '#' && board[by][bx + 1] != 'R')
                {
                    board[by][bx] = '.';
                    ++bx;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
            }
            if (isBOut || visit[by][bx][ry][rx])
            {
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            else if (isROut)
            {
                cout << answer << '\n';
                return;
            }
            else
            {
                visit[by][bx][ry][rx] = true;
                que.push(bead{ by, bx, ry, rx });
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            // ��.
            by = from.by;
            bx = from.bx;
            ry = from.ry;
            rx = from.rx;
            isROut = false;
            isBOut = false;
            board[by][bx] = 'B';
            board[ry][rx] = 'R';
            if (by > ry)
            {
                while (board[by + 1][bx] != '#')
                {
                    board[by][bx] = '.';
                    ++by;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
                while (board[ry + 1][rx] != '#' && board[ry + 1][rx] != 'B')
                {
                    board[ry][rx] = '.';
                    ++ry;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
            }
            else
            {
                while (board[ry + 1][rx] != '#')
                {
                    board[ry][rx] = '.';
                    ++ry;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    else
                    {
                        board[ry][rx] = 'R';
                    }
                }
                while (board[by + 1][bx] != '#' && board[by + 1][bx] != 'R')
                {
                    board[by][bx] = '.';
                    ++by;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
            }
            if (isBOut || visit[by][bx][ry][rx])
            {
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            else if (isROut)
            {
                cout << answer << '\n';
                return;
            }
            else
            {
                visit[by][bx][ry][rx] = true;
                que.push(bead{ by, bx, ry, rx });
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
        }
    }
    // ��� ��츦 ����������� ���������� ������ �������Ƿ� -1�� ����Ѵ�.
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
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                from.ry = i;
                from.rx = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                from.by = i;
                from.bx = j;
                board[i][j] = '.';
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}