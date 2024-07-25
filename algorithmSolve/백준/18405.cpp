#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 어렵지 않은 BFS문제였다. 다만, 출발 위치들을 파악하는것이 중요한것 같다.
// 각 칸들의 초기값들을 입력받을때 1이상이라면 바이러스의 시작점이라는 뜻이므로 vector의 배열을 이용하여
// 칸값에 해당하는 배열속에 모두 저장한후 나중에 queue에 순서대로 집어넣어주면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[201][201], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
vector<pair<int, int>> vir[1000];
int N, K, S, X, Y; // X가 세로축임을 잊지말것.

void BFS()
{
    queue<pair<int, int>> que;
    // 상술한대로 vector에 집어넣은 바이러스의 시작 위치를 queue에 넣는다. 값이 작은 순서부터 넣는다.
    for (int i = 1; i <= K; ++i)
        for (auto& p : vir[i])
            que.push(p);
    int time = 0;

    // time이 S값이 되었을때 반복을 멈춘다.
    while (time < S)
    {
        int qsize = que.size();
        ++time;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + rot[i][0];
                int ny = y + rot[i][1];

                // 배열값을 벗어났거나 이미 바이러스가 존재하는 칸이라면 무시한다.
                if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] != 0)
                    continue;
                que.push(make_pair(nx, ny));
                board[nx][ny] = board[x][y];
            }
        }
    }
}

void MakeAnswer()
{
    BFS();
    cout << board[X][Y] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] >= 1)
                vir[board[i][j]].push_back(make_pair(i, j));
        }
    cin >> S >> X >> Y;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}