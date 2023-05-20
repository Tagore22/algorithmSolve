#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 2665번의 DFS풀이이다. dp를 [50][50]으로만 잡고 싶었으나, 어떤 좌표값 y, x에 도달할때 더 적은수를
// 바꾸어도 나중에 도착한단 이유로 기존값을 그대로 덮어쓰게 된다. 그렇기 때문에 dp를 [50][50][2500]으로
// 바꾼 수까지 dp에 포함시켜야 했다. 그렇다보니 경우의 수가 많아져서 메모리도 속도도 많이 잡아먹게 되었다.

// 자세한 설명은 주석으로 남긴다.

bool board[50][50], visit[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int dp[50][50][2500];
int N;

// 상술하였듯 현재까지 몇번 변경하였는가 또한 포함되어야한다.
int DFS(int y, int x, int num)
{
    if (y == N - 1 && x == N - 1)
        return num;

    int& ans = dp[y][x][num];
    if (ans != -1)
        return ans;

    ans = 987654321;
    visit[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || visit[dy][dx])
            continue;

        if (board[dy][dx])
            ans = min(ans, DFS(dy, dx, num));
        else
            ans = min(ans, DFS(dy, dx, num + 1));
    }
    visit[y][x] = false;
    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    memset(visit, false, sizeof(visit));
    int answer = DFS(0, 0, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}