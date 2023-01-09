#include <iostream>
#include <cstring>

using namespace std;

//풀이
//전형적인 DFS문제이다. 2차원 배열을 순회하면서 음쓰가 있는 좌표에 도달할 경우 DFS함수를 순회하며 음쓰의 크기를 1씩 증가해나간다.
//다만 좌우상하로 이동할때 왔던곳을 다시 와서는 안되므로, DFS 시작부분에 현 좌표를 false로 갱신하는 것을 잊으면 안된다.
//또한, 최초 음쓰의 크기는 0이 아닌 1임에 주의할것.

bool board[100][100];
int tran[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int N, M, K;

int DFS(int y, int x)
{
    int check = 1;
    board[y][x] = false;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || !board[dy][dx])
            continue;

        check += DFS(dy, dx);
    }

    return check;
}

void MakeAnswer()
{
    int answer = 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j])
                answer = max(answer, DFS(i, j));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, false, sizeof(board));

    cin >> N >> M >> K;
    int y, x;
    for (int i = 0; i < K; ++i)
    {
        cin >> y >> x;
        board[y - 1][x - 1] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}