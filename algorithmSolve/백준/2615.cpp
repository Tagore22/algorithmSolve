#include <iostream>

using namespace std;

// 풀이.
// 첫번째로 문제를 잘못봤고, 두번째로 그로 인해 한참 잘못 풀었던 문제이다.
// 문제가 조금 헷갈리게 출제되었는데 그래서 그런지 크게 어렵진 않으나 정답률이 20프로도 안된다.
// 이 문제의 큰 틀을 보자면 다음과 같다.

// 1. 각 칸에 0, 1, 2가 존재하는데 0은 빈곳이고 1은 1번 플레이어, 2는 2번 플레이어이다.
// 2. 가로, 세로, 대각선으로 5개를 연속으로 놓았다면 그 플레이어가 승리한다.
// 3. 다만 연속으로 6개 이상으로 두었다면 그것은 승리로 여기지 않는다.
// 4. 아무도 이기지 못했다면 0을, 누군가 이겼다면 그 플레이어의 번호와 가장 왼쪽 좌표값을 함께 출력하되,
// 세로로 5개를 놓았다면 가장 위의 좌표값을 출력한다.

// 나는 가로 세로 0 ~ 19 를 모두 순회하며 가로, 세로, 대각선으로 5개를 연속으로 놓여져 있다면
// 그 시작점과 플레이어를 출력하게끔 풀었는데 여기서 문제가 한가지 발생했다.
// 지금은 수정하였으나 방향은 총 4개였다. 오른쪽, 아래쪽, 오른쪽 아래, 왼쪽 아래.
// 여기서 왼쪽 아래가 문제였다. 세로로 놓였을때를 제외하고는 가장 왼쪽 좌표값을 출력해야 하는데
// 왼쪽 아래는 가장 왼쪽이 아닌 가장 오른쪽의 좌표값이기 때문이다.
// 이거 하나 때문에 한참을 헤맸다 T^T.

// 문제를 잘좀보자. 물론 문제가 이상할때도 있다.

// 자세한 설명은 주석으로 남긴다.

const int MAX_NUM = 20;
int board[MAX_NUM][MAX_NUM];

bool Check(int y, int x, int num)
{
    // 가로
    bool isfind = true;
    // 우선 현재 시작점에서 5개를 연속으로 놓을수 있는지 확인한다.
    for (int i = 1; i <= 4; ++i)
        if (x + i >= MAX_NUM || board[y][x + i] != num)
        {
            isfind = false;
            break;
        }
    // 연속으로 5개를 놓았을때 시작점을 기준으로 앞 뒤로 한개씩 더 찾아본다.
    // 만약 앞 혹은 뒤로도 놓여져있지 않아 온전히 5개만 연속적으로 놓여져있다면 바로 이곳이 정답이다.
    if (isfind)
        if (((x - 1 >= 0 && board[y][x - 1] != num) || x - 1 < 0) &&
            ((x + 5 < MAX_NUM && board[y][x + 5] != num) || x + 5 >= MAX_NUM))
            return isfind;

    // 세로
    isfind = true;
    for (int i = 1; i <= 4; ++i)
        if (y + i >= MAX_NUM || board[y + i][x] != num)
        {
            isfind = false;
            break;
        }
    if (isfind)
        if (((y - 1 >= 0 && board[y - 1][x] != num) || y - 1 < 0) &&
            ((y + 5 < MAX_NUM && board[y + 5][x] != num) || y + 5 >= MAX_NUM))
            return isfind;

    // 오른쪽 아래 대각선
    isfind = true;
    for (int i = 1; i <= 4; ++i)
        if (x + i >= MAX_NUM || y + i >= MAX_NUM || board[y + i][x + i] != num)
        {
            isfind = false;
            break;
        }
    if (isfind)
        if (((x - 1 >= 0 && y - 1 >= 0 && board[y - 1][x - 1] != num) || x - 1 < 0 || y - 1 < 0) &&
            ((x + 5 < MAX_NUM && y + 5 < MAX_NUM && board[y + 5][x + 5] != num) || x + 5 >= MAX_NUM || y + 5 >= MAX_NUM))
            return isfind;

    //  오른쪽 위 대각선
    isfind = true;
    // 기존에는 왼쪽 아래가 놓여져있던 부분. 왼쪽 아래로 가는 시작점은 가장 왼쪽 부분이 아닌 가장 오른쪽부분이기에
    // 정답이 될수 없다. 여기를 놓쳐 한참 헤맸다.
    for (int i = 1; i <= 4; ++i)
        if (x + i < 0 || y - i >= MAX_NUM || board[y - i][x + i] != num)
        {
            isfind = false;
            break;
        }
    if (isfind)
        if (((x - 1 < MAX_NUM && y + 1 >= 0 && board[y + 1][x - 1] != num) || x - 1 >= MAX_NUM || y + 1 < 0) &&
            ((x + 5 >= 0 && y - 5 < MAX_NUM && board[y - 5][x + 5] != num) || x + 5 < 0 || y - 5 >= MAX_NUM))
            return isfind;
    return false;
}

void MakeAnswer()
{
    for (int i = 1; i < MAX_NUM; ++i)
        for (int j = 1; j < MAX_NUM; ++j)
            if (board[i][j] != 0)
                if (Check(i, j, board[i][j]))
                {
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j << '\n';
                    return;
                }
    cout << 0 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < MAX_NUM; ++i)
        for (int j = 1; j < MAX_NUM; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}