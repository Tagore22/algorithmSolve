#include <iostream>
#include <cstring>

using namespace std;

bool check[1000][1000];
int cashe[1000][1000][3];
int board[1000][1000];
int N, M;
int dy[3] = { 0,1,0 };
int dx[3] = { -1,0,1 };
const int MINNUM = -987654321;

//처음에는 ㅇㅇㅇㅇ 부분에서 방문여부를 수정해주면 굳이 캐싱을 [][][]까지 안해도 될거라고 생각했으나,
//다시 생각해보면 DP를 돌때 어떠한 좌표 y,x에서의 캐시값은 모두 같은 값을 지닌다.
//그것이 왼쪽, 오른쪽, 위쪽에서 접근할지라도 말이다. 허나 이 값은 모두 달라야하는데 
//왜냐하면 예를 들어 오른쪽에서 접근했을때에는 오른쪽이 아닌 아래쪽, 왼쪽으로 이동한 값이 있어야하는데
//왼쪽에서 접근해도 왼쪽, 아래쪽중 큰값을 지니기에 논리적으로 말이 안되기 때문이다.

int DP(int y, int x, int dir)
{
    if (y == N - 1 && x == M - 1)
        return board[y][x];
    int& ans = cashe[y][x][dir];
    if (ans != MINNUM)
        return ans;
    for (int i = 0; i < 3; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy >= N || cx >= M || cy < 0 || cx < 0 || check[cy][cx])
            continue;

        check[cy][cx] = true; //ㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇ
        ans = max(ans, DP(cy, cx, i) + board[y][x]);
        check[cy][cx] = false;
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cashe[i][j][0] = MINNUM;
            cashe[i][j][1] = MINNUM;
            cashe[i][j][2] = MINNUM;
        }
    check[0][0] = true;
    cout << DP(0, 0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, 0, sizeof(check));

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