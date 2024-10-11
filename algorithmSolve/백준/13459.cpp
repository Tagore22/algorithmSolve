#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 아마 3번째 비스므리한 문제를 풀고 있다. 기본적으로 구슬을 돌리는 것은 같으니
// 상세 조건만 확인하면 된다. 이번 조건은 10번 이하로 빨간 구슬을 빼낼수 있으면 1을,
// 그렇지 않다면 0을 출력하는것 뿐이기에 매우 간단했다.

// 자세한 설명은 주석으로 남긴다.

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

// 모든 경우를 계산하는 BFS 함수.
void BFS()
{
    queue<pos> que;
    que.push(pos{ red.first, red.second, blue.first, blue.second });
    visit[red.first][red.second][blue.first][blue.second] = true;
    int answer = 0;
    while (!que.empty())
    {
        ++answer;

        // 10번 이상 돌려도 불가능할때엔 while문을 탈출한다.
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
            // 좌.
            bool isROut = false, isBOut = false;
            board[ry][rx] = 'R';
            board[by][bx] = 'B';
            // 이동하려는 방향과 두 구슬의 위치를 파악하여 먼저 움직이는 구슬을 알아야한다.
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

            // 이 부분을 늘 주의하자. 파란색이 빠졌을 경우에는 파란색을 바꿀 필요가 없지만
            // 중복 방문일 경우 파란색의 위치 또한 복원되야한다.
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
            // 상.
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
            // 우.
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
            // 하.
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

    // 10번 이상이 되어 while문을 탈출하였을 경우 0을 출력한다.
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