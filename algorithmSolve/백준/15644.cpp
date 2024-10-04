#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �������� Ǯ���� ������ ���� �����̴�. Ǯ�� ��ü�� �̹� �˰� ������ �ڵ� ��ü�� ��� ������
// �ϳ� �ð��� �ɷȰ�, �Ǽ� �Ѱ����� �����. ����;; ª�� �������ڸ� �»���� ��� �̵����Ѻ���,
// �� �̵����� ���� ������ �Ķ� ������ ��ġ ���� �ľ��ؾ� �Ѵ�. ���� ��� �������� �̵���Ű�µ�
// ���� ������ �Ķ� ������ �ٷ� ���ʿ� �پ� ������ ���� ������ ���� �̵��ϸ� ����ε� �̵��� �Ҽ�
// ���� �����̴�. ������ �����ϸ� �ȴ�. ������ 15653���� ������ Ǯ�̰� �����ϴ�.

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    int ry;
    int rx;
    int by;
    int bx;
    string str;
};

char board[10][10];
bool visit[10][10][10][10] = { false, };
int N, M;
pair<int, int> red, blue;

// ��� ��츦 ������ BFS �Լ�.
void BFS()
{
    queue<pos> que;
    que.push(pos{ red.first, red.second, blue.first, blue.second, "" });
    visit[red.first][red.second][blue.first][blue.second] = true;
    int answer = 0;

    while (!que.empty())
    {
        ++answer;
        // �������� �־����� 10���� �ѱ�� -1�� ����Ѵ�. �̰� ������ ���� �����ΰ� ����.
        if (answer > 10)
        {
            cout << -1 << '\n';
            return;
        }
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int ry = que.front().ry;
            int rx = que.front().rx;
            int by = que.front().by;
            int bx = que.front().bx;
            string str = que.front().str;
            que.pop();

            pos prev = pos{ ry, rx, by, bx, str };

            // ��.
            bool isROut = false, isBOut = false;
            board[ry][rx] = 'R';
            board[by][bx] = 'B';
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
            // ����� �Ǽ��� �̺κ��̴�. ������ �Ķ� ������ �����ų� �ߺ� �湮�ε�
            // �Ķ� ������ ������ ��쿡�� �Ķ� ������ ��ġ���� �������� �ʾ� �Ķ� ������ ��ǥ����
            // �ǵ帱 �ʿ䰡 ������ �ߺ� �湮�� ��쿡�� �Ķ� ������ ��ġ�� �����Ǿ��� ���ɼ��� �ֱ⿡
            // �ݵ�� �Ķ� ������ ��ǥ������ ������� �������Ѿ� �Ѵ�. �׷��� �̺κ��� �����־���.
            if (isBOut || visit[ry][rx][by][bx])
            {
                board[ry][rx] = isROut ? board[ry][rx] : '.';
                board[by][bx] = isBOut ? board[by][bx] : '.';
            }
            else if (isROut)
            {
                cout << answer << '\n';
                cout << str + "L" << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx, str + "L" });
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
                cout << answer << '\n';
                cout << str + "U" << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx, str + "U" });
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
                cout << answer << '\n';
                cout << str + "R" << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx, str + "R" });
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
                cout << answer << '\n';
                cout << str + "D" << '\n';
                return;
            }
            else
            {
                que.push(pos{ ry, rx, by, bx, str + "D" });
                visit[ry][rx][by][bx] = true;
                board[ry][rx] = '.';
                board[by][bx] = '.';
            }
        }
    }
    // ���� �̺κе� �߿��ϴ�. ���� �Ұ����ϸ鼭 �� �������� ä 10���� �ȵ� ���
    // �ƹ��͵� ����� �ȵȴ�. 
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