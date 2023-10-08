#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 간단한 BFS문제다. 시작점부터 도착점까지 BFS순회를 하여 도착할수 있다면 최단거리를,
// 도착할수 없다면 Trapped!를 출력하면 된다.
// 다만 3차원 배열을 써야했기에 평소보단 복잡했다.

// 자세한 설명은 주석으로 남긴다.

char board[30][30][30];
int rot[6][3] = { {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0} }; // 동, 서, 남, 북, 상, 하.
int L, R, C;

struct point
{
    int l;
    int r;
    int c;
};

point from, to;

// 시작점부터 모든 순회를 하는 함수.
int BFS()
{
    queue<point> que;
    que.push(from);
    bool visit[30][30][30];
    memset(visit, false, sizeof(visit));
    visit[from.l][from.r][from.c] = true;
    int ans = -1;

    // 현재지점부터 이동거리를 1씩 늘려가며 순회를 한다.
    // 다만 한가지 주의해야하는 점은 현재 큐안에 들어있는 원소들만을 순회하고 다음으로 넘어가 반복해야한다는 것이다.
    while (!que.empty())
    {
        // {0, 0, 0}에서 이동을 한다고 하였을때 갈수 있는 방향은 총 6가지이다.(주위에 '#'가 없다고 가정)
        // 모든 이동은 각각 거리가 1씩인데 현재 큐안에 있는 것만을 순회할때 1씩 늘려야 한다.
        // 그렇지 않으면 위 이동을 구현하였을때 1이 6개의 이동이 아닌 1 ~ 6의 이동이 된다.
        int qsize = que.size();
        ++ans;
        for (int iter = 0; iter < qsize; ++iter)
        {
            point here = que.front();
            que.pop();

            // 도착점에 도달하였다면 거리를 출력한다.
            if (here.l == to.l && here.r == to.r && here.c == to.c)
                return ans;

            // 총 6방향중 이동가능한 모든 방향으로 이동해본다.
            for (int i = 0; i < 6; ++i)
            {
                int dz = here.l + rot[i][0];
                int dy = here.r + rot[i][1];
                int dx = here.c + rot[i][2];

                // 범위값을 벗어났거나, 이미 도달한 지역이거나, 막혀있다면 이동하지 못한다.
                if (0 > dz || L <= dz || 0 > dy || R <= dy || 0 > dx || C <= dx ||
                    visit[dz][dy][dx] || board[dz][dy][dx] == '#')
                    continue;

                // 방문여부를 갱신하고 큐에 넣는다.
                visit[dz][dy][dx] = true;
                que.push(point{ dz, dy, dx });
            }
        }
    }
    // 도달하지 못한다면 -1을 출력하여 따로 체크한다.
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