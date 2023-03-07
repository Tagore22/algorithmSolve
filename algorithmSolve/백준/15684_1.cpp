#include <iostream>
#include <cstring>

using namespace std;

// 백준 15684번의 좀더 빠른 풀이.
// 답은 어차피 0 ~ 3이 아니면 -1이기 때문에 추가할수 있는 가로줄의 값을 0 ~ 3까지 늘려나가며
// 답을 찾았다면 추가된 가로줄값을 출력하고 나머지 모든 것을 무시한다.
// 대략 5배정도 빨라졌다.

int board[31][11];
int N, M, H, answer, check;
bool isfind = false;

bool IsEnd()
{
    int cur;
    for (int j = 1; j <= N; ++j)
    {
        cur = j;
        for (int i = 1; i <= H; ++i)
            cur += board[i][cur];
        if (cur != j)
            return false;
    }
    return true;
}

void DrawLine(int y, int x, int num)
{
    board[y][x] = num;
    board[y][x + 1] = -num;
}

void BackTrack(int idx, int num)
{
    if (isfind)
        return;

    if (IsEnd())
    {
        answer = num;
        isfind = true;
        cout << answer << '\n';
        exit(0);
    }

    if (num >= check)
        return;

    int i, j;
    for (int iter = idx + 1; iter < (N - 1) * H; ++iter)
    {
        i = iter % H + 1;
        j = iter / H + 1;
        if (board[i][j] == 0 && board[i][j + 1] == 0)
        {
            DrawLine(i, j, 1);
            BackTrack(iter, num + 1);
            DrawLine(i, j, 0);
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < 4; ++i)
    {
        check = i;
        BackTrack(-1, 0);
    }

    cout << (isfind ? answer : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, 0, sizeof(board));

    cin >> N >> M >> H;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from][to] = 1;
        board[from][to + 1] = -1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}