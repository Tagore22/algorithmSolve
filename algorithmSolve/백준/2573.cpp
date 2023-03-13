#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 생각할게 많은 문제이다. 그러나 풀이 방식은 막상 어렵지 않다.

// 1. 현재 빙산의 조각수를 구한다.
// 1-1. 만약 2개 이상이라면 지금의 턴수를(초기값은 0) 출력한다.
// 1-2. 만약 0개라면 0을 출력한다.
// 1-3. 아직도 1개라면 그 다음으로 넘어간다.
// 2. 1년이 지나고 빙산의 변화가 생긴다(녹는다). 그 변화를 구현한 함수를 호출하여 빙산의 높이값들을 갱신하고 다시 
// 조각수를 구한다.
// 3. 반복.

// 각 함수들은 주석을 참고할것.

int board[300][300], temp[300][300];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
bool check[300][300];
int N, M;

// 빙산의 조각수를 찾기 위해 필요한 DFS함수. 상하좌우로 이동하며 빙산의 높이가 1이상이며 아직 방문하지 않은 모든 곳을 방문한다.
void DFS(int y, int x)
{
    check[y][x] = true;
    int dy, dx;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] == 0 || check[dy][dx])
            continue;

        DFS(dy, dx);
    }
}

// 빙산의 조각수를 구하는 함수. DFS가 호출될때마다 1개의 빙산 조각이 있음을 이용하여 빙산의 조각수를 반환한다.
int CalIceberg()
{
    memset(check, false, sizeof(check));
    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0 && !check[i][j])
            {
                ++ans;
                DFS(i, j);
            }
    return ans;
}

// 1년이 지나 빙산이 변화하는 것을 구현하는 함수. 배열을 순회하며 각 빙산의 상하좌우중 바닷물인 곳을 또 다른 배열 temp에 저장하였다가
// 배열의 순회가 끝난후 다시 순회하며 board를 갱신한다. 순회 >> 순회 >> 갱신이 아닌 순회 >> 갱신 >> 순회는 오류가 발생할수 있다.
// 예를 들어 문제의 그림 2번에 (3, 1)인 값 5를 보면 1년이 지나 3이 되어야 하지만 순회 >> 갱신 >> 순회로 하면 윗값인 1이 0이 되어
// 막상 5를 갱신할때 바닷물의 위치가 2가 아닌 3이 되어 2가 된다. 그래서 순회 >> 순회 >> 갱신의 순서로 구현해야 한다.
void MinusHeight()
{
    int dy, dx, minus;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0)
            {
                minus = 0;
                for (int iter = 0; iter < 4; ++iter)
                {
                    dy = i + rot[iter][0];
                    dx = j + rot[iter][1];

                    if (dy < 0 || dy >= N || dx < 0 || dx >= M)
                        continue;

                    minus = board[dy][dx] == 0 ? minus + 1 : minus;
                }

                temp[i][j] = minus;
            }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0)
                board[i][j] = max(0, board[i][j] - temp[i][j]);
}

// 최종답을 구하는 함수. 원리는 위 상술한 바와 같다.
void MakeAnswer()
{
    int time = 0, now;
    while (true)
    {
        // 1. 현 상황에서 빙산의 조각수를 구한다.
        now = CalIceberg();
        // 1-1. 빙산의 수가 2개 이상이라면 현재 시간(time)을 출력한다.
        if (now > 1)
        {
            cout << time << '\n';
            return;
        }
        // 1-2. 빙산의 수가 0개라면 0을 출력한다.
        else if (now == 0)
        {
            cout << 0 << '\n';
            return;
        }
        // 1-3. 아직도 한개(그 이외값은 1밖에 없음)라면 다음으로 넘어간다.
        // 2. 1년이 지나고(++time), 빙산의 변화값을 갱신한다. 그 후 반복.
        ++time;
        MinusHeight();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}