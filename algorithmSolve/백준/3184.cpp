#include <iostream>

using namespace std;

// 풀이.
// 문제에서 주어진 조건은 다음과 같다.

// 1. 마당에서 탈출할수 있는 곳은 무시한다. (배열의 가장 외곽과 연결되어 있는 곳들은 무시한다.)
// 2. 어떠한 영역에서 양이 늑대보다 많다면 늑대들이 쫓겨나고, 그렇지 않다면 양이 잡아먹힌다.

// 이때 마당에 결과적으로 남는 수들을 출력하는 문제이다.
// 주의할것은 1번 조건인데, 이 말은 즉, 가장 외곽({0, 0}, {0, 1}등)에서 도달할수 있는 모든 곳은
// 결과에 포함이 되지 않는다는 뜻이다. 그렇기에 나는 애시당초 시작하기전에 해당 지역들을 '#'처리하여
// 후에 답을 계산할때 포함시키지 않았다.

// 자세한 설명은 주석으로 남긴다.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int R, C, total_w = 0, total_s = 0, cur_w, cur_s;

// 좌표들을 순회하며 울타리화('#')시키는 함수.
void DFSZero(int y, int x)
{
    board[y][x] = '#';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#')
            continue;

        DFSZero(dy, dx);
    }
}

// 상술한 1번 조건에 의해 외곽과 연결된 (탈출가능한) 곳들을 울타리화('#') 시켜주는 함수.
void CheckZero()
{
    for (int iter = 0; iter < C; ++iter)
    {
        if (board[0][iter] == '.')
            DFSZero(0, iter);
        if (board[R - 1][iter] == '.')
            DFSZero(R - 1, iter);
    }

    for (int iter = 1; iter < R - 1; ++iter)
    {
        if (board[iter][0] == '.')
            DFSZero(iter, 0);
        if (board[iter][C - 1] == '.')
            DFSZero(iter, C - 1);
    }
}

// 좌표들을 순회하며 영역안에 늑대값과 양의 값들 구하는 함수. 이미 방문한 좌표는 울타리화하여
// 중복을 방지한다.
void CalDFS(int y, int x)
{
    if (board[y][x] == 'o')
        ++cur_s;
    else if (board[y][x] == 'v')
        ++cur_w;
    board[y][x] = '#';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#')
            continue;

        CalDFS(dy, dx);
    }
}

void MakeAnswer()
{
    CheckZero();

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != '#')
            {
                cur_w = cur_s = 0;
                CalDFS(i, j);
                if (cur_w < cur_s)
                    total_s += cur_s;
                else
                    total_w += cur_w;
            }

    cout << total_s << ' ' << total_w << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
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