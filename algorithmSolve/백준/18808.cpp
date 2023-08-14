#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 어렵진 않으나 조건이 덕지덕지 붙은 자주 나오는 형식의 문제이다.
// 이런 문제를 풀때 주의할 점은 1가지뿐인데 주석을 이용한 메모를 이용하는 것이다.
// 상술하였듯 조건이 많이 때문에 자칫 한번 꼬여버리면 답이 없어진다.
// 이번처럼 집중해서 한번에 풀어버리자.

// 문제의 큰 틀은 다음과 같다.
// 1. 스티커를 입력 받는다.
// 2. 노트북을 순회하며 현재 스티커를 붙일수 있나 확인한다.
// 2-1. 붙일수 있다면 다음 스티커로 넘어간다.
// 2-2. 붙일수 없다면 스티커를 시계 방향으로 90도 회전하여 최대 3번 확인한다. 그 이후에도 붙일수 없다면 무시하고 넘어간다.
// 1 ~ 2를 최대 K번 확인후 현재 노트북에 붙어 있는 스티커들의 칸을 출력하면 된다.

// 스티커를 회전시키는 부분에서 의외로 애를 먹었다. 처음에는 모든 스티커를 회전시키는 점화식이 존재하지 않는줄알고 
// 온갖 삽질을 했는데 막상 손으로 풀어보니 답이 존재했다. 작디작은 머리로만 푸는 습관을 없애자.

// 자세한 설명은 주석으로 남긴다.

// 노트북과 현재 스티커를 나타내는 2차원 bool 배열들.
bool board[40][40], sticker[10][10];
int N, M, K, row, col; // 세로, 가로순서

// 현재 스티커를 회전시키는 함수. plus는 현재 세로의 크기 -1로 시작하며 가로로 1칸 늘수록 2씩 감소한다.
// 가로 세로를 뒤집은 후 x에 plus를 더하면 된다. 또한, 가로 세로 크기를 변경하는 것도 잊으면 안됀다.
void RotateSticker()
{
    bool temp[10][10];
    memset(temp, false, sizeof(temp));

    int plus = row - 1;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            if (sticker[i][j])
                temp[j][i + plus] = true;
        plus -= 2;
    }

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            sticker[i][j] = temp[i][j];
    swap(row, col);
}

// 스티커를 노트북에 붙이는 함수. 현재 스티커가 붙어 있는 경우(true일때) 노트북도 true가 된다.
void AddSticker(int y, int x)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (sticker[i][j])
                board[i + y][j + x] = true;
}

// 현재 칸에서 스티커를 붙일수 있는지 확인하는 함수. 시작점 y, x에서 스티커의 가로, 세로만큼 순회하며
// 스티커가 true일때 노트북도 true라면 절대로 붙일수 없다.
bool CheckSticker(int y, int x)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (i + y >= N || j + x >= M || (board[i + y][j + x] && sticker[i][j]))
                return false;
    return true;
}

// 모든칸을 순회하며 각 칸에서 스티커를 붙일수 있는지 확인하는 함수.
// 붙일수 있다면 붙인후 true를 반환하고 붙일수 없다면
// false를 반환한다.
bool CheckAll()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (CheckSticker(i, j))
            {
                AddSticker(i, j);
                return true;
            }
    return false;
}

// 위 상술한 큰 틀을 구현하는 함수.
void MakeAnswer()
{
    memset(board, false, sizeof(board));
    for (int iter = 0; iter < K; ++iter)
    {
        cin >> row >> col;
        memset(sticker, false, sizeof(sticker));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                cin >> sticker[i][j];

        for (int i = 0; i < 4; ++i)
        {
            // 대입해본다. 
            if (CheckAll())
                break;
            // 여기서 회전한다.
            RotateSticker();
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j])
                ++answer;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}