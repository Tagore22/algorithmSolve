#include <iostream>
#include <cstring>

using namespace std;

//나름 추적해야할 변수가 많았던 문제.

//풀이
//시작점이 어딘지를 모르기에 모든 이동을 담을수 있을정도로 큰 배열을 생성하여 그 중앙에 시작점을 둔다. 이동할수 있는 곳은 무조건 도달할수 있기에 다른 칸으로 이동시
//true로 값을 변경하여 체크해둔다. 또한 이동시에 y축, x축의 최대 최소 위치를 알아둬야 나중에 그부분만 출력하기에 이것 또한 기록해둔다.

bool board[100][100];
int len, min_x, max_x, min_y, max_y;
string note;

void MakeGraph()
{
    memset(board, false, sizeof(board));
    int y = 50, x = 50, dir = 3;
    min_x = max_x = min_y = max_y = 50; //dir은 현재 바라보는 방향. 1번 북쪽부터 시계방향
    board[y][x] = true;
    for (int i = 0; i < note.size(); ++i)
    {
        if (note[i] == 'L')
        {
            dir = dir - 1 == 0 ? 4 : dir - 1;
        }
        else if (note[i] == 'R')
        {
            dir = dir + 1 == 5 ? 1 : dir + 1;
        }
        else
        {
            if (dir == 1)
                y -= 1;
            else if (dir == 2)
                x += 1;
            else if (dir == 3)
                y += 1;
            else
                x -= 1;
            board[y][x] = true;
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }
    }
}

void MakeAnswer()
{
    MakeGraph();
    for (int i = min_y; i <= max_y; ++i)
    {
        for (int j = min_x; j <= max_x; ++j)
            cout << (board[i][j] ? '.' : '#');
        cout << '\n';
    }
}

void Input()
{
    cin >> len >> note;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}