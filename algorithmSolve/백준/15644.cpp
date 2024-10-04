#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 몇주전에 풀었던 문제의 이전 버전이다. 풀이 자체는 이미 알고 있지만 코드 자체가 길기 때문에
// 꽤나 시간이 걸렸고, 실수 한가지도 곁들인. ㅎㅎ;; 짧게 설명하자면 좌상우하 모두 이동시켜보되,
// 각 이동에서 빨간 구슬과 파란 구슬의 위치 역시 파악해야 한다. 예를 들어 왼쪽으로 이동시키는데
// 빨간 구슬이 파란 구슬의 바로 왼쪽에 붙어 있을때 빨간 구슬이 먼저 이동하면 제대로된 이동을 할수
// 없기 때문이다. 이점을 주의하면 된다. 기존에 15653번과 굉장히 풀이가 유사하다.

// 자세한 설명은 주석으로 남긴다.

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

// 모든 경우를 따지는 BFS 함수.
void BFS()
{
    queue<pos> que;
    que.push(pos{ red.first, red.second, blue.first, blue.second, "" });
    visit[red.first][red.second][blue.first][blue.second] = true;
    int answer = 0;

    while (!que.empty())
    {
        ++answer;
        // 문제에서 주어지듯 10번을 넘기면 -1을 출력한다. 이것 때문에 이전 버전인것 같다.
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

            // 좌.
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
            // 상술한 실수가 이부분이다. 조건은 파란 구슬이 빠졌거나 중복 방문인데
            // 파란 구슬이 빠졌을 경우에는 파란 구슬의 위치값이 변동되지 않아 파란 구슬의 좌표값을
            // 건드릴 필요가 없으나 중복 방문인 경우에는 파란 구슬의 위치가 변동되었을 가능성이 있기에
            // 반드시 파란 구슬의 좌표값까지 원래대로 복원시켜야 한다. 그런데 이부분이 빠져있었다.
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
    // 여기 이부분도 중요하다. 만약 불가능하면서 그 움직임이 채 10번이 안될 경우
    // 아무것도 출력이 안된다. 
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