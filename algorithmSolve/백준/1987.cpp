#include <iostream>
#include <cstring>

using namespace std;

//풀이
//백트래킹 문제이다. 다만, 한번에 나아감에 이미 방문했던 곳을 기존에는 bool형으로 체크했으나 이번 문제는 한번 방문한 알파벳은
//또다시 방문할수 없다는 조건이 붙어서 굳이 bool형을 쓸 필요가 없었기에 방문한 알파벳을 기록하는 int형 배열로 대신하였다.
//한번에 나아감에 방문했던 알파벳을 기록하고 나아가려는 칸이 이미 방문한 알파벳이라면 나아가지 않는다.
//각 이동의 최대값을 반환하여 초기칸의 값인 1을 더해 출력한다.

char board[20][20];
int alpha[26];
int tran[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int R, C;

int DFS(int y, int x)
{
    int move = 0;
    alpha[board[y][x] - 'A'] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || alpha[board[dy][dx] - 'A'] != 0)
            continue;

        move = max(move, DFS(dy, dx) + 1);
    }
    alpha[board[y][x] - 'A'] = 0;
    return move;
}

void MakeAnswer()
{
    cout << DFS(0, 0) + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(alpha, 0, sizeof(alpha));

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}