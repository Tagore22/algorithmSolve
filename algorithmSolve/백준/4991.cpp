#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 평범한 BFS문제지만, 비트마스크가 추가되었다. 같은 곳을 재방문할 수가 있지만 같은 상태에서의 재방문은
// 허락되지 않는다. 이 상태가 바로 남은 더러운 칸의 개수이며 이것을 상술한 비트마스크로 처리한다. 더러운 칸은
// 최대 10개이기에 int 변수 하나로도 충분했다. vector를 사용해서 더러운 칸의 총 개수와 좌표를 저장한 후
// 매번 이동 시 더러운 칸을 만날 때마다 저장된 자료를 이용해서 비트마스크를 갱신한다.

// 자세한 설명은 주석으로 남긴다.

// que에 들어갈 구조체. 각각 좌표와 비트마스크를 가진다.
struct pos
{
    int y;
    int x;
    int mask;
};

char board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int w, h;
// 시작 지점.
pair<int, int> from;
// 더러운 칸의 좌표들.
vector<pair<int, int>> d;

void BFS()
{
    queue<pos> que;
    // 처음에 더러운 칸은 무조건 0일수밖에 없으며 이후 1개씩 늘려나간다.
    que.push(pos{ from.first, from.second, 0 });
    // 상술한대로 좌표뿐만 아니라 비트마스크까지 사용하여 재방문을 막는다.
    bool visit[20][20][(1 << 10)] = { false, };
    visit[from.first][from.second][0] = true;
    int answer = -1, vsize = d.size();

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

            // 모든 더러운칸을 방문하였을때
            if (mask == ((1 << vsize) - 1))
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 원래는 이곳에서 모든 조건을 걸어버리지만 'x'칸을 방문할때에는 이곳에서 모두 처리할수 없기에
                // if문이 둘로 나뉘어졌다. 비트마스크 처리를 먼저 하자니 좌표가 배열값을 벗어났을때를 처리하기
                // 곤란하기 때문이다.
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || board[ny][nx] == 'x')
                    continue;
                int nmask = mask;
                if (board[ny][nx] == '*')
                {
                    int idx = -1;
                    // vector를 순회하며 현재 더러운칸의 인덱스값을 구한다.
                    for (int j = 0; j < d.size(); ++j)
                    {
                        if (d[j].first == ny && d[j].second == nx)
                        {
                            idx = j;
                            break;
                        }
                    }
                    // 비트마스크 갱신.
                    nmask |= (1 << idx);
                }
                // 같은 상태로 이미 방문한 좌표를 재방문했다면 무시한다.
                if (visit[ny][nx][nmask])
                    continue;
                visit[ny][nx][nmask] = true;
                que.push(pos{ ny, nx, nmask });
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        d.clear();
        string str;
        for (int i = 0; i < h; ++i)
        {
            cin >> str;
            for (int j = 0; j < w; ++j)
            {
                board[i][j] = str[j];
                if (board[i][j] == 'o')
                    from = make_pair(i, j);
                else if (board[i][j] == '*')
                    d.push_back(make_pair(i, j));
            }
        }
        BFS();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}