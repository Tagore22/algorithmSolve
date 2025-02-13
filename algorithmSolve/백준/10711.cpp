#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 정답율이 보여주듯 발상을 떠올리기 힘든 문제였다. 처음에는 모래성을 큐에 넣어 주위의 모래수를 찾으려 했으나
// 이러면 파도에 버티는 모래성이 계속 큐에 존재하게 되어 기존의 BFS의 이점을 볼수 없게 된다.
// BFS의 기본. 즉, 현재가 아닌 그 다음을 큐에 넣고 계속 나아가는 것이었다. 결과적으로 모래성이 아닌
// 모래를 큐에 넣어야했는데 주위 8방향의 모래수에 의해 모래성이 존재하거나 사라지기 때문이다. 모래의 위치에서
// 8방향을 순회하여 모래성인 곳이 존재한다면 그 튼튼함을 1 줄이는 식으로 영향을 구현할수 있다.
// 이번턴에 튼튼함이 0이 된다면 모래가 되는 식으로 구현하면 된다.

// 역발상을 잊지 말자. 반대로도 생각해볼것.
// 자세한 설명은 주석으로 남긴다.

char board[1000][1000];
int sand[1000][1000];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int H, W;
queue<pair<int, int>> que;

void BFS()
{
    // 모래에서 시작한다.
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (sand[i][j] == 0)
                que.push(make_pair(i, j));

    int answer = -1;
    while (!que.empty())
    {
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for (int i = 0; i < 8; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 범위값을 벗어났거나 이미 모래라면 무시한다.
                if (ny < 0 || ny >= H || nx < 0 || nx >= W || sand[ny][nx] == 0)
                    continue;
                // 튼튼함을 1줄이고 모래가 된다면 큐에 넣는다.
                --sand[ny][nx];
                if (sand[ny][nx] == 0)
                    que.push(make_pair(ny, nx));
            }
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {

            cin >> board[i][j];
            if (board[i][j] == '.')
                sand[i][j] = 0;
            else
                sand[i][j] = board[i][j] - '0';
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}