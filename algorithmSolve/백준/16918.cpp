#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 시뮬레이션 문제이다. 주어진대로 구현을 하면 된다.
// 다만 더 빠른 풀이가 있는데 수학적 접근을 이용하는 것이다.


// 1. N이 1일때에는 그대로 출력한다.
// 2. N이 짝수일때는 모든 칸을 'O'으로 채워서 출력한다.
// 3. N이 홀수이되, 4로 나누었을때 나머지가 3일 경우와 1일 경우로 나뉜다.

// 이렇게 하면 더 빨리 풀수 있는듯하다.

// 자세한 설명은 주석으로 남긴다.

char board[200][200];
queue<pair<int, int>> que;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int R, C, N;

// 짝수번의 경우 새로운 폭탄을 채우면서 기존 폭탄의 위치를 파악한다.
void FillBomb()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] == '.')
                board[i][j] = 'O';
            else
                que.push(make_pair(i, j));
        }
}

// 홀수번의 경우 기존 폭탄을 터뜨린다.
void Explo()
{
    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= R || dx < 0 || dx >= C)
                continue;

            board[dy][dx] = '.';
        }
        board[y][x] = '.';
    }
}

void MakeAnswer()
{
    int time = 1;
    while (time < N)
    {
        ++time;
        if (time % 2 == 1)
            Explo();
        else
            FillBomb();
    }
    // 여기서 배열 출력.
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            cout << board[i][j];
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> N;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}