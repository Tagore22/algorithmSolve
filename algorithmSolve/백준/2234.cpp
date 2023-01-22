#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//풀이
//1, 2번은 바로 떠올랐으나, 3번이 애매하게 생각이 나지 않아서 해맸던 문제. 1번은 DFS를 이용해서 방문하지 않은 좌표를 찾을때 마다
//방의 개수를 1개씩 늘려주면 되고, 2번은 DFS를 돌면서 방의 크기를 1씩 늘려주되, DFS의 최종값을 기존 최대값과 비교하면 된다.
//3번은 이번 좌표 [y][x]에서 얻은 방의 크기와 [y-1][x], [y][x-1]에서 얻은 방의 크기를 더하면 된다.
//다만, y,x가 0보다 작거나 각각 M, N보다 클경우, [y][x]와 [y-1][x] 혹은 [y][x-1]이 같은 방일 경우는 무시한다.

vector<int> rooms_size;
int board[50][50], room_num[50][50];
int tran[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool check[50][50];
int N, M;
int max_size = 0, plus_room = 0, cur_size = 0;

void DFS(int y, int x)
{
    ++cur_size;
    check[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        if (!(board[y][x] & (1 << i)))
        {
            int dy = y + tran[i][0];
            int dx = x + tran[i][1];

            if (dy < 0 || dy >= M || dx < 0 || dx >= N || check[dy][dx])
                continue;

            DFS(dy, dx);
        }
    }
    room_num[y][x] = rooms_size.size();
}

void MakeAnswer()
{
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (!check[i][j])
            {
                cur_size = 0;
                DFS(i, j);
                max_size = max(max_size, cur_size);
                rooms_size.push_back(cur_size);
            }
            for (int dir = 0; dir < 2; ++dir)
            {
                int di = i + tran[dir][0];
                int dj = j + tran[dir][1];

                if (di < 0 || di >= M || dj < 0 || dj >= N || room_num[i][j] == room_num[di][dj])
                    continue;

                plus_room = max(plus_room, rooms_size[room_num[i][j]] + rooms_size[room_num[di][dj]]);
            }
        }
    cout << rooms_size.size() << '\n';
    cout << max_size << '\n';
    cout << plus_room << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}