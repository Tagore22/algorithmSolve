#include <iostream>
#include <queue>
#include <cstring>

// 주어지는 번호는 12시 방향부터 시작하여 시계 방향이다.
// 시계 방향으로 돌때에는 맨뒤를 맨앞으로 옮기고,
// 반시계 방향은 맨앞을 맨뒤로 옮긴다.

using namespace std;

// 17822번의 인접하면서 같은 수를 찾는 과정에서 DFS를 이용한 풀이.
// 기존에 풀이 방식에서 분명 겹치는 부분이 있음에도 불구하고 N과 M이 최대 50밖에 안되어
// 모두 돌아도 50 * 50 * 4 = 10000밖에 안되었기에 그냥 풀었으나
// 자꾸 마음에 걸려 다시 풀어보았다. 근데 답이 자꾸 이상해서 한참 해매었는데
// 알고보니 DFS에서 다음칸으로 넘어가서 DFS(dy, dx)를 다시 호출하는
// 재귀 형식을 잊어버리고 있었다.... ㅠㅠ...

// 위 상술하였듯 최대값이 그리 크지 않아서 인지 중복을 제거해도 성능에 큰 차이는 없었다.
// 그래도 리팩터링 했다는 점에서 의의를 두자.

struct rota
{
    int x;
    int d;
    int k;
};

deque<int> board[51];
bool check[51][51];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하
rota r[50];
int N, M, T;
bool isfind;

void MoveClock(int idx)
{
    int div = r[idx].x;
    int dir = r[idx].d;
    int num = r[idx].k;

    for (int i = 1; i <= N; ++i)
        if (i % div == 0)
        {
            if (dir == 0)
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].back();
                    board[i].pop_back();
                    board[i].push_front(cur);
                }
            else
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].front();
                    board[i].pop_front();
                    board[i].push_back(cur);
                }
        }
}

void DFS(int y, int x)
{
    for (int iter = 0; iter < 4; ++iter)
    {
        int dy = y + rot[iter][0];
        int dx = x + rot[iter][1];

        if (dy <= 0 || dy > N)
            continue;

        if (dx == M)
            dx = 0;
        else if (dx == -1)
            dx = M - 1;

        if (check[dy][dx])
            continue;

        if (board[y][x] == board[dy][dx])
        {
            isfind = true;
            check[y][x] = true;
            check[dy][dx] = true;
            DFS(dy, dx); // 이부분을 깜빡하고 있었다. 대체 왜지...
        }
    }
}

void EraseNum()
{
    memset(check, false, sizeof(check));
    isfind = false;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] != 0 && !check[i][j])
                DFS(i, j);

    if (isfind)
    {
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (check[i][j])
                    board[i][j] = 0;
    }

    else
    {
        int num = 0;
        int sum = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    ++num;
                    sum += board[i][j];
                }

        double div = static_cast<double>(sum) / num;

        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    if (board[i][j] > div)
                        --board[i][j];
                    else if (board[i][j] < div)
                        ++board[i][j];
                }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        MoveClock(i);
        EraseNum();
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            answer += board[i][j];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int cur;
            cin >> cur;
            board[i].push_back(cur);
        }

    for (int i = 0; i < T; ++i)
        cin >> r[i].x >> r[i].d >> r[i].k;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}