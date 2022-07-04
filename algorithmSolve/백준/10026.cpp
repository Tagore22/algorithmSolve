#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> check;
vector<string> board;
int N;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

void DFS(int y, int x, char color)
{
    check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];
        if (cy < 0 || cy >= N || cx < 0 || cx >= N || check[cy][cx] || board[cy][cx] != color)
            continue;
        DFS(cy, cx, color);
    }
}

int GoDFS()
{
    int rgb = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j])
            {
                DFS(i, j, board[i][j]);
                ++rgb;
            }
    return rgb;
}

void TransGraph()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == 'G')
                board[i][j] = 'R';
}

void MakeAnswer()
{
    check.assign(N, vector<bool>(N, false));
    int rgb = GoDFS();
    cout << rgb << ' ';
    TransGraph();
    check.assign(N, vector<bool>(N, false));
    rgb = GoDFS();
    cout << rgb << '\n';
}

void Input()
{
    cin >> N;
    board.assign(N, string());
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}