#include <iostream>

using namespace std;

// 풀이.
// DP와 DFS를 사용하는 문제였다. 맨처음 어떠한 위치에 도달했을때 그 dp값을 0으로 초기화하고
// 배열값을 벗어나는 위치에서는 1을 반환한다. 결과적으로 순환이 일어나는 곳의 dp값은 0이,
// 배열값을 벗어나는 곳의 dp값은 1이 된다. 그리 어렵진 않았는데 정답율이 33퍼밖에 안된다.

// 자세한 설명은 주석으로 남긴다.

char board[500][500];
int dp[500][500];
int N, M, answer = 0;

// 좌표 y, x에서 시작해서 도달할수 있는 모든 좌표를 순회하는 DFS 함수.
int DFS(int y, int x)
{
    // 배열값을 벗어났다면 1을 반환하여 현재까지 도달한 모든 좌표에 1을 넘긴다.
    if (y >= N || y < 0 || x >= M || x < 0)
        return 1;

    // 이미 방문했던 곳이라면 기존의 dp값을 넘긴다.
    // 만약 0이라면 도달하지 못한곳이고 1이라면 도달하는 곳이다.
    int& ans = dp[y][x];
    if (ans != -1)
        return ans;

    // 반드시 0으로 초기화해야하는데 만약 이번 순회에서 방문한곳에 또다시 방문한다면
    // 그곳은 배열값을 벗어날수 없다. 이때 0을 반환하여 순회가 일어남을 알려야하기 때문이다.
    ans = 0;
    if (board[y][x] == 'U')
        ans = DFS(y - 1, x);
    else if (board[y][x] == 'R')
        ans = DFS(y, x + 1);
    else if (board[y][x] == 'D')
        ans = DFS(y + 1, x);
    else
        ans = DFS(y, x - 1);
    // 모든 순회가 끝난후 2중 for문으로 모든 dp값들을 더해도 상관없다.
    // 다만 이 방법이 그 2중 for문을 되풀이 하지 않아도 되는 방법이다.
    // 모든 좌표에 반드시 한번씩은 방문하기 때문이다.
    answer += ans;
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            dp[i][j] = -1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (dp[i][j] == -1)
                DFS(i, j);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}