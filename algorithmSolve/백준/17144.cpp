#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 평범한 시뮬레이션 문제이다. 주어지는 과정은 

// 1. 먼지의 확산.
// 2. 공기청정기의 행동.

// 이 둘뿐이고 각각 복잡하지 않기에 구현이 어렵지 않다.

int board[50][50], temp[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int R, C, T, air; // 공기청정기의 아래부분.


// 먼지가 확산되는 함수. 다만 실제 배열값에 확산되면 다음 좌표의 확산부터 값이 꼬이기 때문에
// 다른 대체용 배열에 확산값을 몰아놓고 확산이 끝나면 현재 배열값과 더해서 새로운 값으로 갱신해야한다.
void RenewDust(int y, int x)
{
    int dy, dx, move_num = 0;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || (dy == air - 1 && dx == 0) ||
            (dy == air && dx == 0))
            continue;

        ++move_num;
        // 확산값은 대체용 배열에 더해져야한다.
        temp[dy][dx] += board[y][x] / 5;
    }
    board[y][x] -= board[y][x] / 5 * move_num;
}


// 모든 배열의 확산을 구현한 함수.
void SpreadDust()
{
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != 0)
                RenewDust(i, j);

    // 각 대체용 배열에 주어진 확산된 먼지들과 현재 배열에 줄어든 먼지들을 더해 
    // 새로운 먼지값들을 갱신한다.
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            board[i][j] += temp[i][j];
}

// 반시계 방향으로 도는 함수.
void MoveCounter()
{
    int y = air - 2;
    int x = 0;
    while (y > 0)
    {
        board[y][x] = board[y - 1][x];
        --y;
    }

    while (x < C - 1)
    {
        board[y][x] = board[y][x + 1];
        ++x;
    }

    while (y < air - 1)
    {
        board[y][x] = board[y + 1][x];
        ++y;
    }

    while (x > 1)
    {
        board[y][x] = board[y][x - 1];
        --x;
    }

    board[y][x] = 0;
}

// 시계 방향으로 도는 함수.
void MoveClock()
{
    int y = air + 1;
    int x = 0;
    while (y < R - 1)
    {
        board[y][x] = board[y + 1][x];
        ++y;
    }

    while (x < C - 1)
    {
        board[y][x] = board[y][x + 1];
        ++x;
    }

    while (y > air)
    {
        board[y][x] = board[y - 1][x];
        --y;
    }

    while (x > 1)
    {
        board[y][x] = board[y][x - 1];
        --x;
    }

    board[y][x] = 0;
}

// 최종답을 구하는 함수. 이미 구현된 모든 함수들을 사용하여
// 시뮬레이션을 실행한다.
void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        SpreadDust();
        MoveCounter();
        MoveClock();
    }

    int answer = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            answer += board[i][j];

    // 공기청정기가 각각 -1, -1을 가지고 있기에 2를 더해준다.
    cout << answer + 2 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
                air = i;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}