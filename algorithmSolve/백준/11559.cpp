#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 그래프 이론을 이용한 문제이다. 이 문제의 틀을 크게 요약해보자면

// 1. 현재 상태에서 일어날수 있는 모든 연쇄를 일으킨다. 다만 한턴에 여러번의 연쇄가 일어나도 1번으로 친다.
// 2. 연쇄로 인해 텅 빈곳이 존재할수 있는데 그곳을 중력에 의해 메꾸어 주는 것을 더이상 메꿀것이 없을때
//    까지 반복한다.(텅빈 곳위에 뿌요가 존재한다면 그것과 교체)

// 이것을 더이상 연쇄가 존재하지 않을때까지 반복해주면 된다.

// 자세한 설명은 주석으로 남긴다.

char board[12][6];
bool visit[12][6];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int path;

// 연쇄가 존재하는지 확인하는 DFS함수. path의 수를 늘려가며 확인한다.
void DFS(int y, int x)
{
    visit[y][x] = true;

    ++path;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= 12 || dx < 0 || dx >= 6 || board[dy][dx] != board[y][x] || visit[dy][dx])
            continue;

        DFS(dy, dx);
    }
}

// 연쇄로 인해 뿌요를 텅비게 하는 함수. 뿌요값이 변하기 때문에 char 변수 c를 추가하여 
// 다음 목표를 찾는데 사용하여야한다.
void Erase(int y, int x, char c)
{
    board[y][x] = '.';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= 12 || dx < 0 || dx >= 6 || board[dy][dx] != c)
            continue;

        Erase(dy, dx, c);
    }
}

// 이번 턴에 연쇄가 존재하는지 확인하는 함수.
bool IsBomb()
{
    memset(visit, false, sizeof(visit));

    bool isbomb = false;
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 6; ++j)
            if (board[i][j] != '.' && !visit[i][j])
            {
                path = 0;
                DFS(i, j, board[i][j]);
                if (path >= 4)
                {
                    isbomb = true;
                    Erase(i, j, board[i][j]);
                }
            }
    return isbomb;
}

// 연쇄로 인해 텅빈 곳을 바로 위 뿌요로 메꾸는 함수.
// 더이상 메꿀게 없을때까지 반복해야한다.
bool GetDown()
{
    bool ischange = false;
    for (int i = 11; i > 0; --i)
        for (int j = 0; j < 6; ++j)
            if (board[i - 1][j] != '.' && board[i][j] == '.')
            {
                ischange = true;
                swap(board[i - 1][j], board[i][j]);
            }
    return ischange;
}

void MakeAnswer()
{
    int answer = 0;
    while (true)
    {
        if (IsBomb())
            ++answer;
        else
            break;

        bool ischange;
        while (true)
        {
            ischange = GetDown();
            if (!ischange)
                break;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    for (int i = 0; i < 12; ++i)
    {
        cin >> str;
        for (int j = 0; j < 6; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}