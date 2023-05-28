#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 여러가지 복잡한 문제가 덕지덕지 기워진 삼성다운 문제다.
// 어려운 것은 전혀 없다. 문제에 제시된 순서를 구현하여 최종값을 구현하면 되나,
// 그 과정이 꽤나 복잡하다.

// 1. 가장 크기가 큰 블록 그룹을 찾는다. 다만 무지개(0)은 어느 그룹에나 낄수 있음을 주의해야한다.
// 2. 1번에서 찾은 가장 큰 블록을 제거한다. 또한 그룹수의 제곱에 해당하는 수를 점수로 얻는다.
// 3. 격자에 중력이 작용하여 -1을 제외한 나머지는 아래가 빈칸이라면 아래쪽으로 이동한다.
// 4. 격자가 반시계 방향으로 회전한다.
// 5. 다시 중력이 작용한다.

// 하나씩 풀어나가보자. 
// 1번부터 꽤나 복잡하다. 상술하였듯 무지개(0)은 어느 그룹에나 낄수 있다. 그렇기 때문에 BFS순회가 끝난 이후
// 이번 순회동안 무지개였던 좌표값들은 다시 방문을 하지 않은 것으로 바꾸어 다음 순회에도 접근이 가능하게 바꾸어야한다.
// 2번은 제거가 중요한데 사실상 쓰이지 않는 M + 1을 대입하여 후에 조건문에서 빈칸처리를 따로 하면 된다. 그 이후 최종값에 점수값을 더한다.
// 3번은 while문을 이용하여 이동하는 칸이 없을때까지 계속 아래로 이동시키면 된다.
// 4번은 빈 배열하나를 만들어 이동값을 저장한후 다시 본배열에 복사시키면 된다.
// 5번은 3번에서 쓰인 함수를 다시 쓰면 된다.

// 꽤나 복잡했으나, 그래도 집중력을 발휘하여 한번에 풀었다. 다만 복잡했던 만큼 시간은 꽤나 걸렸다.

// 자세한 설명은 주석으로 남긴다.

int board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌, 상, 우, 하.
int N, M;
bool visit[20][20];
vector<pair<int, int>> vec;
int max_b, max_r;
pair<int, int> pos;

// BFS순회를 구현하는 함수.
void BFS(int y, int x, int num)
{
    // 현재 최대 블록값과 무지개 블록값.
    int b_num = 1;
    int r_num = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 오직 현재 board와 값이 같거나 무지개(0)일때에만 이동가능하다.
            if (dy < 0 || dy >= N || dx < 0 || dx >= N || (board[dy][dx] != 0 &&
                board[dy][dx] != num) || visit[dy][dx])
                continue;

            visit[dy][dx] = true;
            que.push(make_pair(dy, dx));
            // 상술하였듯 무지개일 경우 다른 그룹에도 속할수 있기에 좌표값들을 포함시켜
            // 후에 방문을 가능하게끔 바꾼다.
            if (board[dy][dx] == 0)
            {
                vec.push_back(make_pair(dy, dx));
                ++r_num;
            }
            ++b_num;
        }
    }

    // 그룹의 최소 수는 2개 이상이다.
    if (b_num <= 1)
        return;

    // 기준 좌표의 갱신 조건문들.
    bool isfind = false;
    if (max_b < b_num)
        isfind = true;
    else if (max_b == b_num)
        if (max_r <= r_num)
            isfind = true;

    if (isfind)
    {
        max_b = b_num;
        max_r = r_num;
        pos = make_pair(y, x);
    }
}

// 모든 좌표를 순회하며 최대 그룹의 수를 구하고 무지개칸의 갱신여부를 매번 갱신시켜준다.
void BFSAll()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visit[i][j] && (board[i][j] != -1 && board[i][j] != 0 && board[i][j] != M + 1))
            {
                vec.clear();
                BFS(i, j, board[i][j]);
                for (int i = 0; i < vec.size(); ++i)
                    visit[vec[i].first][vec[i].second] = false;
            }
}

// 최대 그룹을 비우는 함수.
void EraseBFS()
{
    int num = board[pos.first][pos.second];
    queue<pair<int, int>> que;
    que.push(pos);

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 현재칸을 비운다(M + 1로 바꾼다). 다만, 값이 변하여 이전 좌표로 돌아갈일이 없기 때문에
            // 방문 여부의 bool배열은 필요없다.
            if (dy < 0 || dy >= N || dx < 0 || dx >= N || (board[dy][dx] != 0 &&
                board[dy][dx] != num))
                continue;

            board[dy][dx] = M + 1;
            que.push(make_pair(dy, dx));
        }
    }
}

// 중력을 작용시키는 함수.
void Gravity()
{
    bool isfind;
    while (true)
    {
        isfind = false;
        for (int i = N - 2; i >= 0; --i)
            for (int j = 0; j < N; ++j)
                if ((board[i][j] != -1 && board[i][j] != M + 1) && board[i + 1][j] == M + 1)
                {
                    swap(board[i][j], board[i + 1][j]);
                    isfind = true;
                }
        // 현재 이동할수 있는 좌표가 존재하는한 계속 반복하면서 중력을 작용시킨다.
        if (!isfind)
            break;
    }
}

// 90도로 반시계 회전하는 함수. 직접 그려보며 대입하면 쉽다.
void Rotate()
{
    int temp[20][20];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            temp[i][j] = board[j][N - 1 - i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = temp[i][j];
}

void MakeAnswer()
{
    int answer = 0;
    while (true)
    {
        max_b = 1;
        BFSAll();// 여기서 블록 그룹 검사. 그룹이 없다면 while문 탈출.(max_b가 2보다 작다면)
        if (max_b == 1)
            break;
        answer += max_b * max_b;
        EraseBFS();// 제거.
        Gravity();// 첫번째 중력 작용.
        Rotate();// 90도 반시계 회전.
        Gravity();// 두번째 중력 작용.
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}