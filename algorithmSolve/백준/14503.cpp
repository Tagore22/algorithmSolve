#include <iostream>
#include <cstring>

using namespace std;

// 풀이
// DFS문제에서 약간 다른점이 추가된 문제이다.
// 문제에서 주어진 청소기의 행동 방식을 다시 살펴보자.

// 1. 현재 위치가 청소되지 않은 방이라면 청소한다.
// 2. 이후 4번에 걸쳐 반시계 방향으로 90도만큼 회전하고 바라보는 방향의 칸이 청소되지 않은 빈칸이라면 전진하여 1번을 반복한다.
// 3. 인근 4칸 모두 청소가 된 빈칸이거나 벽이라 나아갈수 없다면 현재 바라보고 있는 방향에서 뒤로 한칸 후진한다. 이때 빈칸일 경우
// 에만 후진할수 있으며, 뒤가 벽이라면 청소기는 작동을 종료한다.

// 즉, 평범하게 좌우상하를 움직이는 DFS를 구현하되, 4방향 모두 나아갈수 없다면 현재 방향에서 뒤를 확인하고 빈칸이라면 후진 아니라면
// 종료하면 된다. 다만 어쩔수없이 방문하였던 곳을 다시 방문하는 경우가 있기에 bool 타입 배열로 방문의 여부를 갱신하여 답이 중복되지
// 않게 주의해야한다.


// 청소기의 현 좌표와 방향을 담는 구조체.
struct cleaner
{
    int y;
    int x;
    int dir;
};

int board[50][50];
bool check[50][50];
int rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
cleaner from;
int N, M, answer = 0;
bool isend = false;


// DFS 함수. 위에 상술한 청소기의 행동이 구현되어 있다.
void DFS(cleaner cur)
{

    // 뒤가 벽이여서 후진할수 없기에 종료된 상황. 아무것도 하지 않고 종료한다.
    if (isend)
        return;

    // 후진하는 경우 어쩔수 없이 방문한 곳을 다시 방문하게 된다. 이 경우 답이 중복될수도 있기에 if 조건문으로 사전에 방지한다.
    if (!check[cur.y][cur.x])
    {
        check[cur.y][cur.x] = true;
        ++answer;
    }

    // 다음 청소기의 좌표와 방향을 담는 변수. DFS순회가 끝나고 다시 이곳으로 콜백되었을때 청소기의 상태를 복구시켜야 하는데,
    // 변수의 크기도 크지 않고 int 변수 3개만 들어있기에 그냥 그때그때마다 새로 생성하여 처리하였다.
    cleaner next;

    // 위치좌표는 그때그때마다 새로 변하지만 방향만큼은 미리 초기화되어 계속 변하여야한다.
    next.dir = cur.dir;
    for (int i = 0; i < 4; ++i)
    {
        next.dir = next.dir - 1 >= 0 ? next.dir - 1 : 3;
        next.y = cur.y + rot[next.dir][0];
        next.x = cur.x + rot[next.dir][1];

        if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M || check[next.y][next.x] ||
            board[next.y][next.x] == 1)
            continue;

        DFS(next);
    }

    // 4방향의 순회 이후 무조건 더이상 나아갈수 없기에 후진하거나 종료한다. -1을 곱하여 현재 방향의 반대에 해당하는
    // 뒤의 좌표를 구하고 뒤가 벽이라면 종료하고, 빈칸이라면 후진한다.
    next.y = rot[next.dir][0] * -1 + cur.y;
    next.x = rot[next.dir][1] * -1 + cur.x;
    if (board[next.y][next.x] != 1)
        DFS(next);
    else
        isend = true;
}

void MakeAnswer()
{
    DFS(from);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    cin >> from.y >> from.x >> from.dir;
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