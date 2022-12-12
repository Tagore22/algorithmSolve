#include <iostream>

using namespace std;

//주먹구구식으로 푼 문제. 최대값이 너무 커서 될까 망설였으나 줄어드는 부분도 많아서 한번 해보았더니 맞았다.
//제대로 된 풀이는 1261_1을 찾을것.

//풀이
//입력받는 2차원 배열을 제외한 어떤 정점 y, x까지 도달하기 위해 부수어야 하는 최소한의 벽값을 저장하는 별도의 배열 walls를 만들어서
//이동가능한 모든 정점들을 순회하며 walls를 갱신하고 마지막에 walls[N-1][M-1]을 출력한다.
//위 상술하였듯이 순회하는 모든 경우의 수가 4의 10000제곱이기에 너무 컸으나 walls를 갱신하는 조건문에서 꽤나 많은 경우의 수가 줄어들어
//정답이 된것같다. 시간복잡도조차 구하기 난해한 풀이

int board[100][100];
int walls[100][100];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int M, N;
const int MAX_NUM = 987654321;

void CalAnswer(int y, int x)
{
    if (y == N - 1 && x == M - 1)
        return;

    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || cy >= N || cx < 0 || cx >= M)
            continue;

        if (walls[y][x] + board[cy][cx] < walls[cy][cx])
        {
            walls[cy][cx] = walls[y][x] + board[cy][cx];
            CalAnswer(cy, cx);
        }
    }
}

void MakeAnswer()
{
    CalAnswer(0, 0);
    cout << walls[N - 1][M - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            walls[i][j] = MAX_NUM;
    walls[0][0] = 0;

    cin >> M >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}