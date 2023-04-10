#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 복잡하다 싶으면 또 삼성이다. 이젠 귀찮다.

// 조건이 엄청 복잡하게 제시되어 있어서 언뜻 보기에 어려워보였으나,
// 막상 하나씩 조건을 대입하기만 하면 되는 문제다.

//

int board[21][21];
int people[5];
bool check[21][21];
int N, answer = 987654321;

// 주어진 값들로 각 선거구의 최소 차이값을 구하는 문제.
void CalMax(int y, int x, int d1, int d2)
{
    // 각 선거구의 인원들과 방문 여부를 초기화한다.
    // 방문 여부는 후에 마지막 5번 선거구의 인원들을 파악하는데 사용된다.
    memset(people, 0, sizeof(people));
    memset(check, false, sizeof(check));
    int dy, dx, cur_row = 1;
    int cur_y = y, cur_x = x;

    // 1번 선거구는 배열에서 좌상단부터 우하단 방향으로 파악한다.
    // 예를 들면 1번행의 N개, 2번행의 N-1개 등등...
    // 또한 cur_row는 현재 구하고자하는 행의 위치를 추적한다.
    for (int i = 0; i <= d1; ++i)
    {
        dy = cur_y + i;
        dx = cur_x - i;

        // 현재 구하고자 하는 행부터 순회를 한다.
        for (; cur_row < dy; ++cur_row)
            for (int c = 1; c <= dx; ++c)
            {
                people[0] += board[cur_row][c];
                // 1번 선거구의 인원들은 모두 방문하였다.
                check[cur_row][c] = true;
            }
    }

    // 여기서 cur_row의 값을 갱신한다.
    cur_row = 1;

    // 2번 선거구의 인원들 역시 좌상단에서 우하단으로 순회하며 구한다.
    for (int i = 1; i <= d2 + 1; ++i)
    {
        dy = cur_y + i;
        dx = cur_x + i;

        for (; cur_row < dy; ++cur_row)
            for (int c = dx; c <= N; ++c)
            {
                people[1] += board[cur_row][c];
                check[cur_row][c] = true;
            }
    }

    // 기준점이 바뀐다. (경계의 가장 왼쪽 좌표)
    // 3번 선거구부터 구하는 방향이 달라진다. 왼쪽에서 오른쪽으로 순회가 아닌
    // 위에서 아래로 순회를 하며 왼쪽에서 오른쪽으로 이동한다.
    // 추적하는 값도 행의 위치를 뜻하는 cur_row이 아닌 열의 위치를 뜻하는
    // cur_col로 바뀐다.
    cur_y = y + d1;
    cur_x = x - d1;
    int cur_col = 1;

    for (int i = 0; i <= d2; ++i)
    {
        dy = cur_y + i;
        dx = cur_x + i;

        // 기존처럼 순회를 돌때 열부터 도는게 아닌 행부터 돈다.
        // 배열값은 그대로임을 잊지 말자. 
        // 여기서 헷갈려서 5분을 날렸다.
        for (; cur_col < dx; ++cur_col)
            for (int r = dy; r <= N; ++r)
            {
                people[2] += board[r][cur_col];
                check[r][cur_col] = true;
            }
    }

    // 마찬가지로 기준점이 바뀌며 순회 방향이 위에서 아래로는 그대로지만
    // 오른쪽에서 왼쪽으로 바뀐다.
    cur_y = y + d2;
    cur_x = x + d2;
    cur_col = N;
    for (int i = 1; i <= d1 + 1; ++i)
    {
        dy = cur_y + i;
        dx = cur_x - i;

        // 마찬가지로 열을 먼저 순회하되 배열값은 그대로다.
        // ex) 첫 for문이 j이지만 좌표값은 board[i][j];
        for (; cur_col > dx; --cur_col)
            for (int r = dy; r <= N; ++r)
            {
                people[3] += board[r][cur_col];
                check[r][cur_col] = true;
            }
    }

    // 아직 방문하지 않은 (더하지 않은) 모든 값들은 5번 선거구이므로
    // 여기서 모두 더해준다.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (!check[i][j])
                people[4] += board[i][j];

    int cur_max = -1;
    int cur_min = 987654321;

    // 최종값의 갱신.
    for (int i = 0; i < 5; ++i)
    {
        cur_max = max(people[i], cur_max);
        cur_min = min(people[i], cur_min);
    }

    answer = min(answer, cur_max - cur_min);
}

void CalPosition()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int f = 1; j - f >= 1; ++f)
                for (int s = 1; i + f + s <= N && j + s <= N; ++s)
                    CalMax(i, j, f, s);
}

void MakeAnswer()
{
    CalPosition();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}