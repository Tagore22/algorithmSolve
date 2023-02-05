#include <iostream>
#include <cstring>

using namespace std;

//풀이
//이 문제에는 2가지 2차원 배열이 필요한데 
//1. 현재 좌표가 치즈인가(1인가), 치즈가 아닌가(0인가)를 뜻하는 int형 배열 board.
//2. 현재 좌표가 외부 공기인가 혹은 내부 공기인가를 뜻하는 bool형 isinside.(후술하겠으나 이번에 녹는 치즈값들을 구분하는데에도 사용됨.)
//이 2가지가 필요하다. 

//첫번째로 치즈를 녹이기 위해서는 공기과 2군데 이상 맞닿아 있어야하는데 다만, 내부 공기는 맞닿아도 아무런 상관이 없기에 외부 공기와
//내부 공기를 분리해야만 한다. 문제에서 맨 가장자리는 절대로 치즈가 아니라고 명시해놨기에 {0,0}은 무조건 외부 공기이다. 이것을 이용해서
//0,0에서 시작하는 DFS를 시작하여 외부 공기들을 알아내고 isinside에 false로 체크해놓는다. 

//DFS순회가 끝나면 모든 좌표들을 순회하여 해당 좌표의 board값이 1일때 상하좌우 4군데를 비교하여 board값이 0이면서(공기이면서), 
//isinside값이 false인(내부 공기가 아닐때) 값이 2이상일때 그 좌표값의 치즈는 녹게 되므로 isinside값을 false로 바꾸어 기록해놓는다.
//(애시당초 board가 1인값들의 isinside값은 쓰일일이 없기에 이렇게 사용하는것이 메모리 절약에 도움이 된다.)

//이렇게 board값의 순회가 끝나면 이번에 녹을 치즈좌표들은 board가 1이면서 isinside가 false인 값들이다.
//이 좌표들의 board값을 모두 0으로 바꾸어 준다.

//마지막으로 이번 순회에 녹은 치즈값들이 있나 확인을 하는데 만약 녹은 값들이 없다면 모든 치즈가 녹은 것이므로 while문을 벗어나면 되고,
//그렇지 않다면 시간값을 1 추가하여 다시 while문을 순회한다.

int board[100][100];
bool isinside[100][100];
int trans[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;

void CheckInsideDFS(int y, int x)
{
    isinside[y][x] = false;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + trans[i][0];
        int dx = x + trans[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx] == 1 || !isinside[dy][dx])
            continue;

        CheckInsideDFS(dy, dx);
    }
}

void MakeAnswer()
{
    int answer = 0;
    bool ismelt;
    while (true)
    {
        ismelt = false;
        memset(isinside, true, sizeof(isinside));
        CheckInsideDFS(0, 0);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 1)
                {
                    int check = 0;
                    for (int iter = 0; iter < 4; ++iter)
                    {
                        int y = i + trans[iter][0];
                        int x = j + trans[iter][1];

                        if (board[y][x] == 0 && !isinside[y][x])
                            ++check;
                    }

                    if (check >= 2)
                    {
                        ismelt = true;
                        isinside[i][j] = false;
                    }
                }

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 1 && !isinside[i][j])
                    board[i][j] = 0;
        if (ismelt)
            ++answer;
        else
            break;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
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