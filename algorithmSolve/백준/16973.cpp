#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// BFS를 약간 꼬아놓은 듯한 문제였다. 직사각형의 왼쪽 상단 좌표를 기준으로 하여 BFS 순회를 하되,
// 다음과 같은 것들을 처리해야한다.

// 1. 왼쪽 상단 좌표가 배열값을 벗어날을때 이외에 우측 하단 좌표 역시 배열값에서 벗어났나 확인해야한다.
// 2. 각 이동시 직사각형의 한쪽 변을 따라 '1'값이 존재하는지를 확인해야한다. 예를 들어
// 직사각형의 왼쪽 상단 좌표를 왼쪽으로 한칸 이동한다고 했을때 왼쪽 상단부터 왼쪽 하단까지 순회하며
// '1'값이 존재하는지를 확인해야한다. 이때, 다른 3변은 처리할 필요가 없다. 

// 상술한 2번의 처리가 까다로웠다. 
// 자세한 설명은 주석으로 남긴다.

char board[1001][1001];
// 4방향으로 이동시 좌표와, 그때 변을 순회하는 이동좌표.
// 0번째 이동인 왼쪽과 2번째 이동인 오른쪽은 가장 상단에서 아래쪽으로,
// 1번째 이동인 윗쪽과 3번째 이동인 아래쪽은 가장 왼쪽에서 오른쪽으로 이동하며 '1'이 존재하는지 확인한다.
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }, dir[2][2] = { {1, 0}, {0, 1} };
// 각 변을 순회할때 왼쪽 상단 좌표에서 초기 좌표까지 이동해야하는 값들.
int pos[4][2] = { {0, 0}, {0, 0}, {0, 1}, {1, 0} };
int N, M, H, W;
pair<int, int> from, to;

// 각 변을 순회하며 '1'이 존재하는지를 확인하는 함수.
bool CheckBorder(int y, int x, int idx)
{
    // 왼쪽 상단에서 순회를 시작하는 위치로 옮긴다.
    int ny = y + pos[idx][0] * (H - 1);
    int nx = x + pos[idx][1] * (W - 1);

    // 0번째, 2번째는 위에서 아래로 이동하며 1번째, 3번째는 왼쪽에서 오른쪽으로 이동한다.
    int len = idx % 2 == 0 ? H : W;
    for (int i = 0; i < len; ++i)
    {
        // '1'을 발견할시 벽에 걸려 이동하지 못함.
        if (board[ny][nx] == '1')
            return false;
        ny += dir[idx % 2][0];
        nx += dir[idx % 2][1];
    }
    // 이동 가능.
    return true;
}

// BFS 순회를 통해 이동할수 있는 모든 경우를 따진다.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    bool visit[1001][1001] = { false, };
    visit[from.first][from.second] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            if (y == to.first && x == to.second)
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 왼쪽 상단값 혹은 우측 하단값이 배열값을 벗어났거나, 재방문시 혹은 테두리에
                // '1'이 발견될시 이동할수 없으므로 무시한다.
                if (ny <= 0 || ny + H - 1 > N || nx <= 0 || nx + W - 1 > M || visit[ny][nx] ||
                    !CheckBorder(ny, nx, i))
                    continue;

                que.push(make_pair(ny, nx));
                visit[ny][nx] = true;
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
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    cin >> H >> W >> from.first >> from.second >> to.first >> to.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}