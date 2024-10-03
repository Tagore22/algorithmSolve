#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// '이게 40퍼를 넘는다고?' 라고 생각할정도로 어려운 문제였다. 물론 나에게 어려운 문제였을수도 있다만.
// 최소값고 그래프에 대한 언급으로 BFS문제임을 알수 있다. 다만 평범한 BFS와는 확연히 다른데
// 방문했던 곳을 또 방문해야한다던가, 중복 방문한 곳이 'X'라서 이것을 두번 더하지 않아야 한다던가 등이 있기 
// 때문이다. 위에 두가지 조건을 해결해가며 도착점에 도달하는 최소값을 출력하면 된다. 후술하겠으나
// 치명적인 실수 두가지로 10분정도 해맸다. 그래도 홀로 잘 해결했으니 다행이다.

// 자세한 설명은 주석으로 남긴다.
// P.S 기존과는 방문여부를 확인하는 visit 배열이 2차원이 아닌 3차원인데
// 3번째 비트마스크 때문이다. 똑같이 'X' 2곳을 방문후 어떠한 지점에 도달한다고 했을때
// 방문했던 'X' 2곳이 같다면 상관없지만 다를수도 있다. 그렇기 때문에 단순 방문한 수가 아닌
// 비트마스크를 이용하여 어느곳을 몇군데 방문했는지까지 계산해야 한다.

struct pos
{
    int y;
    int x;
    int mask; // 비트마스크.
};

char board[50][50];
bool visit[50][50][35] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
pair<int, int> from, to;
pair<int, int> es[5];
int N, M, num = 0;

// 모든 'X'를 방문하였는지 확인하는 함수. 비트마스크를 이용한다.
// 최대 50, 50크기를 어떻게 비트마스크화 하는지 애매했는데 모든 좌표값이 아닌
// 'X'인 지점들만을 파악하면 된다.
bool CheckMask(int mask)
{
    // 최대 5번을 순회하며 각 'X'가 방문되었는지, 즉 비트마스크의 모든 비트가 1인지
    // 확인한다.
    for (int i = 0; i < num; ++i)
        // 현재 비트가 1이 아니라면 실패한다.
        if ((mask & (1 << i)) == 0)
            return false;
    return true;
}

void BFS()
{
    queue<pos> que;
    // 처음에는 그 어떤 'X'도 방문하지 못했으므로 비트마스크는 0으로 초기화된다.
    que.push(pos{ from.first, from.second, 0 });
    visit[from.first][from.second][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int mask = que.front().mask;
            que.pop();

            // 도착점에 도달했으며 모든 'X'를 방문했다면 이동 횟수를 출력하고 탈출한다.
            if (y == to.first && x == to.second && CheckMask(mask))
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 치명적인 실수 첫번째이다. 이동하는 곳이 벽이라면 무시해야한다. 이건 인지했었다.
                // 다만 좌표값을 벗어날때를 생각하지 못했는데 모든 벽으로 둘러쌓여있다고 생각했기 때문이다.
                // 하지만 실제로는 그러지 않았는데 도착점이 가장 바깥쪽에 존재하는 경우 그 너머로 이동하는
                // 경우가 생기기에 반드시 좌표값 확인을 해야한다.
                if (board[ny][nx] == '#' || ny < 0 || ny >= M || nx < 0 || nx >= N)
                {

                }
                // 이동하는 곳이 'X'일때.
                else if (board[ny][nx] == 'X')
                {
                    int idx;
                    // 최대 5번 순회하며 현재 'X'의 순서를 찾는다.
                    for (int j = 0; j < num; ++j)
                    {
                        if (es[j].first == ny && es[j].second == nx)
                        {
                            idx = j;
                            break;
                        }
                    }
                    // 치명적인 실수 두번째. 새로운 nmask를 쓰지 않고 기존에 mask의 값을 변경시켰었다.
                    // 예를 들어 0번째 좌측이동에서 mask를 변경시킨후 1번째 위쪽이동할때 이미 mask는 이상하게
                    // 변경됬기에 제대로 된 정답이 출력되지 않는다. 따라서 아래 풀이처럼 새로운 값을 만들어서
                    // 기존 mask의 수정된값을 할당한후 이용해야한다.
                    int nmask = (mask & (1 << idx)) == 0 ? (mask | (1 << idx)) : mask;

                    // 방문하지 않은 상태라면 큐에 추가하고 방문여부를 갱신한다.
                    if (!visit[ny][nx][nmask])
                    {
                        visit[ny][nx][nmask] = true;
                        que.push(pos{ ny, nx, nmask });
                    }
                }
                // 'S' 혹은 '.'일때.
                else
                {
                    // 방문하지 않은 상태라면 큐에 추가하고 방문여부를 갱신한다.
                    if (!visit[ny][nx][mask])
                    {
                        visit[ny][nx][mask] = true;
                        que.push(pos{ ny, nx, mask });
                    }
                }
            }
        }
    }
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
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
            {
                from = make_pair(i, j);
            }
            else if (board[i][j] == 'E')
            {
                to = make_pair(i, j);
            }
            else if (board[i][j] == 'X')
            {
                es[num] = make_pair(i, j);
                ++num;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}