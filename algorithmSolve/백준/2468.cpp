#include <iostream>
#include <cstring>

using namespace std;

// 풀이
// 전형적인 DFS문제이다. 다만 DFS순회의 조건중 하나인 배열값조차 순회하며 DFS를 순회해야한다.
// 100 * 100번으로 최대 10000번씩 순회하는 것이 크지는 않으나, 나름대로의 최적화를 위해
// 최대 높이값을 구하여 그 이전까지만 순회를 진행하였다.

int board[100][100];
bool check[100][100];
int rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, H, max_H = 0;

// 전형적인 DFS 구현함수.
void DFS(int y, int x)
{
    check[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || check[dy][dx] || board[dy][dx] <= H)
            continue;

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    int answer = 0, cur;
    
    // 하술하였듯 도시의 최대 높이부터의 순회는 의미가 없다. 최대 높이부터는 무조건 모든 도시가 물에 잠겨 안전지대가 없기 때문.
    for (int i = 0; i < max_H; ++i)
    {
        // 이번 순회의 안전지대의 수와 높이값, 방문 여부를 기록하는 배열의 초기화.
        cur = 0;
        H = i;
        memset(check, false, sizeof(check));

        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                if (board[j][k] > H && !check[j][k])
                {
                    ++cur;
                    DFS(j, k);
                }

        answer = max(answer, cur);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            // 이후 DFS 순회시 주어지는 높이값을 최소화하기 위해 배열의 최대값을 구한다. 도시가 모두 물에 잠긴다면 안전지대는
            // 무조건 0이기 때문에 최대값부터의 순회는 의미가 없다.
            max_H = max(max_H, board[i][j]);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}