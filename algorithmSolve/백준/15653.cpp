#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 어려운 개념은 아니지만 쉬운게 얽혀있는 삼성문제 같은 느낌이었다. 엄청 오래걸렸다;
// 한번 설계를 잘못하면 엄청 헤매는 그런 문제였다. 문제 자체는 쉽다. 규칙을 나열하자면 다음과 같다.

// 1. 구슬을 움직인다. 벽에 도달하거나 또다른 구슬에 도달할때까지 무한히 움직인다.
// 2. 만약 이번 움직임에서 파란색 구슬이 구멍으로 빠지게 된다면 무조건 실패한다. 오직 빨간 구슬만이 빠져야한다.

// 특히나 주의했던 부분은 두 구슬이 같은 라인에 존재할때이다. 예를 들어 파란 구슬이 3, 3이고, 빨간 구슬이 3, 2일때
// 오른쪽으로 움직인다면 무조건 파란구슬이 먼저 움직이게 된다. 빨간 구슬이 먼저 움직이게 된다면 바로 오른쪽에 파란구슬이
// 있기에 더 움직일수 없기 때문이다. 이러한 부분이 꽤나 복잡하게 다가왔다. 내가 푼 풀이를 정리하자면 다음과 같다.

// 1. 상술한대로 각 구슬의 위치에 따라 어떠한 방향에서는 빨간 구슬이, 어떨때에는 파란 구슬이 먼저 움직인다.
// 2. 구멍을 감지해야하기 때문에 한칸씩 더이상 움직일수 없을때 까지 이동한다.
// 3. 모든 이동이 끝난후에 각 구슬이 구멍에 빠졌는지 확인한다.
// 3-1. 파란색 구슬이 빠졌거나 두 구슬의 위치가 이미 방문했던 위치라면 구슬의 위치의 값을 되돌린다.
// 3-2. 빨간색 구슬만이 빠졌다면 정답이므로 여태까지 움직인 횟수를 출력하고 탈출한다.
// 3-3. 모두 아니라면 새로운 위치값을 que에 넣고 구슬의 위치의 값을 되돌린다.

// 여러므로 복잡한 문제였다. 후술하겠으나 한가지를 빠뜨려서 엄청 헤맸다. 그래도 풀어서 다행이다.
// 자세한 설명은 주석으로 남긴다.

// 각 구슬의 위치값. que에 넣어야 하기에 새로운 구조체를 만들어야했다.
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

// 모든 이동을 계산하여 최소값을 출력하는 함수.
void BFS()
{
    queue<bead> que;
    // 초기 위치를 que에 집어넣고 방문 여부를 초기화한다.
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
            // 현재 구슬들의 위치의 값을 B와 R로 갱신한다.
            board[by][bx] = 'B';
            board[ry][rx] = 'R';
            // by ~ rx은 값이 변하기에 따로 저장해둔다.
            from = bead{ by, bx, ry, rx };

            // 좌, 상, 우, 하순으로 이동.
            // 좌.
            // 각 구슬이 구멍에 빠졌는지 체크하는 bool 변수.
            bool isROut = false;
            bool isBOut = false;
            // 좌측으로 움직일때 파란구슬이 더 왼쪽에 존재한다면 무조건 파란구슬이 먼저 움직여야 한다.
            // 아래도 동일하다.
            if (bx < rx)
            {
                // 파란 구슬의 왼쪽이 벽이 아니라면 계속 이동한다.
                while (board[by][bx - 1] != '#')
                {
                    // 현재 구슬의 값을 빈칸으로 갱신하고 좌표값을 바꾼다.
                    board[by][bx] = '.';
                    --bx;
                    // 이동한 곳이 구멍이라면 더이상 움직일수 없으므로 bool 변수를 갱신한후 탈출한다.
                    if (board[by][bx] == 'O')
                    {
                        isBOut = true;
                        break;
                    }
                    // 그렇지 않다면 계속 이동한다.
                    else
                    {
                        board[by][bx] = 'B';
                    }
                }
                // 두번째로 움직이는 구슬은 한가지 조건이 더 붙는데 벽뿐만 아니라 먼저 이동한 구슬이
                // 움직이려는 방향에 존재한다면 움직일수 없다. 이 조건은 같은 라인에 존재한다는 가정에만
                // 적용된다.
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
            // 파란구슬이 빠졌거나 이미 방문한 곳이라면 현재 구슬의 위치값을 변경만 한다.
            if (isBOut || visit[by][bx][ry][rx])
            {
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            // 파란구슬이 빠지지 않았고 방문한 곳이 아니며 빨간구슬이 빠졌다면 답을 찾았으므로
            // 움직인 횟수를 출력하고 탈출한다.
            else if (isROut)
            {
                cout << answer << '\n';
                return;
            }
            // 둘다 아니라면 그냥 새로운 위치에 방문한것이므로 위치값을 que에 넣고
            // 방문 여부를 갱신하며 구슬의 위치값을 변경한다.
            else
            {
                visit[by][bx][ry][rx] = true;
                que.push(bead{ by, bx, ry, rx });
                board[by][bx] = isBOut ? 'O' : '.';
                board[ry][rx] = isROut ? 'O' : '.';
            }
            // 상.
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
            // 우.
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
            // 하.
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
    // 모든 경우를 계산했음에도 빨간구슬이 빠지지 못했으므로 -1을 출력한다.
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