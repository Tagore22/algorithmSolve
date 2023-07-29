#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 무식할정도로 덕지덕지 붙은 문제다.
// 하나하나 보기에 어렵진 않으나 여러가지 조건이 많다.
// 문제에서 주어진 행동 순서는 다음과 같다.

// 1. 현재 주어진 방향대로 움직인다. 다만, 방향대로 움직였을때 배열값을 벗어난다면 방향을 반대로 바꾸어 이동한다.
// 2. 이동한 좌표가 y, x라고 할때 동서남북으로 이동하며 값이 y, x와 같은 모든칸 N개를 찾는다.
// 그 후 좌표의 점수 K와 N을 최종값 answer에 더한다.
// 3. 좌표 점수 K와 현재 주사위의 아래값 D를 비교하여 

// 3-1. K > D라면 시계 방향으로 회전한다.
// 3-2. K < D라면 시계 반대방향으로 회전한다.
// 3-3. K == D 즉, 그 이외에는 방향의 변동이 없다.

// 다음과 같은 규칙에 의해 다음 방향이 주어지며 그 이후는 1, 2, 3번을 K번 반복한다.

// 위 상술하였듯 어렵진 않으나 구현해야 할것이 많다. 정신만 잘 차리면 한번에 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[20][20];
int dice[6] = { 3, 4, 5, 2, 1, 6 }; // 초창기 주사위. 동, 서, 남, 북, 위, 아래 순서.
int trans[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // 동, 서, 남, 북 순서. 
bool visit[20][20];
int N, M, K, dir = 0; // 동쪽부터 시계 방향으로.
pair<int, int> pos;

// 현 좌표가 배열값을 벗어났는지 확인하는 함수.
bool CheckPos(pair<int, int> pos)
{
    int y = pos.first;
    int x = pos.second;

    return y < 0 || y >= N || x < 0 || x >= M ? false : true;
}

// 주사위의 이동을 구현하는 함수.
void MoveDice()
{
    // 동쪽으로 이동. 남쪽과 북쪽은 변동이 없다.
    if (dir == 0)
    {
        int prev_up = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[0];
        dice[0] = prev_up;
        ++pos.second;
    }
    // 남쪽으로 이동. 동쪽과 서쪽은 변동이 없다.
    else if (dir == 1)
    {
        int prev_up = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = prev_up;
        ++pos.first;
    }
    // 서쪽으로 이동. 남쪽과 북쪽은 변동이 없다.
    else if (dir == 2)
    {
        int prev_up = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = prev_up;
        --pos.second;
    }
    // 북쪽으로 이동. 동쪽과 서쪽은 변동이 없다.
    else
    {
        int prev_up = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[3];
        dice[3] = prev_up;
        --pos.first;
    }
}

// BFS를 이용하여 현재 좌표에서 얻을수 있는 점수를 계산하는 함수.
int CalPoint()
{
    queue<pair<int, int>> que;
    que.push(pos);
    memset(visit, false, sizeof(visit));
    visit[pos.first][pos.second] = true;
    int ans = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + trans[i][0];
            int dx = x + trans[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx] ||
                board[dy][dx] != board[pos.first][pos.second])
                continue;

            que.push(make_pair(dy, dx));
            visit[dy][dx] = true;
            ++ans;
        }
    }
    return board[pos.first][pos.second] * ans;
}

// 다음 방향을 구하는 함수. 미리 이동해보고 배열값을 벗어난다면 반대 방향으로 바꾼다.
void CalNextDir()
{
    int y = pos.first;
    int x = pos.second;

    if (dice[5] > board[y][x])
        dir = (dir + 1) % 4;
    else if (dice[5] < board[y][x])
        dir = (dir + 3) % 4;

    pair<int, int> new_pos = pos;
    if (dir == 0)
        ++new_pos.second;
    else if (dir == 1)
        ++new_pos.first;
    else if (dir == 2)
        --new_pos.second;
    else
        --new_pos.first;

    if (!CheckPos(new_pos))
        dir = (dir + 2) % 4;
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K; ++i)
    {
        MoveDice();
        answer += CalPoint();
        CalNextDir();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    pos = make_pair(0, 0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}