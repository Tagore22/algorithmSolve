#include <iostream>
#include <cstring>

using namespace std;

// 풀이. 
// 언젠가 풀어본 치즈 문제와 비슷하다. 어쩌면 아예 같을지도;
// 푸는 원리는 다음과 같은 3가지를 반복하면 된다.

// 1. 공기와 치즈를 분리한다. (DFS)
// 2. 배열을 순회하며 어떤 좌표 y, x의 치즈가 공기와 맞닿아 있는지 확인하고 ismelt 값을 갱신한다.
// 3. 다시 배열을 순회하며 공기와 맞닿은 치즈의 값을 갱신한다(1에서 0으로)

// 반복을 최대한 줄이기 위해 치즈값과 녹기 이전 치즈값을 따로 저장하여 더 성능을 올릴수 있다.

int board[100][100];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
bool ismelt[100][100];
int R, C, cheese = 0; // 현재 치즈의 개수.

// 배열의 값을 공기와 치즈로 분리하는 함수. 1사이클 마다 다른 함수들과 마찬가지로 반복해주어야 한다.
void FindAirDFS(int y, int x)
{
    ismelt[y][x] = true;

    int dy, dx;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || ismelt[dy][dx] || board[dy][dx] != 0)
            continue;

        FindAirDFS(dy, dx);
    }
}

// y, x값의 치즈가 공기와 맞닿아 있는지 확인하는 함수. 맞닿아 있다면
// ismelt 값을 true로 갱신하여 이번 사이클에 녹인다.
void FindMelt(int y, int x)
{
    int dy, dx;
    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C)
            continue;

        if (ismelt[dy][dx] && board[dy][dx] == 0)
        {
            ismelt[y][x] = true;
            break;
        }
    }
}

void MakeAnswer()
{
    // 사이클값 answer와, 이전 치즈값 prev.
    int answer = 0, prev = 0;
    while (cheese > 0)
    {
        memset(ismelt, false, sizeof(ismelt));
        FindAirDFS(0, 0);

        ++answer;
        prev = cheese;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (board[i][j] == 1)
                    FindMelt(i, j);

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (board[i][j] == 1 && ismelt[i][j])
                {
                    --cheese;
                    board[i][j] = 0;
                }
    }
    cout << answer << '\n';
    cout << prev << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                ++cheese;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}