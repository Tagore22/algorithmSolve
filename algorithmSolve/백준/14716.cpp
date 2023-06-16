#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 평범한 BFS문제이다. 다만 평소에도 그렇듯이 방문 여부를 사용하는 bool 타입 배열을
// 기존 board값을 변경시키므로써 대체할수 있다.
// 또한 난 8ms가 나왔는데 4ms 코드들과 비교해도 별로 차이가 없는데 뭐가 차이나는지를 모르겠다.
// 사소한 차이에서 비롯된것같다. 그리 차이가 크지 않으니 무시하자.

// 자세한 설명은 주석으로 남긴다.

bool board[250][250];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} }; // 좌부터 시계방향.
int M, N;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    board[y][x] = false;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // 이번엔 좌 상 우 하 4방향이 아닌 대각선까지 8방향이다.
        for (int i = 0; i < 8; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= M || dx < 0 || dx >= N || !board[dy][dx])
                continue;

            // 상술하였듯 기존 값을 변경시키므로써 이후 중복 방문 여부를 체크할수 있다.
            board[dy][dx] = false;
            que.push(make_pair(dy, dx));
        }
    }
}

void MakeAnswer()
{
    int answer = 0;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j])
            {
                ++answer;
                BFS(i, j);
            }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}