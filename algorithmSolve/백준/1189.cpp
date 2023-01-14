#include <iostream>

using namespace std;

//풀이
//상하좌우 4방향중 갈수 있는 모든 곳으로 가되, 우상단에 도착했을때 거리가 K일때만 최종답 answer의 값을 1 더한다.
//또한, 한번의 이동중 갔던 곳은 또다시 갈수 없기에 bool형식의 2차원 배열로 이미 방문한 곳을 갱신해주어야 한다.

string board[5];
bool check[5][5];
int tran[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int R, C, K, answer = 0;

void BackTrack(int y, int x, int num)
{
    if (y == 0 && x == C - 1 && num == K)
        ++answer;

    check[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + tran[i][0];
        int dx = x + tran[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || check[dy][dx] || board[dy][dx] == 'T')
            continue;
        BackTrack(dy, dx, num + 1);
    }

    check[y][x] = false;
}

void MakeAnswer()
{
    BackTrack(R - 1, 0, 1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}