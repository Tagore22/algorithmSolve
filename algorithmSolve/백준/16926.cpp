#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 말그대로 배열의 각 원소들을 시계 반대 방향으로 바꾸는 문제다.
// 각 시작점, 움직여야 하는 위치 등등 고려해야할게 많아서 복잡했던 문제지만
// 하나하나 근시적으로 격파해나가면 어렵지 않다.

// 실수했던 점이 하나 있는데 회전수 R을 가지치기 할수 있을줄 알았다.
// 각 N, M이 주어질때 회전수는 (N - 1) * 2 + (M - 1) * 2이기 때문에
// 이 수로 R을 나눈 나머지로만 회전하면 될줄 알았다.
// 하지만 N = 5, M = 4 같은 경우를 직접 대입해보면 가장 바깥 회전은 한바퀴에
// 14지만 그 바로 안쪽 회전은 6으로 이 가설은 틀린 경우가 되었다.

// 자세한 설명은 주석으로 남긴다.

int board[300][300];
int N, M, R;

// 회전을 담당하는 함수.
void MoveFunc()
{
    // 세로, 가로로의 회전의 수.
    int row = N - 1;
    int col = M - 1;

    // 현재 위치 및 다음에 대입할 수.
    int cur_y = 0, cur_x = 0, cur_num;

    // 각 가로, 세로 회전은 안쪽으로 들어가며 2씩 줄어든다.
    while (row > 0 && col > 0)
    {
        // 회전을 구현하는 방법을 여러가지 생각해보았으나, 이것이 제일 맞다.
        // 현재 위치를 가로 혹은 세로로 1씩 움직여서 그 부분의 값과 현재 값(이전 값)을 변경하면 된다.
        cur_num = board[cur_y][cur_x];
        for (int i = 0; i < row; ++i)
        {
            ++cur_y;
            swap(cur_num, board[cur_y][cur_x]);
        }
        for (int i = 0; i < col; ++i)
        {
            ++cur_x;
            swap(cur_num, board[cur_y][cur_x]);
        }
        for (int i = 0; i < row; ++i)
        {
            --cur_y;
            swap(cur_num, board[cur_y][cur_x]);
        }
        for (int i = 0; i < col; ++i)
        {
            --cur_x;
            swap(cur_num, board[cur_y][cur_x]);
        }

        // 1번의 회전(한바퀴)가 끝나고 나면 다음 회전은 각각 가로 - 2, 세로 - 2로 줄어든다.
        // 또한, 현 위치는 늘 가장 좌상단에서 멈추며 다음 시작이 가능하다면 현재 위치에서
        // 가로, 세로로 1씩 우하단으로 이동한곳에서 시작된다.
        row -= 2;
        col -= 2;
        ++cur_y;
        ++cur_x;
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        MoveFunc();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
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