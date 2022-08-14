#include <iostream>
#include <cstring>

using namespace std;

const int MAXNUM = 500;
int cashe[MAXNUM][MAXNUM];
int board[MAXNUM][MAXNUM];
int N;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int answer = 0;

//기존 풀이에 적은 것은 그닥 필요없었다. 그냥 정점[a][b]부터 시작한 이동수를 캐싱하면 되었음.

int DFS(int y, int x)
{
    int& ans = cashe[y][x];
    if (ans != -1)
        return ans;
    ans = 1;
    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy >= N || cx >= N || cy < 0 || cx < 0 || board[cy][cx] <= board[y][x])
            continue;

        ans = max(ans, DFS(cy, cx) + 1);
    }
    return ans;
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer = max(answer, DFS(i, j));
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
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