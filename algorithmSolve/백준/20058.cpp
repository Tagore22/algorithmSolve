#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 삼성 문제답게 특별히 어려운건 없으나 복잡하게 꼬아놓은 문제다.
// 침착하게 잘 푼것 같다. 문제의 큰틀은 다음과 같다.

// 1. 배열을 2의 Li제곱 * 2의 Li제곱 크기로 나눈다.
// 2. 모든 부분 배열을 시계 방향으로 90도 회전시킨다.
// 3. 인접한 얼음이 존재하는 칸이 2개 이하라면 얼음의 양이 1씩 줄어든다.
// 4. 이것을 Q번 순회했을때 남아 있는 얼음의 총합과 가장 큰 덩어리의 개수를 출력하라.

// 자세한 설명은 주석으로 남긴다.

int board[64][64], temp[64][64];
int seq[1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int N, Q, len, div_num, ice_sum = 0, max_piece = 0;
bool ismelt[64][64];

// 부분 배열을 회전시키는 함수. 각 y와 x별로 시작값과 끝값이 필요하다.
void RotateBoard(int from_y, int to_y, int from_x, int to_x)
{
    for (int i = 0; i < div_num; ++i)
        for (int j = 0; j < div_num; ++j)
            temp[from_y + i][from_x + j] = board[to_y - j][from_x + i];
}

// 회전된 값을 본래 배열로 옮기는 함수. 처음엔 swap()을 이용해서 할까도
// 생각했으나 그러면 하나의 좌표값을 여러번 건드리는 경우가 있어서 더 복잡했다.
// 차라리 용량을 조금 더 차지하더라도 이게 나은것 같았다.
// 또한 배열 자체가 매우 큰것이 아니라서 속도도 그리 차이나지 않을 것이다.
void ClearBoard()
{
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            board[i][j] = temp[i][j];
}

// 어떠한 좌표값이 녹는지를 검사하는 함수. 이론상 최대 연산량은
// 2의 6제곱(64) * 2의 6제곱의 4제곱으로 1600만의 제곱꼴이다.
// 하지만 걸러지는 조건문들이 있기 때문에 시간내에 계산이 가능했다.
void CheckMelt()
{
    memset(ismelt, false, sizeof(ismelt));
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
        {
            if (board[i][j] == 0)
                continue;

            int num = 0;
            for (int iter = 0; iter < 4; ++iter)
            {
                int dy = i + rot[iter][0];
                int dx = j + rot[iter][1];

                if (dy < 0 || dy >= len || dx < 0 || dx >= len)
                    continue;

                if (board[dy][dx] > 0)
                    ++num;
            }
            if (num < 3)
                ismelt[i][j] = true;
        }

    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            if (ismelt[i][j])
                --board[i][j];
}

// 각 덩어리의 크기와 남아있는 얼음의 총량을 구하는 BFS함수.
void FindBFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    ismelt[y][x] = true;
    ice_sum += board[y][x];
    int cur_piece = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= len || dx < 0 || dx >= len || ismelt[dy][dx] || board[dy][dx] == 0)
                continue;

            que.push(make_pair(dy, dx));
            ismelt[dy][dx] = true;
            ice_sum += board[dy][dx];
            ++cur_piece;
        }
    }
    max_piece = max(max_piece, cur_piece);
}

// 배열을 순회하며 BFS를 호출하는 함수.
void FindAnswer()
{
    memset(ismelt, false, sizeof(ismelt));
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            if (board[i][j] != 0 && !ismelt[i][j])
                FindBFS(i, j);
}

void MakeAnswer()
{
    // 1. 배열을 2의 Li제곱 * 2의 Li제곱 크기로 나눈다.
    // 2. 모든 부분 배열을 시계 방향으로 90도 회전시킨다.
    // 3. 인접한 얼음이 존재하는 칸이 2개 이하라면 얼음의 양이 1씩 줄어든다.
    // 4. 이것을 Q번 순회했을때 남아 있는 얼음의 총합과 가장 큰 덩어리의 개수를 출력하라.
    for (int iter = 0; iter < Q; ++iter)
    {
        // 1 ~ 2번 단계.
        div_num = pow(2, seq[iter]);
        for (int i = 0; i < len; i += div_num)
            for (int j = 0; j < len; j += div_num)
                RotateBoard(i, i + div_num - 1, j, j + div_num - 1);

        ClearBoard();
        // 3번 단계.
        CheckMelt();
    }
    // 4번 단계.
    FindAnswer();
    cout << ice_sum << '\n' << max_piece << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    len = pow(2, N);
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            cin >> board[i][j];

    for (int i = 0; i < Q; ++i)
        cin >> seq[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}