#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �Ƹ� 3��° �񽺹Ǹ��� ������ Ǯ�� �ִ�. �⺻������ ������ ������ ���� ������
// �� ���Ǹ� Ȯ���ϸ� �ȴ�. �̹� ������ 10�� ���Ϸ� ���� ������ ������ ������ 1��,
// �׷��� �ʴٸ� 0�� ����ϴ°� ���̱⿡ �ſ� �����ߴ�.

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    int ry;
    int rx;
    int by;
    int bx;
};
char board[10][10];
bool visit[10][10][10][10] = { false, };
int N, M;
pair<int, int> red, blue;

// ��� ��츦 ����ϴ� BFS �Լ�.
void BFS()
{
    queue<pos> que;
    que.push(pos{ red.first, red.second, blue.first, blue.second });
    visit[red.first][red.second][blue.first][blue.second] = true;
    int answer = 0;
    while (!que.empty())
    {
        ++answer;

        // 10�� �̻� ������ �Ұ����Ҷ��� while���� Ż���Ѵ�.
        if (answer > 10)
            break;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int ry = que.front().ry;
            int rx = que.front().rx;
            int by = que.front().by;
            int bx = que.front().bx;
            que.pop();
            pos prev = pos{ ry, rx, by, bx };
            // ��.
            bool isROut = false, isBOut = false;
            board[ry][rx] = 'R';
            board[by][bx] = 'B';
            // �̵��Ϸ��� ����� �� ������ ��ġ�� �ľ��Ͽ� ���� �����̴� ������ �˾ƾ��Ѵ�.
            if (rx < bx)
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
                    board[ry][rx] = 'R';
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
                    board[by][bx] = 'B';
                }
            }
            else
            {
                while (board[by][bx - 1] != '#')
                {
                    board[by][bx] = '.';
                    --bx;
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    board[by][bx] = 'B';
                }
                while (board[ry][rx - 1] != '#' && board[ry][rx - 1] != 'B')
                {
                    board[ry][rx] = '.';
                    --rx;
                    if (board[ry][rx] == 'O')
                    {
                        isROut = true;
                        break;
                    }
                    board[ry][rx] = 'R';
                }
            }

            // �� �κ��� �� ��������. �Ķ����� ������ ��쿡�� �Ķ����� �ٲ� �ʿ䰡 ������
            // �ߺ� �湮�� ��� �Ķ����� ��ġ ���� �����Ǿ��Ѵ�.
            if (isBOut || visit[ry][rx][by][bx])
            {
                board[ry][rx] = isROut ? board[ry][rx] : '.';
                board[by][bx] = isBOut ? board[by][bx] : '.';
            }
            else if (isROut)
            {
                cout << 1 << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx });
                visit[ry][rx][by][bx] = true;
                board[ry][rx] = '.';
                board[by][bx] = '.';
            }
            // ��.
            isROut = false, isBOut = false;
            ry = prev.ry;
            rx = prev.rx;
            by = prev.by;
            bx = prev.bx;
            board[ry][rx] = 'R';
            board[by][bx] = 'B';
            if (ry < by)
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
                    board[ry][rx] = 'R';
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
                    board[by][bx] = 'B';
                }
            }
            else
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
                    board[by][bx] = 'B';
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
                    board[ry][rx] = 'R';
                }
            }
            if (isBOut || visit[ry][rx][by][bx])
            {
                board[ry][rx] = isROut ? board[ry][rx] : '.';
                board[by][bx] = isBOut ? board[by][bx] : '.';
            }
            else if (isROut)
            {
                cout << 1 << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx });
                visit[ry][rx][by][bx] = true;
                board[ry][rx] = '.';
                board[by][bx] = '.';
            }
            // ��.
            isROut = false, isBOut = false;
            ry = prev.ry;
            rx = prev.rx;
            by = prev.by;
            bx = prev.bx;
            board[ry][rx] = 'R';
            board[by][bx] = 'B';
            if (rx > bx)
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
                    board[ry][rx] = 'R';
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
                    board[by][bx] = 'B';
                }
            }
            else
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
                    board[by][bx] = 'B';
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
                    board[ry][rx] = 'R';
                }
            }
            if (isBOut || visit[ry][rx][by][bx])
            {
                board[ry][rx] = isROut ? board[ry][rx] : '.';
                board[by][bx] = isBOut ? board[by][bx] : '.';
            }
            else if (isROut)
            {
                cout << 1 << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx });
                visit[ry][rx][by][bx] = true;
                board[ry][rx] = '.';
                board[by][bx] = '.';
            }
            // ��.
            isROut = false, isBOut = false;
            ry = prev.ry;
            rx = prev.rx;
            by = prev.by;
            bx = prev.bx;
            board[ry][rx] = 'R';
            board[by][bx] = 'B';
            if (ry > by)
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
                    board[ry][rx] = 'R';
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
                    board[by][bx] = 'B';
                }
            }
            else
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
                    board[by][bx] = 'B';
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
                    board[ry][rx] = 'R';
                }
            }
            if (isBOut || visit[ry][rx][by][bx])
            {
                board[ry][rx] = isROut ? board[ry][rx] : '.';
                board[by][bx] = isBOut ? board[by][bx] : '.';
            }
            else if (isROut)
            {
                cout << 1 << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx });
                visit[ry][rx][by][bx] = true;
                board[ry][rx] = '.';
                board[by][bx] = '.';
            }
        }
    }

    // 10�� �̻��� �Ǿ� while���� Ż���Ͽ��� ��� 0�� ����Ѵ�.
    cout << 0 << '\n';
}
void MakeAnswer()
{
    BFS();
}
void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                red = make_pair(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                blue = make_pair(i, j);
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