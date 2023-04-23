#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 풀이.
// 1926번의 DFS 풀이다.
// 단순히 DFS의 호출 횟수와 한번 호출했을시 몇번까지 재귀되어 다시 호출하는지를 출력하면 된다.
// 예전에는 DFS가 거의 무조건 BFS보다 잡아먹는 메모리가 적은줄 알았는데
// 이번에는 DFS가 훨씬더 메모리를 많이 차지했다. 아마 범위가 커지면서
// 재귀 호출이 많아질때 콜스택이 계속 쌓여서 그런가보다.
// 정리하자면 BFS와 DFS가 호출횟수가 적을때에는 DFS가 훨씬 더 가벼우나
// 호출횟수가 증가하면 증가할수록 BFS가 더 가벼워진다.

bool board[500][500];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
bool visit[500][500];
int N, M;

int DFS(int y, int x)
{
    visit[y][x] = true;

    int ans = 1;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || !board[dy][dx] || visit[dy][dx])
            continue;

        ans += DFS(dy, dx);
    }
    return ans;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    int num = 0, answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j] == 1 && !visit[i][j])
            {
                ++num;
                answer = max(answer, DFS(i, j));
            }
    cout << num << '\n';
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int cur;
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