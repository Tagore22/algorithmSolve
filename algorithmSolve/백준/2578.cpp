#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 5x5칸의 각 칸에 숫자가 하나씩 있고 랜덤하게 25개의 수를 지명할때 몇번째 지명에서 3번째 빙고를 만드는지 찾는 문제다.
// 2가지를 고민했었는데

// 1. 빙고를 확인하는 방법. 어떤 칸이 주어질때 그 칸에서만 찾느냐 혹은 그럴것 없이 매번 모든 칸을 찾아보느냐
// 2. 어떤 칸에서만 확인한다면 대각선을 어떻게 확인하는가

// 1번은 아무리봐도 전자가 나았다. 매번 모든 칸을 확인하는 것이 단순 25번 순회가 아닌 가로 세로 대각선을 모두 확인해봐야하기 때문이다.
// 다만 2번이 걸렸는데 좌상단에서 우하단의 대각선은 좌표 y, x에서 y == x 일때가 확실했으나 좌하단에서 우상단으로의 대각선은
// 어떤 칸들이 가능한지 확인할 조건문이 생각나질 않았다. 의외로 답은 간단했는데 y + x가 4일때였다. 

// 나머지는 최대 25개의 칸을 순회하며 지명된 칸을 찾고 그 칸을 방문 표시로 갱신한후 현재 빙고가 몇개인지 찾아가면서
// 3번째 빙고가 나타났을때 몇번째 지명인지 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[5][5], nums[25];
bool visit[5][5];
int bingo = 0;

// 현재 좌표 y, x가 주어졌을때 이 칸으로부터 확인할수 있는 빙고의 수를 확인하는 함수.
void CheckBingo(int y, int x)
{
    // 좌상단에서 우하단으로의 대각선 
    if (y == x)
    {
        bool isFind = true;
        for (int i = 0; i < 5; ++i)
        {
            if (!visit[i][i])
            {
                isFind = false;
                break;
            }
        }
        bingo = isFind ? bingo + 1 : bingo;
    }
    // 좌하단에서 우상단으로의 대각선
    // 오직 y + x == 4일때만 좌하단에서 우상단으로의 5칸짜리 대각선을 만들수 있다.
    if (y + x == 4)
    {
        bool isFind = true;
        for (int i = 0; i < 5; ++i)
        {
            if (!visit[4 - i][i])
            {
                isFind = false;
                break;
            }
        }
        bingo = isFind ? bingo + 1 : bingo;
    }

    // 가로 및 세로.
    bool isFindCol = true;
    bool isFindRow = true;
    for (int i = 0; i < 5; ++i)
    {
        if (!visit[y][i])
            isFindRow = false;
        if (!visit[i][x])
            isFindCol = false;
    }
    bingo = isFindCol ? bingo + 1 : bingo;
    bingo = isFindRow ? bingo + 1 : bingo;
}

// 주어진 번호의 방문 표시를 갱신하고 현재 몇개의 빙고가 존재하는지 확인한다.
void CheckPoint(int num)
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            if (board[i][j] == num)
            {
                visit[i][j] = true;
                CheckBingo(i, j);
                return;
            }
        }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    for (int iter = 0; iter < 25; ++iter)
    {
        // 현재 주어진 번호를 방문하고 존재하는 빙고의 개수를 확인한다.
        CheckPoint(nums[iter]);

        // 현재 빙고가 3개 이상이라면 몇번째 지명인지 출력하고 탈출한다.
        if (bingo >= 3)
        {
            cout << iter + 1 << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];

    for (int i = 0; i < 25; ++i)
        cin >> nums[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}