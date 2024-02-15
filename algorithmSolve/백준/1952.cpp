#include <iostream>

using namespace std;

// 풀이.
// 원래는 규칙을 찾으려고 했으나 도무지 찾을수가 없어서 결국 직접
// 그려보기로 했다.

int rot[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool board[100][100];
int M, N;

int main()
{
    cin >> M >> N;
    int idx = 0, y = 0, x = 0, answer = 0;
    board[y][x] = true;
    for (int i = 1; i < M * N; ++i)
    {
        int dy = y + rot[idx][0];
        int dx = x + rot[idx][1];
        if (dy < 0 || dy >= M || dx < 0 || dx >= N || board[dy][dx])
        {
            ++idx;
            idx %= 4;
            dy = y + rot[idx][0];
            dx = x + rot[idx][1];
            ++answer;
        }
        board[dy][dx] = true;
        y = dy;
        x = dx;
    }
    cout << answer << '\n';
    return 0;
}