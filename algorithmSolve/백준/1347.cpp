#include <iostream>
#include <cstring>

using namespace std;

//���� �����ؾ��� ������ ���Ҵ� ����.

//Ǯ��
//�������� ������� �𸣱⿡ ��� �̵��� ������ ���������� ū �迭�� �����Ͽ� �� �߾ӿ� �������� �д�. �̵��Ҽ� �ִ� ���� ������ �����Ҽ� �ֱ⿡ �ٸ� ĭ���� �̵���
//true�� ���� �����Ͽ� üũ�صд�. ���� �̵��ÿ� y��, x���� �ִ� �ּ� ��ġ�� �˾Ƶ־� ���߿� �׺κи� ����ϱ⿡ �̰� ���� ����صд�.

bool board[100][100];
int len, min_x, max_x, min_y, max_y;
string note;

void MakeGraph()
{
    memset(board, false, sizeof(board));
    int y = 50, x = 50, dir = 3;
    min_x = max_x = min_y = max_y = 50; //dir�� ���� �ٶ󺸴� ����. 1�� ���ʺ��� �ð����
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