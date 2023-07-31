#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 문제가 참 지저분하게 덕지덕지 붙었다. 거의 누더기골렘인줄.
// 문제에서 주어졌듯 풀이의 큰틀은 다음과 같다.

// 1. 가로 혹은 세로로 길이 3인 통나무가 주어진다.
// 2. 위 아래 왼쪽 오른쪽으로 움직일수 있고 회전할수도 있다.
// 다만 움직이는 곳이 1이면 안된다.
// 3. 움직일수 있는 최소 동작의 수를 출력한다.

// 크게 보면 어렵지 않으나 작게 보면 세세히 구현하기 귀찮은 문제다.
// 하지만 집중해서 풀면 한번에 풀수 있다.
// 통나무의 위치를 파악할때 3가지 조건이 필요한데

// 1. y값(세로)
// 2. x값(가로)
// 3. bool값(세로인가?)

// 이 3가지이다. 중요한점은 통나무의 중심점을 위치로 잡아야한다는 것이다.
// 그래야 회전시 불필요하게 복잡한 계산을 하지 않아도 되기 때문이다.

// 자세한 설명은 주석으로 남긴다.

struct tree
{
    int y;
    int x;
    bool isvert;
};

char board[50][50];
pair<int, int> from, to; // 통나무의 첫번째 위치. 가로라면 가장 왼쪽이며 세로라면 가장 위쪽. (중심값)
bool f_vert, t_vert; // 통나무가 세로로 놓여있는가?
queue<tree> que;
bool visit[50][50][2];
int N;

// 통나무의 이동과 회전이 가능한지 모든 경우를 대입하는 함수.
void MoveAndRotate(int y, int x, bool isvert)
{
    if (isvert)
    {
        // 위로 이동.
        if (y - 2 >= 0 && !visit[y - 1][x][isvert] && board[y - 2][x] != '1')
        {
            visit[y - 1][x][isvert] = true;
            que.push(tree{ y - 1, x, isvert });
        }
        // 아래로 이동.
        if (y + 2 < N && !visit[y + 1][x][isvert] && board[y + 2][x] != '1')
        {
            visit[y + 1][x][isvert] = true;
            que.push(tree{ y + 1, x, isvert });
        }
        // 왼쪽으로 이동.
        if (board[y][x - 1] != '1' && board[y + 1][x - 1] != '1' && board[y - 1][x - 1] != '1'
            && !visit[y][x - 1][isvert] && x - 1 >= 0)
        {
            visit[y][x - 1][isvert] = true;
            que.push(tree{ y, x - 1, isvert });
        }
        // 오른쪽으로 이동.
        if (board[y][x + 1] != '1' && board[y + 1][x + 1] != '1' && board[y - 1][x + 1] != '1'
            && !visit[y][x + 1][isvert] && x + 1 < N)
        {
            visit[y][x + 1][isvert] = true;
            que.push(tree{ y, x + 1, isvert });
        }
        // 회전. isvert 변수가 반전된다.
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
        // 위로 이동.
        if (board[y - 1][x] != '1' && board[y - 1][x + 1] != '1' && board[y - 1][x - 1] != '1'
            && !visit[y - 1][x][isvert] && y - 1 >= 0)
        {
            visit[y - 1][x][isvert] = true;
            que.push(tree{ y - 1, x, isvert });
        }
        // 아래로 이동.
        if (board[y + 1][x] != '1' && board[y + 1][x + 1] != '1' && board[y + 1][x - 1] != '1'
            && !visit[y + 1][x][isvert] && y + 1 < N)
        {
            visit[y + 1][x][isvert] = true;
            que.push(tree{ y + 1, x, isvert });
        }
        // 왼쪽으로 이동.
        if (x - 2 >= 0 && !visit[y][x - 1][isvert] && board[y][x - 2] != '1')
        {
            visit[y][x - 1][isvert] = true;
            que.push(tree{ y, x - 1, isvert });
        }
        // 오른쪽으로 이동.
        if (x + 2 < N && !visit[y][x + 1][isvert] && board[y][x + 2] != '1')
        {
            visit[y][x + 1][isvert] = true;
            que.push(tree{ y, x + 1, isvert });
        }
        // 회전. isvert 변수가 반전된다.
        if (y - 1 >= 0 && y + 1 < N && board[y - 1][x] != '1' && board[y - 1][x - 1] != '1'
            && board[y - 1][x + 1] != '1' && board[y + 1][x] != '1' && board[y + 1][x - 1] != '1'
            && board[y + 1][x + 1] != '1' && !visit[y][x][!isvert])
        {
            visit[y][x][!isvert] = true;
            que.push(tree{ y, x, !isvert });
        }
    }
}

// 시작점부터 이동 및 회전할수 있는 모든 경우를 대입하여 도착점에 도달하는
// 최소 행위수를 반환한다. 도달할수 없을시 0을 반환.
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

            // 여기서 상하좌우 4방향의 이동과 회전을 해본다.
            MoveAndRotate(y, x, isvert);
        }
    }
    // 모든 경우를 대입했음에도 도착할수 없다.
    return 0;
}

void MakeAnswer()
{
    // 시작점과 도착점의 세로여부 및 중심점을 구한다.
    // 애시당초 시작점과 도착점의 맨 위 혹은 맨 왼쪽 위치를 저장한 상태이기 때문에
    // y + 1의 값을 비교하여 중심점을 구할수 있다.
    int y = from.first;
    int x = from.second;
    // 바로 아래가 'B'라면 시작 통나무는 세로 형태다.
    if (board[y + 1][x] == 'B')
    {
        f_vert = true;
        ++from.first;
    }
    // 그렇지 않다면 시작 통나무는 가로 형태다.
    else
    {
        f_vert = false;
        ++from.second;
    }

    y = to.first;
    x = to.second;
    // 바로 아래가 'E'라면 도착 통나무는 세로 형태다.
    if (board[y + 1][x] == 'E')
    {
        t_vert = true;
        ++to.first;
    }
    // 그렇지 않다면 도착 통나무는 가로 형태다.
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
    // N x N 크기의 값들을 입력받되, 가장 첫번째로 'B'인 값과 'E'인 값의
    // 좌표들을 저장한다.(맨 위 혹은 맨 왼쪽)
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