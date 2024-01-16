#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 별것 아닌 BFS문제인데 정점 2개를 연동시켜야 해서 괜히 헤맨 문제다.
// 특히 방문 여부를 체크하는 bool 배열도 연동되어야 하기 때문에 2차원 배열 2개가 아닌
// 4차원 배열 하나로 묶어야 한다.

// 자세한 설명은 주석으로 남긴다.

struct point
{
    int zero_y;
    int zero_x;
    int one_y;
    int one_x;
};

char board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌, 상, 우, 하
int N, M;
point from;

void BFS()
{
    queue<point> que;
    que.push(from);
    // 상술한대로 2개의 정점이 연동되기 때문에 그 방문여부도 하나의 4차원 배열로 연동되어야 한다.
    bool visit[20][20][20][20];
    memset(visit, false, sizeof(visit));
    visit[from.zero_y][from.zero_x][from.one_y][from.one_x] = true;
    int answer = 0;

    while (!que.empty() && answer < 10)
    {
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int zero_y = que.front().zero_y;
            int zero_x = que.front().zero_x;
            int one_y = que.front().one_y;
            int one_x = que.front().one_x;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                bool zero_over = false;
                bool one_over = false;

                // 각 정점들의 이동.
                int nz_y = zero_y + rot[i][0];
                int nz_x = zero_x + rot[i][1];
                int no_y = one_y + rot[i][0];
                int no_x = one_x + rot[i][1];

                // 둘중 하나만 배열값을 벗어난다면 최종값 answer를 출력하고 탈출한다.
                if (nz_y < 0 || nz_y >= N || nz_x < 0 || nz_x >= M)
                    zero_over = true;
                if (no_y < 0 || no_y >= N || no_x < 0 || no_x >= M)
                    one_over = true;
                if (zero_over || one_over)
                {
                    if (zero_over && one_over)
                    {
                        continue;
                    }
                    else
                    {
                        cout << answer << '\n';
                        return;
                    }
                }
                if (visit[nz_y][nz_x][no_y][no_x])
                    continue;
                // 현재 위치가 벽이라면 이전값을, 그렇지 않다면 현재값으로 방문 여부를 갱신하고 큐에 넣는다.
                // 다만 현재 위치가 벽이라면 rot[][] 값을 다시 제거해서 뒤로 후진시키는 방법도 있다.
                pair<int, int> next_zero = board[nz_y][nz_x] == '#' ? make_pair(zero_y, zero_x) :
                    make_pair(nz_y, nz_x);
                pair<int, int> next_one = board[no_y][no_x] == '#' ? make_pair(one_y, one_x) :
                    make_pair(no_y, no_x);
                visit[next_zero.first][next_zero.second][next_one.first][next_one.second] = true;
                que.push(point{ next_zero.first, next_zero.second, next_one.first,
                              next_one.second });
            }
        }
    }
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
    string str;
    bool isFind = false;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'o')
            {
                if (!isFind)
                {
                    from.zero_y = i;
                    from.zero_x = j;
                    isFind = true;
                }
                else
                {
                    from.one_y = i;
                    from.one_x = j;
                }
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}