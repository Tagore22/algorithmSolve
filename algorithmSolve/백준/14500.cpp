#include <iostream>
#include <cstring>

//주어진 2차원 배열에서 4번의 이동끝에 얻을수 있는 원소값의 합들의 최대값을 구하는 문제이다. 전형적인 DFS문제지만 한가지 함정은
//ㅗ계열의 이동은 DFS로는 갈수 없기에 따로 구해줘야했다.

using namespace std;

const int MAX_NUM = 500;
int board[MAX_NUM][MAX_NUM];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
bool check[MAX_NUM][MAX_NUM];
int N, M, answer = 0;

void Cal(int y, int x, int iter, int sum)
{
    if (iter == 3)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || cy >= N || cx < 0 || cx >= M || !check[cy][cx])
            continue;
        check[cy][cx] = false;
        Cal(cy, cx, iter + 1, sum + board[cy][cx]);
        check[cy][cx] = true;
    }
}

void CalHalfPlus(int y, int x)
{
    if (y + 1 < N && x - 1 >= 0 && x + 1 < M) // ㅗ
        answer = max(answer, board[y][x] + board[y + 1][x] + board[y + 1][x - 1] + board[y + 1][x + 1]);
    if (y + 2 < N && x + 1 < M) // ㅏ
        answer = max(answer, board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x + 1]);
    if (y + 2 < N && x - 1 >= 0) // ㅓ
        answer = max(answer, board[y][x] + board[y + 1][x] + board[y + 2][x] + board[y + 1][x - 1]);
    if (y + 1 < N && x + 2 < M) // ㅜ
        answer = max(answer, board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x + 1]);
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            check[i][j] = false;
            Cal(i, j, 0, board[i][j]);
            check[i][j] = true;
            CalHalfPlus(i, j);
        }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, true, sizeof(check));

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